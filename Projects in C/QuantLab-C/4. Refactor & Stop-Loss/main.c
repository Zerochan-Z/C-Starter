#include "indicator.h"
#include "stocks.h"
#include "signal.h"
#include "utils.h"
#include "portfolio.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
1. Open file
2. Skip header
3. While there are lines to read:
   a. Read a line
   b. Parse it into `s`
   c. Grow the array
   d. Store `s` in the array
   e. Increment count
4. You now have an array of all data
5. Close the file
6. Do something with the data
7. Free the memory when done
*/

int main() {
    Stocks *stocks = NULL; 
    // stocks = pointer to array of stocks starts as empty
    int count = 0;

    char *path = "D:/Users/Zac Tee/Documents/GitHub/C-Starter/Projects in C/QuantLab-C/5. Stop-Loss/data.csv";
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        printf("No certain file.\n");
        return 1;
    }
    
    char line[200];
    fgets(line, sizeof(line), file);
    Stocks s;

    while (fgets(line, sizeof(line), file) != NULL) {
        parse_csv_line(line, &s);

        Stocks *temp = realloc(stocks, (count + 1) * sizeof(Stocks));

        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            free(stocks);
            return 1;
        }

        stocks = temp;
        stocks[count] = s; 
        // copies s into array
        // stocks[0] = first row of data ✅
        // s.date → stocks[count].date
        // and so on...
        count ++;
    }

    print_stock(stocks, count);

    float *sma5 = calculate_sma(stocks, count, 5);
    float *sma20 = calculate_sma(stocks, count, 20);
    float *dailyReturn = calculate_daily_return(stocks, count);

    if (sma5 == NULL || sma20 == NULL || dailyReturn == NULL) {
        printf("Results loading failed.\n");
        return 1;
    }
    Signal signal;

    float cash = 10000.00;
    float holdings = 0.0;
    float totalWealth = 0.0;
    float startingCash = 10000.00;
    float buy_price = 0.0;

    for (int i = 0; i < count; i++) {
        if (i < 20) {
            signal = HOLD;
        } else if (sma5[i] > sma20[i] && sma5[i-1] <= sma20[i-1]) {
            signal = BUY;
        } else if (sma5[i] < sma20[i] && sma5[i-1] >= sma20[i-1]) {
            signal = SELL;
        } else {
            signal = HOLD;
        }

        reduce_lost(&signal, &buy_price, stocks[i].close, 0.10, &cash, &holdings);
        const char *sig = signal_name(signal);

        execute_trade(&signal, stocks[i].close, &cash, &holdings, &buy_price);
        totalWealth = calculate_wealth(cash, holdings, stocks[i].close);

        printf("%d. %s | C: %.2f | SMA5: %.2f | SMA20: %.2f | Return: %.2f%% |\nSignal: %s | Total Wealth: %.2f\n",
                i + 1, stocks[i].date, stocks[i].close,
                sma5[i], sma20[i], dailyReturn[i] * 100, 
                sig, totalWealth);
    }

    portfolio_summary(startingCash, cash, holdings, totalWealth);

    free(sma5);
    free(sma20);
    free(stocks);
    free(dailyReturn);
    return 0;
}