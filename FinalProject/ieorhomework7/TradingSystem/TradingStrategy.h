//
// Created by sebastiend on 06/10/2018.
//

#ifndef IEOR_HOMEWORK5_TRADINGSTRATEGY_H
#define IEOR_HOMEWORK5_TRADINGSTRATEGY_H
#include "AppBase.h"
#include "BookUpdate.h"
#include "Order.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <math.h>
#include <memory>


class Signal{
private:
    std::deque<BookUpdate> priceStore;
    unsigned int latestTime;
//    double prev5Avg;
//    double prev20Avg;
public:
    void insert_book_update(BookUpdate bu){
//        if (priceStore.size() % 2 == 0) {
//            prev5Avg = get_5min_moving_average();
//            prev20Avg = get_20min_moving_average();
//        }
        priceStore.push_front(bu);
        latestTime = bu.get_time();
        //std::cout << priceStore.size() << std::endl;
        if (priceStore.back().get_time() + 1500 < latestTime) {
            priceStore.pop_back();
        }
        std::ofstream file;
        file.open("averagePrice.csv", std::ios_base::app);
        if (priceStore.size() % 2 == 0) {
            std::string temp = std::to_string(bu.get_time()) + "," + std::to_string(get_5min_moving_average())
                               + "," + std::to_string(get_20min_moving_average()) + "," + "\n";
            file << temp;
        }
    };
    double getPrev5Avg() {
        double result = 0;
        int count = 0;
        for (std::deque<BookUpdate>::iterator it = priceStore.begin() + 2; it != priceStore.end(); ++it){
            if (it->get_time() + 300 >= (priceStore.begin() + 2)->get_time()) {
                //std::cout << priceStore[it].get_time() <<  "  " << priceStore[it].get_price() << std::endl;
                result += it->get_price();
                count++;
            } else {
                break;
            }
        }
        return (result/count);
    }
    double getPrev20Avg() {
        double result = 0;
        int count = 0;
        for (std::deque<BookUpdate>::iterator it = priceStore.begin() + 2; it != priceStore.end(); ++it){
            if (it->get_time() + 1200 >= (priceStore.begin() + 2)->get_time()) {
                //std::cout << priceStore[it].get_time() <<  "  " << priceStore[it].get_price() << std::endl;
                result += it->get_price();
                count++;
            } else {
                break;
            }
        }
        return (result/count);
    }
    double get_5min_moving_average(){
        double result = 0;
        int count = 0;
        for (std::deque<BookUpdate>::iterator it = priceStore.begin(); it != priceStore.end(); ++it){
            if (it->get_time() + 300 >= latestTime) {
                //std::cout << priceStore[it].get_time() <<  "  " << priceStore[it].get_price() << std::endl;
                result += it->get_price();
                count++;
            } else {
                break;
            }
        }
        return (result/count);
    }
    double get_20min_moving_average(){
        double result = 0;
        int count = 0;
        for (std::deque<BookUpdate>::iterator it = priceStore.begin(); it != priceStore.end(); ++it){
            if (it->get_time() + 1200 >= latestTime) {
                result += it->get_price();
                count++;
            } else {
                break;
            }
        }
        return (result/count);
    }
    bool go_long(){
        return (getPrev5Avg() <= getPrev20Avg() && get_5min_moving_average() > get_20min_moving_average());
    }
    bool go_short(){
        return (getPrev5Avg() >= getPrev20Avg() && get_5min_moving_average() < get_20min_moving_average());
    }
    bool is_tradeable(BookUpdate &bu){return true;}
    void print() {
        //std::cout << priceStore.size() << std::endl;
        for (std::deque<BookUpdate>::iterator it = priceStore.begin(); it != priceStore.end(); ++it) {
            std::cout << it->get_time()  << " " << it->get_price()<< std::endl;
        }
    }
};

class Execution{
private:
    Order e;
    bool tradeable;
public:

    Execution():tradeable(false){}
    bool insert_order(long timestamp_,
                      bool is_buy_,
                      double price_,
                      unsigned int quantity_,
                      const char * venue_,
                      const char * symbol_,
                      ordertype type_,
                      unsigned int id_);
    bool is_tradeable() {return tradeable;}
    void set_tradeable(bool is_tradable){tradeable=is_tradable;};
    Order & get_order() {return e;}
};

class TradingStrategy : public AppBase {
private:
    Signal signal;
    Execution execution;
    int order_id;
    std::unordered_map<std::string,double> positions;
    unsigned int number_of_rejections;
    unsigned int number_of_fills;
    unsigned int pnl;

public:
    TradingStrategy(
            std::queue<Order> &strategy_to_ordermanager_,
            std::queue<ExecutionOrder> &ordermanager_to_strategy_,
            std::queue<Order> &ordermanager_to_simulator_,
            std::queue<ExecutionOrder> &simulator_to_ordermanager_,
            std::queue<BookUpdate> &bookbuilder_to_strategy_
    ):
    AppBase(strategy_to_ordermanager_,
              ordermanager_to_strategy_,
              ordermanager_to_simulator_,
              simulator_to_ordermanager_,
              bookbuilder_to_strategy_),
              signal(),
              execution(),
              order_id(1),
              number_of_rejections(0),
              number_of_fills(0),
              pnl(0){}
    virtual void start() {is_working=true;}
    virtual void stop() {
        positions.clear();
        is_working=false;
    }


    bool process_book_update(BookUpdate &bu);
    bool process_book_update();
    bool process_execution();
    bool process_market_response();
    std::shared_ptr<Execution> get_execution() {
        std::shared_ptr<Execution> ptr (&execution);
        return ptr;
    }
    int get_position(std::string symbol);
    unsigned int get_number_of_rejections();
    unsigned int get_number_of_fills();
    void reset_position();
    unsigned int get_pnl();
    void adjustPnl() {
        if (execution.get_order().isBuy()) {
            pnl -= execution.get_order().getQuantity() * execution.get_order().getPrice();
        } else {
            pnl += execution.get_order().getQuantity() * execution.get_order().getPrice();
        }
    }

};


#endif //IEOR_HOMEWORK5_TRADINGSTRATEGY_H
