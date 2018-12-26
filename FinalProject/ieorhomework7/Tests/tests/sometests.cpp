#include "gtest/gtest.h"
#include "AppBase.h"
#include "BookBuilder.h"
#include "BookUpdate.h"
#include "MarketSimulator.h"
#include "MDReader.h"
#include "Order.h"
#include "OrderManager.h"
#include "TradingStrategy.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>

TEST(MDreader, getData) {
    MDReader reader("/Users/ruohanwu/Desktop/IBM.1min.TradesAndQuotes.20160128.csv", ",", 10);
    std::vector<BookUpdate> dataList = reader.getData();
//    for (int i = 0; i < dataList.size(); i++) {
//        std::cout << dataList[i].get_price() << " "
//        << dataList[i].get_quantity() << " " << dataList[i].get_time() << std::endl;
//    }
    EXPECT_EQ(dataList[0].get_price(), 118);
    EXPECT_EQ(dataList[0].get_quantity(), 100);
    EXPECT_EQ(dataList[0].get_is_buy(), true);
    EXPECT_EQ(dataList[0].get_time(), 1453953660);
    EXPECT_EQ(strcmp(dataList[0].get_symbol(), "IBM"), 0);
    EXPECT_EQ(dataList[1].get_price(), 124.5);
    EXPECT_EQ(dataList[1].get_quantity(), 100);
    EXPECT_EQ(dataList[1].get_is_buy(), false);
    EXPECT_EQ(dataList[1].get_time(), 1453953660);
    EXPECT_EQ(dataList[2].get_time(), 1453953720);
    EXPECT_EQ(dataList[2].get_price(), 120.37);
    EXPECT_EQ(dataList[2].get_quantity(), 100);
}

TEST(Signal, fakeData) {
    Signal sig1;
    sig1.insert_book_update(BookUpdate(0,10,10000,"GAIN",true,"EURUSD",0));
    sig1.insert_book_update(BookUpdate(0,12,10000,"GAIN",false,"EURUSD",0));
    sig1.insert_book_update(BookUpdate(0,14,10000,"GAIN",true,"EURUSD",280));
    sig1.insert_book_update(BookUpdate(0,15,10000,"GAIN",false,"EURUSD",280));
    sig1.insert_book_update(BookUpdate(0,14,10000,"GAIN",true,"EURUSD",290));
    sig1.insert_book_update(BookUpdate(0,15,10000,"GAIN",false,"EURUSD",290));
    EXPECT_EQ(round(sig1.get_5min_moving_average() * 100) / 100, 13.33);
    sig1.insert_book_update(BookUpdate(0,14,10000,"GAIN",true,"EURUSD",300));
    sig1.insert_book_update(BookUpdate(0,16,10000,"GAIN",false,"EURUSD",300));
    EXPECT_EQ(round(sig1.get_20min_moving_average() * 100) / 100, 13.75);
    EXPECT_EQ(round(sig1.getPrev5Avg() * 100) / 100,13.33);
    EXPECT_EQ(round(sig1.getPrev20Avg() * 100) / 100, 13.33);
    EXPECT_EQ(sig1.go_long(),false);
    EXPECT_EQ(sig1.go_short(),false);
    sig1.insert_book_update(BookUpdate(0,12,10000,"GAIN",true,"EURUSD",400));
    sig1.insert_book_update(BookUpdate(0,14,10000,"GAIN",false,"EURUSD",400));
    EXPECT_EQ(sig1.getPrev5Avg(),13.75);
    EXPECT_EQ(sig1.getPrev20Avg(), 13.75);
    EXPECT_EQ(round(sig1.get_5min_moving_average() * 100) / 100, 14.25);
    EXPECT_EQ(round(sig1.get_20min_moving_average() * 100) / 100, 13.6);
    EXPECT_EQ(sig1.go_long(),true);
    EXPECT_EQ(sig1.go_short(),false);
    sig1.insert_book_update(BookUpdate(0,20,10000,"GAIN",true,"EURUSD",600));
    sig1.insert_book_update(BookUpdate(0,24,10000,"GAIN",false,"EURUSD",600));
    EXPECT_EQ(sig1.getPrev5Avg(),14.25);
    EXPECT_EQ(sig1.getPrev20Avg(), 13.6);
    EXPECT_EQ(round(sig1.get_5min_moving_average() * 100) / 100, 16.67);
    EXPECT_EQ(round(sig1.get_20min_moving_average() * 100) / 100, 15);
    EXPECT_EQ(sig1.go_long(), false);
    EXPECT_EQ(sig1.go_short(),false);
}

TEST(Signal_Movingavg, realData) {
    MDReader reader("/Users/ruohanwu/Desktop/IBM.1min.TradesAndQuotes.20160128.csv", ",", 30);
    std::vector<BookUpdate> dataList = reader.getData();
    Signal sig1;
    sig1.insert_book_update(dataList[0]);
    sig1.insert_book_update(dataList[1]);
    EXPECT_EQ(round(sig1.get_5min_moving_average() * 100) / 100, 121.25);
    sig1.insert_book_update(dataList[2]);
    sig1.insert_book_update(dataList[3]);
    sig1.insert_book_update(dataList[4]);
    sig1.insert_book_update(dataList[5]);
    sig1.insert_book_update(dataList[6]);
    sig1.insert_book_update(dataList[7]);
    sig1.insert_book_update(dataList[8]);
    sig1.insert_book_update(dataList[9]);
    EXPECT_EQ(round(sig1.get_5min_moving_average() * 100) / 100, 121.90);
    EXPECT_EQ(round(sig1.get_20min_moving_average() * 100) / 100, 121.90);
    sig1.insert_book_update(dataList[10]);
    sig1.insert_book_update(dataList[11]);
    EXPECT_EQ(round(sig1.get_5min_moving_average() * 100) / 100, 121.93);
    for (int i = 12; i < 42; i++) {
        sig1.insert_book_update(dataList[i]);
    }
    EXPECT_EQ(round(sig1.get_5min_moving_average() * 100) / 100, 121.67);
    EXPECT_EQ(round(sig1.get_20min_moving_average() * 100) / 100, 121.77);
    sig1.insert_book_update(dataList[42]);
    sig1.insert_book_update(dataList[43]);
    EXPECT_EQ(round(sig1.get_5min_moving_average() * 10000) / 10000, 121.6625);
    EXPECT_EQ(round(sig1.get_20min_moving_average() * 10000) / 10000, 121.7874);
}

TEST(Signal_GoLongShort, realData) {
    MDReader reader("/Users/ruohanwu/Desktop/IBM.1min.TradesAndQuotes.20160128.csv", ",", 30);
    std::vector<BookUpdate> dataList = reader.getData();
    Signal sig1;
    sig1.insert_book_update(dataList[0]);
    sig1.insert_book_update(dataList[1]);
    EXPECT_EQ(round(sig1.get_5min_moving_average() * 100) / 100, 121.25);
    EXPECT_EQ(sig1.go_long(), false);
    EXPECT_EQ(sig1.go_short(), false);
    for (int i = 2; i < 12; i++) {
        sig1.insert_book_update(dataList[i]);
    }
    EXPECT_EQ(round(sig1.get_5min_moving_average() * 100) / 100, 121.93);
    EXPECT_EQ(round(sig1.get_20min_moving_average() * 100) / 100, 121.93);
    EXPECT_EQ(sig1.go_long(), false);
    EXPECT_EQ(sig1.go_short(), false);
    sig1.insert_book_update(dataList[12]);
    sig1.insert_book_update(dataList[13]);
    EXPECT_EQ(round(sig1.get_5min_moving_average() * 10000) / 10000, 122.0658);
    EXPECT_EQ(round(sig1.get_20min_moving_average() * 10000) / 10000, 121.9493);
    EXPECT_EQ(sig1.go_long(), true);
    EXPECT_EQ(sig1.go_short(), false);

}




TEST(epoch, timeConvert) {
    struct tm * t;
    long tstamp = 1453953660;
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
    EXPECT_EQ(tm, "20160128 04:01:00");
}
