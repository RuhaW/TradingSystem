project(TradingSystem)

add_definitions(-std=c++11)

set(HEADER_FILES_A AppBase.h)
set(SOURCE_FILES_A AppBase.cpp)
add_library(AppBase STATIC ${SOURCE_FILES_A} ${HEADER_FILES_A})

set(HEADER_FILES_B BookBuilder.h)
set(SOURCE_FILES_B BookBuilder.cpp)
add_library(BookBuilder STATIC  ${SOURCE_FILES_B} ${MY_HEADER_FILES_B})

set(HEADER_FILES_B2 BookUpdate.h)
set(SOURCE_FILES_B2 BookUpdate.cpp)
add_library(BookUpdate STATIC  ${SOURCE_FILES_B2} ${MY_HEADER_FILES_B2})

set(HEADER_FILES_M MarketSimulator.h)
set(SOURCE_FILES_M MarketSimulator.cpp)
add_library(MarketSimulator STATIC  ${SOURCE_FILES_M} ${MY_HEADER_FILES_M})

set(HEADER_FILES_MD MDReader.h)
set(SOURCE_FILES_MD MDReader.cpp)
add_library(MDReader STATIC  ${SOURCE_FILES_MD} ${MY_HEADER_FILES_MD})

set(HEADER_FILES_O Order.h)
set(SOURCE_FILES_O Order.cpp)
add_library(Order STATIC  ${SOURCE_FILES_O} ${MY_HEADER_FILES_O})

set(HEADER_FILES_OM OrderManager.h)
set(SOURCE_FILES_OM OrderManager.cpp)
add_library(OrderManager STATIC  ${SOURCE_FILES_OM} ${MY_HEADER_FILES_OM})

set(HEADER_FILES_T TradingStrategy.h)
set(SOURCE_FILES_T TradingStrategy.cpp)
add_library(TradingStrategy STATIC  ${SOURCE_FILES_T} ${MY_HEADER_FILES_T})
