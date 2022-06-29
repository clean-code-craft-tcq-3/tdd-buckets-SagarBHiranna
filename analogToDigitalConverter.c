#include "analogToDigitalConverter.h"

int getMaxSensorDigitalValue(int A2DResolution)
{
	return (pow(2,A2DResolution) - 2);
}

int digitalToAnalogCurrentValue(int A2DValues, int A2DResolution, int maxCurrentValue)
{	
	float currentValue;
	int analogConvertedvalue;
	int maxValue = getMaxSensorDigitalValue(A2DResolution);
	printf("%d\n", A2DValues);
	printf("%d\n", maxValue);
	float dividedValue = (float)A2DValues/(float)maxValue;
	printf("%f\n", dividedValue);
	currentValue = (maxCurrentValue * (A2DValues/maxValue))/maxValue;
	printf("%f\n", currentValue);
	analogConvertedvalue = round(currentValue);
	printf("%d\n", analogConvertedvalue);
	if(analogConvertedvalue < 0)
		analogConvertedvalue = abs(analogConvertedvalue);
    return analogConvertedvalue;	
}

int chargingCurrentValue(int A2DValues[], int numberOfSamples, int A2DResolution, int maxCurrentValue, int* analogValues)
{
	int invalidValue;
	invalidValue = (pow(2,A2DResolution) - 1);
    //int digitalValues[] = {};
	for (int i=0; i< numberOfSamples; i++)
	{
		if(A2DValues[i] != invalidValue)
		{
			analogValues[i] = digitalToAnalogCurrentValue(A2DValues[i], A2DResolution, maxCurrentValue);
		}
		else{
			return 0;
		}
		return 1;
	}
	
}