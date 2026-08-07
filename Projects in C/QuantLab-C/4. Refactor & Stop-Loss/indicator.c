#include "indicator.h"
#include "stocks.h"
#include <stdlib.h>

float* calculate_sma(Stocks *stocks, int count, int period) {
    float *sma = malloc(count * sizeof(float));

    if (sma == NULL) {
        return NULL;
    }

    for (int i = 0; i < count; i++) {
        if (i < period - 1) {
            sma[i] = 0.0;
            continue;
        }

        float sum = 0.0;
        for (int k = i - period + 1; k <= i; k++) {
            sum += stocks[k].close;
        }

        sma[i] = sum / (float) period;
    }
    return sma;
}

float *calculate_daily_return(Stocks *stocks, int count) {
    float *returns = malloc(count * sizeof(float));
    if (returns == NULL) {
        return NULL;
    }

    returns[0] = 0.0;

    for (int i = 0; i < count; i++) {
        if (stocks[i-1].close == 0.0) {
            returns[i] = 0.0;
        } else {
            returns[i] = (stocks[i].close - stocks[i-1].close) / stocks[i-1].close;
        }
    }

    return returns;
}