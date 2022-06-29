#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "currentMeasurements.h"
#include "analogToDigitalConverter.h"


TEST_CASE("Get the range distribution details for consecutive numbers scenario 1") {
    int sampleNumbersArray[] = {4,5};
    REQUIRE(getRangeDetails(sampleNumbersArray, 2) == 1);
}


TEST_CASE("Get the range distribution details for consecutive numbers scenario 2"){
    int sampleNumbersArray[] = {1,21,2};
    REQUIRE(getRangeDetails(sampleNumbersArray, 3) == 2);
}

TEST_CASE("Check the display function "){
    int sampleNumbersArray[] = {1,21,2};
    REQUIRE(informRangeToUser(sampleNumbersArray, 3) == 2);
}


TEST_CASE("Get the range distribution details for consecutive numbers scenario 3"){
    int sampleNumbersArray[] = {1,21,2,1,5,4,3,1,2,3,20};
    int sampleNumbersArray1[] = {1,-1,2,-2,3,-3};
    int sampleNumbersArray2[] = {1,-1,2,-2,3,-3,0};
    REQUIRE(getRangeDetails(sampleNumbersArray, 11) == 2);
    REQUIRE(getRangeDetails(sampleNumbersArray1, 6) == 2);
    REQUIRE(getRangeDetails(sampleNumbersArray2, 7) == 1);
}


TEST_CASE("Check the display function Usecase 2"){
    int sampleNumbersArray4[] = {1,21,2};
    int sampleNumbersArray[] = {1,21,2,1,5,4,3,1,2,3,20};
    int sampleNumbersArray1[] = {1,-1,2,-2,3,-3};
    int sampleNumbersArray2[] = {1,-1,2,-2,3,-3,0};
    REQUIRE(informRangeToUser(sampleNumbersArray4, 3) == 2);
    REQUIRE(informRangeToUser(sampleNumbersArray, 11) == 2);
    REQUIRE(informRangeToUser(sampleNumbersArray1, 6) == 2);
    REQUIRE(informRangeToUser(sampleNumbersArray2, 7) == 1);
}


TEST_CASE("TestCaseto verify the functionality when the ADC Values passed are within range") {
	
	int ADCValues[] = {64, 512, 1140, 1220, 1560, 2048,4094};
	int numberOfSamples = sizeof(ADCValues) / sizeof(ADCValues[0]);
	int expectedCurrentSenseValues[] = {0, 1, 2, 3, 4, 5, 10};
	int ADC_Resolution = 12;
	int maxCurrentValue = 10;
	int digitalvalues[] = {};
	int expectedStartIndex = 0, expectedEndIndex = 5 , expectedNumOfReadingsInRange = 6;
	REQUIRE(chargingCurrentValue(ADCValues, numberOfSamples, ADC_Resolution, maxCurrentValue, digitalvalues)==1);
	REQUIRE(informRangeToUser(digitalvalues, numberOfSamples) == 2);
}

TEST_CASE("TestCaseto verify the functionality when the ADC Values passed are in error zone") {
	
	int ADCValues[] = {4095};
	int numberOfSamples = sizeof(ADCValues) / sizeof(ADCValues[0]);
	int expectedCurrentSenseValues[] = {0};
	int ADC_Resolution = 12;
	int maxCurrentValue = 10;
	int digitalvalues[] = {};
	int expectedStartIndex = 0, expectedEndIndex = 5 , expectedNumOfReadingsInRange = 6;
	REQUIRE(chargingCurrentValue(ADCValues, numberOfSamples, ADC_Resolution, maxCurrentValue, digitalvalues)==0);
}