#include "portfolio.h"
#include "stocks.h"
#include "signal.h"
#include "indicator.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void parse_csv_line(char line[200], Stocks *s) {
    if (line == NULL) {
        printf("Nothing inside line.\n");
        return;
    }
    char *token = strtok(line, ",");
    strcpy(s->date, token);
    token = strtok(NULL, ",");
    s->open = atof(token);
    token = strtok(NULL, ",");
    s->high = atof(token);
    token = strtok(NULL, ",");
    s->low = atof(token);
    token = strtok(NULL, ",");
    s->close = atof(token);
    token = strtok(NULL, ",");
    s->volume = atoi(token);
}

void print_stock(Stocks *stocks, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s | O: %.2f H: %.2f L: %.2f C: %.2f V: %d\n", 
                i + 1, stocks[i].date, stocks[i].open, 
                stocks[i].high, stocks[i].low, 
                stocks[i].close, stocks[i].volume);
    }
}

const char* signal_name(Signal signal) {
    if (signal == 0) return "BUY";
    if (signal == -1) return "SELL";
    return "HOLD";
}

void portfolio_summary(float startingCash, float cash, float holdings, float totalWealth) {
    printf("\n --- Portfolio Summary --- \n");
    printf("Starting Cash: $%.2f\n", startingCash);
    printf("Final Cash: $%.2f\n", cash);
    printf("Final Holdings: %.2f shares\n", holdings);
    printf("Total Wealth: $%.2f\n", totalWealth);
    printf("Total Return: %.2f%%\n", (totalWealth - startingCash) / startingCash * 100);
}