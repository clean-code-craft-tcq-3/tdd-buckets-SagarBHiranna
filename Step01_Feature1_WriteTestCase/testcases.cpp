#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"


/* FEATURE 1 : The return Value for {4,5} from getRangeDetails should be 1 .
   TDD_STEP1 : Write the Test Code(Unit Test) without having the implementation of a function being called .
   Actions : Write only test code (Unit Test).
   Result : FAILED .
   Reason : There is no function defined present     */
TEST_CASE("Get the range distribution details for consecutive numbers "){
    int sampleNumbersArray[] = {4,5};
    REQUIRE(getRangeDetails(sampleNumbersArray, 2) == 1);
}