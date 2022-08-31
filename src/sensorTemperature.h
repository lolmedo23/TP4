# ifndef sensorTemperature_H
# define sensorTemperature_H

#include "lpc17xx.h"
#include <time.h>
#include <stdio.h>   

#define START_CNV           (1<<24) //001 for starting the conversion immediately
#define ADC_DONE            (1U<<31) //define it as unsigned value or compiler will throw #61-D warning
#define VREF                3.3 //Reference Voltage at VREFP pin, given VREFN = 0V(GND) - not used in this example.

float readTemperatureADC0(void);
float averageTemperatureArray(float *array, int length);

# endif