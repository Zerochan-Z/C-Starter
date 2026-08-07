#ifndef UTILS_H
#define UTILS_H

#include "stocks.h"
#include "indicator.h"

void parse_csv_line(char line[200], Stocks *s);

void print_stock(Stocks *stocks, int count);

const char* signal_name(Signal signal);

void portfolio_summary(float startingCash, float cash, float holdings, float totalWealth);

#endif