#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include "stocks.h"
#include "signal.h"

void execute_trade(Signal *signal, float price, float *cash, float *holdings, float *buy_price);

float calculate_wealth(float cash, float holdings, float price);

void reduce_lost(Signal *signal, float *buy_price, float current_price, double loss_percent, float *cash, float *holdings);

#endif