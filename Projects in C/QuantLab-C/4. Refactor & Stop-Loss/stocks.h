#ifndef STOCKS_H
#define STOCKS_H

typedef struct {
    char date[12];
    float open;
    float close;
    float low;
    float high;
    int volume;
} Stocks;

#endif