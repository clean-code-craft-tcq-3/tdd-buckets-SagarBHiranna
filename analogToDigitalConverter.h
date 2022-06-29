#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getMaxSensorDigitalValue(int ADC_Resolution);
int digitalToAnalogCurrentValue(int ADCValues, int A2DResolution, int maxCurrentValue);
int chargingCurrentValue(int ADCValues[], int numberOfSamples, int ADC_Resolution, int maxCurrentValue, int* analogConvertedvalues);