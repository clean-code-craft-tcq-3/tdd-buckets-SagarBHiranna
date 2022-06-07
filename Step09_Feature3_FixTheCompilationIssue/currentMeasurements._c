#include "currentMeasurements.h"

int cmpFunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int *sortArray(int *inputArray, int size)
{
    qsort(inputArray, size, sizeof(int), cmpFunc);
    return inputArray;
}

int isSamplesConsecutive(int currentNumber, int nextNumber)
{
    int sampleDifference = nextNumber - currentNumber ;
    if (sampleDifference == 0 || sampleDifference == 1)
        return 1;
    return 0 ;
}

void updateRangeData(int index, int startRangeNumber, int endRangeNumber, int numberOfConsecutiveNumbers)
{
    rangeDetailRecords[index].rangeFirstNumber = startRangeNumber;
    rangeDetailRecords[index].rangeLastNumber = endRangeNumber;
    rangeDetailRecords[index].rangeNoOfSamples = numberOfConsecutiveNumbers;
}

int getRangeDetails(int *inputArray, int size)
{
    inputArray = sortArray(inputArray, size);
    int numberOfConsecutiveNumbers=1, numberOfRanges=0, startRangeNumber=inputArray[0], endRangeNumber = inputArray[0];
    for (int arrayIndex=0; arrayIndex<size; arrayIndex++){
        if (isSamplesConsecutive(inputArray[arrayIndex], inputArray[arrayIndex+1])){
            numberOfConsecutiveNumbers++;
            endRangeNumber = inputArray[arrayIndex+1];
        }
        else {
            updateRangeData(numberOfRanges, startRangeNumber, endRangeNumber, numberOfConsecutiveNumbers);
            numberOfRanges++;
            numberOfConsecutiveNumbers = 1;
            startRangeNumber = inputArray[arrayIndex+1];
            endRangeNumber = startRangeNumber;     
        }
    }
    updateRangeData(numberOfRanges, startRangeNumber, endRangeNumber, numberOfConsecutiveNumbers);
    return numberOfRanges;
}

int informRangeToUser(int *inputArray, int size)
{
    return 0;
}
