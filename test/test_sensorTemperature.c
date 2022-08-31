#include "unity.h"
#include "sensorTemperature.h"

//Test to verify the minimum (2°C due to the hardware connection used) temperature delivered by the LM35
void test_read_Min_Temperature_LM35_ADC0(void)
{    
    float expectedTemperature = 2.0f;
    float tolerance = 0.25f;
    LPC_ADC->ADDR0=0xFFFF019F;
    float temperature = readTemperatureADC0();
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature,temperature);
}

//An intermediate temperature is verified to corroborate the linearity of the LM35 sensor
void test_readTemperature_ADC0(void)
{    
    float expectedTemperature = 32.0f;
    float tolerance = 0.25f;
    LPC_ADC->ADDR0=0xFFFF18DF;
    float temperature = readTemperatureADC0();
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature,temperature);
}

//Test to verify the maximum temperature delivered by the LM35
void test_read_Max_Temperature_LM35_ADC0(void)
{    
    float expectedTemperature = 150.0f;
    float tolerance = 0.25f;
    LPC_ADC->ADDR0=0xFFFF745F;
    float temperature = readTemperatureADC0();
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature,temperature);
}

//The test verifies the calculation of average temperatures
void test_Average_Temperature()
{
    float array[3] = { 10.0f, 12.0f, 14.0f };
    float expectedAverage = 12.0f;
    float tolerance = 0.2f;
    int length = sizeof(array)/sizeof(float);
    float average = averageTemperatureArray(array, length);
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedAverage, average);
}

//Test verifies number of elements equal to zero
void test_Average_Length_Zero()
{
    float array[3] = { 10.0f, 12.0f, 14.0f };
    float expectedAverage = -1;
    float tolerance = 0.2f;
    int length = 0;
    float average = averageTemperatureArray(array, length);
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedAverage, average);
}

//Test verifies number of elements less than zero
void test_Average_Length_Negative()
{
    float array[3];
    float expectedAverage = -1;
    float tolerance = 0.2f;
    int length = -1;
    float average = averageTemperatureArray(array, length);
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedAverage, average);
}