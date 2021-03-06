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
	currentValue = (float)(maxCurrentValue * ((float)A2DValues/(float)maxValue));
	analogConvertedvalue = round(currentValue);
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
		
	}
	return 1;
	
}