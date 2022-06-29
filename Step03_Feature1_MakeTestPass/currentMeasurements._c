#include "currentMeasurements.h"

int getRangeDetails(int *inputArray, int size)
{
    int numberOfConsecutiveNumbers=1, numberOfRanges=0, startRangeNumber=inputArray[0], endRangeNumber = inputArray[0];
    for (int arrayIndex=0; arrayIndex<size; arrayIndex++){
        if (inputArray[arrayIndex+1]-inputArray[arrayIndex]==0||inputArray[arrayIndex+1]-inputArray[arrayIndex]==1){
            numberOfConsecutiveNumbers++;
            endRangeNumber = inputArray[arrayIndex+1];
        }
        else {
            rangeDetailRecords[numberOfRanges].rangeFirstNumber = startRangeNumber;
            rangeDetailRecords[numberOfRanges].rangeLastNumber = endRangeNumber;
            rangeDetailRecords[numberOfRanges].rangeNoOfSamples = numberOfConsecutiveNumbers;
            numberOfRanges++;
            numberOfConsecutiveNumbers = 1;
            startRangeNumber = inputArray[arrayIndex+1];
            endRangeNumber = startRangeNumber;     
        }
    }
    rangeDetailRecords[numberOfRanges].rangeFirstNumber = startRangeNumber;
    rangeDetailRecords[numberOfRanges].rangeLastNumber = endRangeNumber;
    rangeDetailRecords[numberOfRanges].rangeNoOfSamples = numberOfConsecutiveNumbers;
    return numberOfRanges;
}
