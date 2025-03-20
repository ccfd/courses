// 010-TestCase.cpp
//https://github.com/catchorg/Catch2/blob/master/examples/010-TestCase.cpp
//https://github.com/education/autograding-example-cpp

// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Chain.h"
#include <string>
#include <sstream>
#include <iostream>

// https://stackoverflow.com/questions/3803465/how-to-capture-stdout-stderr-with-googletest
// https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
// g++ -std=c++17 test_suite.cpp -o test_suite  && test_suite --success

TEST_CASE( "Testing ATM Dispenser: std out", "[single-file]" ) {
    std::ostringstream oss;
    std::streambuf *p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    {
        ATM atm(new FeeTaker(20, new Dispenser(100, new Dispenser(50, new Dispenser(20, new Dispenser(10))))));
        // process the requests

        SECTION("Processing 610$") {
            atm.WithdrawCash(610);
            std::cout.rdbuf(p_cout_streambuf); // restore
            // std::cout << oss.str(); // see what is inside
            REQUIRE(oss.str() == "Subtracting fee: 20$.\n"
                                 "To dispense: 5 x 100$ banknote.\n"
                                 "To dispense: 1 x 50$ banknote.\n"
                                 "To dispense: 2 x 20$ banknote.\n");
            //  oss.clear(); // this is not needed
        }

        SECTION("Processing 50$") {
            atm.WithdrawCash(50);
            std::cout.rdbuf(p_cout_streambuf); // restore
            REQUIRE(oss.str() == "Subtracting fee: 20$.\n"
                                 "To dispense: 1 x 20$ banknote.\n"
                                 "To dispense: 1 x 10$ banknote.\n");
        }

        SECTION("Processing 123$") {
            atm.WithdrawCash(123);
            std::cout.rdbuf(p_cout_streambuf); // restore
            REQUIRE(oss.str() == "Subtracting fee: 20$.\n"
                                 "To dispense: 1 x 100$ banknote.\n"
                                 "Can't dispense further... Remainder: 3$ < banknote face value: 10$.\n");
        }
    }

    SECTION("Free memory - hello from destructors") {
        std::cout.rdbuf(p_cout_streambuf); // restore
        REQUIRE(oss.str() == "~FeeTaker: 20$.\n"
                             "~Dispenser: 100$.\n"
                             "~Dispenser: 50$.\n"
                             "~Dispenser: 20$.\n"
                             "~Dispenser: 10$.\n");
    }
}