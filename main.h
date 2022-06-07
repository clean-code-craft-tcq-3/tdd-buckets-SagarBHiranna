#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct main
{
    int rangeFirstNumber;
    int rangeLastNumber;
    int rangeNoOfSamples; 
}rangeDetails;

rangeDetails rangeDetailRecords[100];

int *sortArray(int *inputArray, int size);

int informRangeToUser(int *inputArray, int size);

int cmpFunc (const void * a, const void * b) ;

void updateRangeData(int index, int startRangeNumber, int endRangeNumber, int numberOfConsecutiveNumbers);

int isSamplesConsecutive(int currentNumber, int nextNumber);

int getRangeDetails(int *inputArray, int size);

#endif