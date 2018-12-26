//
// Created by sebastiend on 06/10/2018.
//

#include "OrderManager.h"


bool OrderManager::handle_execution_order(){
    if(!is_working)
        return false;
    if (simulator_to_ordermanager.empty())
        return true;

    const ExecutionOrder &e = simulator_to_ordermanager.front();
    simulator_to_ordermanager.pop();

    std::unordered_map<unsigned int, ExecutionOrder> ::iterator got = list_orders.find (e.getID());


    if ( got == list_orders.end() )
    {
        //std::cout << "not found";
        return false;
    }
    else
    {
        //std::cout << e.getState() << std::endl;
        got->second.setState(e.getState());
        ordermanager_to_strategy.push(e);
    }

    if (e.getState()==orderstate::FILLED){
        double position = e.getQuantity()*e.getPrice();
        std::unordered_map<std::string,  double> ::const_iterator got = positions.find (order.getSymbol());
        if ( got == positions.end() )
            positions[order.getSymbol()]=(order.isBuy())?position:-position;
        else{
            //std::cout << order.getQuantity() << " " << order.getPrice() << " " << positions[order.getSymbol()] << std::endl;
            positions[order.getSymbol()]+=(order.isBuy())?position:-position;
        }
    }



    if (e.getState()==orderstate::FILLED
        or e.getState()==orderstate::REJECTED
        or e.getState()==orderstate::CANCELLED)
    {
        list_orders.erase(got);
    }

    return true;
};


unsigned int OrderManager::get_number_of_open_orders()
{
    return list_orders.size();
}


unsigned int OrderManager::get_number_of_non_acknowledged_orders()
{
    unsigned int number_of_unack_orders=0;
    for (std::pair<unsigned int, ExecutionOrder> order : list_orders)
    {
        if (order.second.getState()==orderstate::OPEN)
            number_of_unack_orders++;
    }

    return number_of_unack_orders;
}

double OrderManager::get_position(std::string symbol)
{
    std::unordered_map<std::string, double> ::const_iterator got = positions.find (symbol);
    if ( got == positions.end() )
        return 0;
    else
        return positions[symbol];
}

bool OrderManager::handle_order(){
    //std::cout << "----------------" << strategy_to_ordermanager.size() << std::endl;
    if(!is_working)
        return false;
    if (strategy_to_ordermanager.empty())
        return true;
    const Order &e = strategy_to_ordermanager.front();
    strategy_to_ordermanager.pop();

    order_id++;
    order=e;
    //std::cout << e.getTimeStamp() << std::endl;
    //std::cout << "TRY ORDER..." << list_orders.size() << std::endl;

    std::unordered_map<std::string, double> ::const_iterator got = positions.find (order.getSymbol());
    if ( got == positions.end() )
        positions[e.getSymbol()]=0;
    double position=(e.isBuy())?e.getPrice()*e.getQuantity():-e.getPrice()*e.getQuantity();
    //std::cout << list_orders.size() << " " << std::abs(positions[e.getSymbol()]+position) << std::endl;
    if(list_orders.size()>10 or std::abs(positions[e.getSymbol()]+position)>10000000)
    {
        //std::cout << "REJECTED ORDER" << std::endl;
        execution_order=e;
        execution_order.setOrderID(order_id);
        execution_order.setState(orderstate::REJECTED);
        ordermanager_to_strategy.push(execution_order);
        return false;
    }
    else {
        order.setOrderID(order_id);
        list_orders[order_id] = order;
        list_orders[order_id].setState(orderstate::OPEN);
        //std::cout << "OMS push an order" << std::endl;
        ordermanager_to_simulator.push(order);
    }
    return true;
};
