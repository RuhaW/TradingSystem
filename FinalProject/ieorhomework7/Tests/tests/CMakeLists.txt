include_directories(${gtest_SOURCE_DIR}/include $gtest_SOURCE_DIR)

add_executable(RunTests SomeTests.cpp)
target_link_libraries(RunTests gtest gtest_main AppBase BookBuilder BookUpdate
        MarketSimulator MDReader Order OrderManager TradingStrategy ${Boost_LIBRARIES})
