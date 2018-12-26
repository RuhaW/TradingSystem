cmake_minimum_required(VERSION 3.12)
project(ieor_homework7)


set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE(Boost 1.66 REQUIRED date_time program_options thread filesystem system unit_test_framework)
IF(${Boost_FOUND})
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ENDIF()

include_directories(TradingSystem)

add_subdirectory(TradingSystem)
add_subdirectory(Tests)


add_executable(ieorhomework7 main.cpp my_unit_test.cpp my_unit_test.h TradingSystem/OrderManager.cpp TradingSystem/OrderManager.h
        TradingSystem/MarketSimulator.cpp TradingSystem/MarketSimulator.h TradingSystem/TradingStrategy.cpp TradingSystem/TradingStrategy.h
        TradingSystem/Order.cpp TradingSystem/Order.h TradingSystem/BookUpdate.cpp TradingSystem/BookUpdate.h TradingSystem/AppBase.cpp TradingSystem/AppBase.h
        TradingSystem/MDReader.cpp TradingSystem/MDReader.h TradingSystem/BookBuilder.cpp TradingSystem/BookBuilder.h)

target_link_libraries(ieorhomework7 AppBase BookBuilder BookUpdate MarketSimulator
        MDReader Order OrderManager TradingStrategy ${Boost_LIBRARIES})