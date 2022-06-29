#include "currentMeasurements.h"

typedef struct main
{
    int rangeFirstNumber;
    int rangeLastNumber;
    int rangeNoOfSamples; 
}rangeDetails;

rangeDetails rangeDetailRecords[100];

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
    // This functions does dual purpose insync with its name , informing user on console as well as returning range to user
    int ranges = getRangeDetails(inputArray,size);
    printf("\nRange,Readings\n");
    for(int noOfRange=0; noOfRange<ranges; noOfRange++)
    {
        printf("  %d-%d, %d\n", rangeDetailRecords[noOfRange].rangeFirstNumber, rangeDetailRecords[noOfRange].rangeLastNumber, rangeDetailRecords[noOfRange].rangeNoOfSamples);
    }
    return ranges;
}
