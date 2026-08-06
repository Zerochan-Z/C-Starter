#ifndef INDICATOR_H
#define INDICATOR_H

#include "stocks.h"

float* calculate_sma(Stocks *stocks, int count, int period);

float *calculate_daily_return(Stocks *stocks, int count);

#endif