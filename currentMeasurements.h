#ifndef CURRENTMEASUREMENTS_H
#define CURRENTMEASUREMENTS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



int *sortArray(int *inputArray, int size);

int informRangeToUser(int *inputArray, int size);

int cmpFunc (const void * a, const void * b) ;

void updateRangeData(int index, int startRangeNumber, int endRangeNumber, int numberOfConsecutiveNumbers);

int isSamplesConsecutive(int currentNumber, int nextNumber);

int getRangeDetails(int *inputArray, int size);

#endif