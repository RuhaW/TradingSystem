//
// Created by sebastiend on 06/10/2018.
//

#include "TradingStrategy.h"
#include <iomanip>

bool Execution::insert_order(long timestamp_,
                  bool is_buy_,
                  double price_,
                  unsigned int quantity_,
                  const char * venue_,
                  const char * symbol_,
                  ordertype type_,
                  unsigned int id_)
{
    e.setTimeStamp(timestamp_);
    e.setSide(is_buy_);
    e.setPrice(price_);
    e.setQuantity(quantity_);
    e.setVenue(venue_);
    e.setType(type_);
    e.setSymbol(symbol_);
    e.setOrderID(id_);
};

bool TradingStrategy::process_book_update(BookUpdate &bu){
    if(!is_working)
        return false;
    if (signal.is_tradeable(bu)) {
        execution.insert_order(bu.get_time(),bu.get_is_buy(),
                               bu.get_price(),bu.get_quantity(),bu.get_venue(),bu.get_symbol(),ordertype::LIMIT,order_id++);
        execution.set_tradeable(true);
    }
    //std::cout << execution.get_order().getTimeStamp() << std::endl;
    return process_execution();
}


bool TradingStrategy::process_book_update() {
    if (!is_working)
        return false;
    if (bookbuilder_to_strategy.empty())
        return true;
    BookUpdate &bu1 = bookbuilder_to_strategy.front();
    bookbuilder_to_strategy.pop();
    BookUpdate &bu2 = bookbuilder_to_strategy.front();
    bookbuilder_to_strategy.pop();
    signal.insert_book_update(bu1);
    signal.insert_book_update(bu2);
//    signal.print();
//    std::cout << std::setprecision(7) << signal.getPrev5Avg() << " " << signal.getPrev20Avg() << " "
//    << signal.get_5min_moving_average() << " " << signal.get_20min_moving_average() << std::endl;
//    std::cout << signal.go_long() << " " << signal.go_short() << std::endl;

    if (signal.go_long()) {
        return process_book_update(bu1);
    } else if (signal.go_short()){
        return process_book_update(bu2);
    } else {
        return true;
    }
}


bool TradingStrategy::process_execution() {
    if(!is_working)
        return false;
    Order order;
    if (execution.is_tradeable()) {
        order.setType(execution.get_order().getOrderType());
        order.setVenue(execution.get_order().getVenue());
        order.setQuantity(execution.get_order().getQuantity());
        order.setPrice(execution.get_order().getPrice());
        order.setOrderID(execution.get_order().getID());
        order.setSymbol(execution.get_order().getSymbol());
        order.setSide(execution.get_order().isBuy());
        order.setTimeStamp(execution.get_order().getTimeStamp());
        if (execution.get_order().isBuy()) {
            pnl += execution.get_order().getPrice() * execution.get_order().getQuantity();
        } else {
            pnl += -execution.get_order().getPrice() * execution.get_order().getQuantity();
        }
        execution.set_tradeable(false);
        //std::cout << "strategy push an order" << std::endl;
        strategy_to_ordermanager.push(order);
    }
    return true;
};

bool TradingStrategy::process_market_response()
{
    if(ordermanager_to_strategy.empty())
        return true;
    ExecutionOrder &order = ordermanager_to_strategy.front();
    ordermanager_to_strategy.pop();

    if (order.getState()==orderstate::REJECTED)
        number_of_rejections++;

    if (order.getState()!=orderstate::FILLED)
        return true;
    number_of_fills++;

    double position = order.getQuantity()*order.getPrice();
    std::unordered_map<std::string,  double> ::const_iterator got = positions.find (order.getSymbol());
    if ( got == positions.end() )
        positions[order.getSymbol()]=(order.isBuy())?position:-position;
    else{
        //std::cout << order.getQuantity() << " " << order.getPrice() << " " <<  position << " " << positions[order.getSymbol()] << std::endl;
        positions[order.getSymbol()]+=(order.isBuy())?position:-position;
    }

    return true;
}

int TradingStrategy::get_position(std::string symbol)
{
    std::unordered_map<std::string,  double> ::const_iterator got = positions.find (symbol);
    if ( got == positions.end() )
        return 0;
    else
        return positions[symbol];
}

unsigned int TradingStrategy::get_number_of_rejections() {
    return number_of_rejections;
}

unsigned int TradingStrategy::get_number_of_fills() {
    return number_of_fills;
}

unsigned int TradingStrategy::get_pnl() {
    return pnl;
}

void TradingStrategy::reset_position(){
    positions.clear();
}