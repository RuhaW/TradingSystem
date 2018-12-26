#include <iostream>
#include <fstream>
//#include "my_unit_test.h"
#include "TradingSystem/Order.h"
#include "TradingSystem/BookUpdate.h"
#include "TradingSystem/MarketSimulator.h"
#include "TradingSystem/OrderManager.h"
#include "TradingSystem/TradingStrategy.h"
#include "TradingSystem/MDReader.h"
#include "TradingSystem/BookUpdate.h"
#include "TradingSystem/BookBuilder.h"

void reset_communication(
        std::queue<Order> &strategy_to_ordermanager,
        std::queue<ExecutionOrder> &ordermanager_to_strategy,
        std::queue<Order> &ordermanager_to_simulator,
        std::queue<ExecutionOrder> &simulator_to_ordermanager
        )
{
    while (!strategy_to_ordermanager.empty()) strategy_to_ordermanager.pop();
    while (!ordermanager_to_strategy.empty()) ordermanager_to_strategy.pop();
    while (!ordermanager_to_simulator.empty()) ordermanager_to_simulator.pop();
    while (!simulator_to_ordermanager.empty()) simulator_to_ordermanager.pop();
}

int main() {
    /* Create an order o1 on the stack with the following parameter
     *
     * (100,true,1,10,1000,"JPM","APPL",ordertype::LIMIT);
     *
     * */

    std::queue<Order> strategy_to_ordermanager;
    std::queue<ExecutionOrder> ordermanager_to_strategy;
    std::queue<Order> ordermanager_to_simulator;
    std::queue<ExecutionOrder> simulator_to_ordermanager;
    std::queue<BookUpdate> bookbuilder_to_strategy;

    MDReader reader("/Users/ruohanwu/Desktop/IBM.1min.TradesAndQuotes.20160128.csv",",",0);

    // Get the data from CSV File
    std::vector<BookUpdate> dataList = reader.getData();
//    std::cout << dataList.size() << std::endl;


    TradingStrategy ts1(strategy_to_ordermanager,
                        ordermanager_to_strategy,
                        ordermanager_to_simulator,
                        simulator_to_ordermanager,
                        bookbuilder_to_strategy);

    MarketSimulator simulator(strategy_to_ordermanager,
                              ordermanager_to_strategy,
                              ordermanager_to_simulator,
                              simulator_to_ordermanager,
                              bookbuilder_to_strategy);

    OrderManager order_manager(strategy_to_ordermanager,
                               ordermanager_to_strategy,
                               ordermanager_to_simulator,
                               simulator_to_ordermanager,
                               bookbuilder_to_strategy);

    BookBuilder book_builder(strategy_to_ordermanager,
                                ordermanager_to_strategy,
                                ordermanager_to_simulator,
                                simulator_to_ordermanager,
                                bookbuilder_to_strategy);

    /* The book builder fills the queue of BookUpdate
    * for simulation purpose
    */

    srand(41);
    book_builder.start();
    simulator.start();
    order_manager.start();
    ts1.start();

    while(!bookbuilder_to_strategy.empty()) {
//    int i = 0;
//    while (i < 5000) {
//        std::cout << strategy_to_ordermanager.size() << " "
//                  << ordermanager_to_strategy.size() << " "
//                  << ordermanager_to_simulator.size() << " "
//                  << simulator_to_ordermanager.size() << " "
//                  << bookbuilder_to_strategy.size() << std::endl;
//    }
        ts1.process_book_update();
        if (!order_manager.handle_order()) {
            ts1.get_execution()->set_tradeable(false);
            ts1.adjustPnl();
        }
//        order_manager.handle_order();
        simulator.handle_order();
        order_manager.handle_execution_order();
        ts1.process_execution();
        order_manager.handle_execution_order();
        ts1.process_execution();
//        i++;
    }

//    std::cout << ts1.get_pnl() << std::endl;
    std::cout << simulator.get_pnl() << std::endl;






    return 0;
}