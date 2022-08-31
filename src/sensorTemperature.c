#include "sensorTemperature.h"

/**
 * @brief 
 * name: readTemperatureADC0
 * params: void
 * @return float 
 *         temperature value between 0-150.
 */
float readTemperatureADC0(void)
{
    float temperature = 0;
    int adcResult = 0;
    //Start Conversion 
    LPC_ADC->ADCR |= START_CNV;
    //Wait untill conversion is finished
    while((LPC_ADC->ADDR0 & ADC_DONE) == 0);
    //12 bit Mask to extract result
	adcResult = (LPC_ADC->ADDR0>>4) & 0xFFF;
    //As per the Equation given in the tutorial
	temperature = ((float)adcResult * VREF * 100)/4096;
	return temperature;			
}

/**
 * @brief 
 * name: averageTemperatureArray
 * @param array 
 * @return float 
 */
float averageTemperatureArray(float *array, int length)
{    
    float varRet = 0;
    float sum = 0;   
    if(length <=0)
    {
        varRet = -1;
    }else
    {        
        for (int x = 0; x < length; x++)
        {
            sum = sum + array[x];
        }
        varRet = (sum/length);
    }
    return varRet;    
}