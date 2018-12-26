//
// Created by sebastiend on 06/10/2018.
//

#ifndef IEOR_HOMEWORK5_MARKETSIMULATOR_H
#define IEOR_HOMEWORK5_MARKETSIMULATOR_H
#include "AppBase.h"
#include "Order.h"
#include <set>
#include <queue>
#include <string>
#include <iostream>
#include <time.h>

class MarketSimulator : public AppBase {
public:
    unsigned execution_id;
    std::set<std::string> list_symbols;
    unsigned int pnl;
    MarketSimulator(
             std::queue<Order> &strategy_to_ordermanager_,
             std::queue<ExecutionOrder> &ordermanager_to_strategy_,
             std::queue<Order> &ordermanager_to_simulator_,
             std::queue<ExecutionOrder> &simulator_to_ordermanager_,
             std::queue<BookUpdate> &bookbuilder_to_strategy_
    );
    bool handle_order();

    virtual void start() {is_working=true;}
    virtual void stop() {is_working=false;}
    unsigned int get_pnl();
    std::string Epoch2HumanTime(long tstamp) {
        struct tm * t;
        t = std::gmtime (&tstamp);
        std::string tm = std::to_string(t->tm_year + 1900);
        long mon = t->tm_mon + 1;
        if (mon< 10) {tm += "0";}
        tm += std::to_string(mon);
        if (t->tm_mday < 10) {tm += "0";}
        tm += std::to_string(t->tm_mday) + " ";
        if (t->tm_hour < 10) {
            tm += "0";
        }
        tm += std::to_string(t->tm_hour) + ":";
        if (t->tm_min < 10) {
            tm += "0";
        }
        tm += std::to_string(t->tm_min) + ":";
        if (t->tm_sec < 10) {
            tm += "0";
        }
        tm += std::to_string(t->tm_sec);
        return tm;
    }
};


#endif //IEOR_HOMEWORK5_MARKETSIMULATOR_H
