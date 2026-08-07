#include "portfolio.h"
#include "stocks.h"
#include "signal.h"
#include "indicator.h"
#include <stdlib.h>

void execute_trade(Signal *signal, float price, float *cash, float *holdings, float *buy_price) {
    if (*signal == BUY && *cash > 0 && *holdings == 0) {
        *holdings = *cash / price;
        *cash = 0.0;
        *buy_price = price;
    } else if (*signal == SELL && *holdings > 0) {
        *cash = *holdings * price;
        *holdings = 0.0;
    }
}

float calculate_wealth(float cash, float holdings, float price) {
    return cash + (holdings * price);
}

void reduce_lost(Signal *signal, float *buy_price, float current_price, double loss_percent, float *cash, float *holdings) {
    if (*holdings > 0 && *buy_price > 0) {
        if ((*buy_price - current_price) / *buy_price >= loss_percent) {
                *signal = SELL;
                execute_trade(signal, current_price, cash, holdings, buy_price);
                *buy_price = 0.00;
        }
    }
}