#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include "stocks.h"
#include "signal.h"

void execute_trade(Signal signal, float price, float *cash, float *holdings);

float calculate_wealth(float cash, float holdings, float price);

#endif