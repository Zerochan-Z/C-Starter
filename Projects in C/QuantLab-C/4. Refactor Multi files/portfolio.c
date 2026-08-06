#include "portfolio.h"
#include "stocks.h"
#include "signal.h"
#include "indicator.h"
#include <stdlib.h>

void execute_trade(Signal signal, float price, float *cash, float *holdings) {
    if (signal == BUY && *cash > 0 && *holdings == 0) {
        *holdings = *cash / price;
        *cash = 0.0;
    } else if (signal == SELL && *holdings > 0) {
        *cash = *holdings * price;
        *holdings = 0.0;
    }
}

float calculate_wealth(float cash, float holdings, float price) {
    return cash + (holdings * price);
}