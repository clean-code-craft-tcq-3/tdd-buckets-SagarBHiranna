#ifndef CURRENTMEASUREMENTS_H
#define CURRENTMEASUREMENTS_H

#include<stdio.h>
typedef struct main
{
    int rangeFirstNumber;
    int rangeLastNumber;
    int rangeNoOfSamples; 
}rangeDetails;

rangeDetails rangeDetailRecords[100];

void updateRangeData(int index, int startRangeNumber, int endRangeNumber, int numberOfConsecutiveNumbers);

int isSamplesConsecutive(int currentNumber, int nextNumber);

int getRangeDetails(int *inputArray, int size);

#endif