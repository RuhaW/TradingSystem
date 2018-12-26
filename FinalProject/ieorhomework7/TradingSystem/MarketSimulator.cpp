//
// Created by sebastiend on 06/10/2018.
//

#include "MarketSimulator.h"
#include <fstream>
#include <time.h>

MarketSimulator::MarketSimulator(
        std::queue<Order> &strategy_to_ordermanager_,
        std::queue<ExecutionOrder> &ordermanager_to_strategy_,
        std::queue<Order> &ordermanager_to_simulator_,
        std::queue<ExecutionOrder> &simulator_to_ordermanager_,
        std::queue<BookUpdate> &bookbuilder_to_strategy_
        ):AppBase(strategy_to_ordermanager_,
                ordermanager_to_strategy_,
                ordermanager_to_simulator_,
                 simulator_to_ordermanager_,
                 bookbuilder_to_strategy_),
                 execution_id(0),
                 pnl(0)
     {
        list_symbols = {"IBM"};
     }


bool MarketSimulator::handle_order(){
    //std::cout << "----------------" << ordermanager_to_simulator.size() << std::endl;
    if(!is_working)
        return false;
    if(ordermanager_to_simulator.empty())
        return true;
    const Order &o = ordermanager_to_simulator.front();
    ordermanager_to_simulator.pop();
    //std::cout << ordermanager_to_simulator.size() << std::endl;

    const bool is_tradeable = list_symbols.find(o.getSymbol()) != list_symbols.end();

    ExecutionOrder new_execution(o);
    //std::cout <<  o.getTimeStamp() << std::endl;
    if(is_tradeable){
        new_execution.setState(o.getQuantity()>10?orderstate::ACKNOWLEDGED:orderstate::REJECTED);
        new_execution.setExecutionID(execution_id++);
        simulator_to_ordermanager.push(new_execution);
        if (rand() % 2 == 1) {
            new_execution.setState(orderstate::FILLED);
            std::ofstream myfile;
            myfile.open("output.csv", std::ios_base::app);
            std::string temp =
                    Epoch2HumanTime(new_execution.getTimeStamp()) + "," + std::to_string(new_execution.getTimeStamp())
                    + "," + std::to_string(new_execution.getPrice()) + "," + std::to_string(new_execution.isBuy())
                    + "," + "FILLED" + "\n";
            myfile << temp;
            std::cout << "simulator push a FILL|" <<
                      Epoch2HumanTime(new_execution.getTimeStamp()) << "|" <<
                      new_execution.getPrice() << "|" <<
                      new_execution.isBuy() << "|" <<
                      new_execution.getQuantity() << "|" <<
                      std::endl;
            if (new_execution.isBuy()) {
                pnl += new_execution.getPrice() * new_execution.getQuantity();
            } else {
                pnl += -new_execution.getPrice() * new_execution.getQuantity();
            }
        } else {
            new_execution.setState(orderstate::REJECTED);
            std::ofstream myfile;
            myfile.open("output.csv", std::ios_base::app);
            std::string temp =
                    Epoch2HumanTime(new_execution.getTimeStamp()) + "," + std::to_string(new_execution.getTimeStamp())
                    + "," + std::to_string(new_execution.getPrice()) + "," + std::to_string(new_execution.isBuy())
                    + "," + "REJECTED" + "\n";
            myfile << temp;
            std::cout << "simulator push a REJT|" <<
                      Epoch2HumanTime(new_execution.getTimeStamp()) << "|" <<
                      new_execution.getPrice() << "|" <<
                      new_execution.isBuy() << "|" <<
                      new_execution.getQuantity() << "|" <<
                      std::endl;
        }
        simulator_to_ordermanager.push(new_execution);
    }
    else {
        // std::cout << "simulator push a reject" << std::endl;
        new_execution.setState(orderstate::REJECTED);
        new_execution.setExecutionID(execution_id++);
        simulator_to_ordermanager.push(new_execution);
    }

    return true;
}


unsigned int MarketSimulator::get_pnl() {
    return pnl;
};