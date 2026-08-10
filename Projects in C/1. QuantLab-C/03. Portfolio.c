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

typedef struct {
    char date[12];
    float open;
    float close;
    float low;
    float high;
    int volume;
} Stocks;

typedef enum {
    HOLD = 0,
    BUY = 1,
    SELL = -1,
} Signal;

int main() {
    Stocks *stocks = NULL; 
    // stocks = pointer to array of stocks starts as empty
    int count = 0;

    char *path = "D:/Users/Zac Tee/Documents/GitHub/C-Starter/Projects in C/QuantLab-C/data.csv";
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        printf("No certain file.\n");
        return 1;
    }
    
    char line[200];
    fgets(line, sizeof(line), file);
    Stocks s;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, ",");
        strcpy(s.date, token);
        token = strtok(NULL, ",");
        s.open = atof(token);
        token = strtok(NULL, ",");
        s.high = atof(token);
        token = strtok(NULL, ",");
        s.low = atof(token);
        token = strtok(NULL, ",");
        s.close = atof(token);
        token = strtok(NULL, ",");
        s.volume = atoi(token);

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

    for (int i = 0; i < count; i++) {
        printf("%d. %s | O: %.2f H: %.2f L: %.2f C: %.2f V: %d\n", 
                i + 1, stocks[i].date, stocks[i].open, 
                stocks[i].high, stocks[i].low, 
                stocks[i].close, stocks[i].volume);
    }

    float *sma5 = malloc(count * sizeof(float));
    float *sma20 = malloc(count * sizeof(float));
    float *dailyReturn = malloc(count * sizeof(float));

    if (sma5 == NULL || sma20 == NULL || dailyReturn == NULL) {
        printf("Results loading failed.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        if (i >= 4) {
            float sum = 0.00;
            for (int k = i - 4; k <= i; k++) {
                sum += stocks[k].close;
            }
            sma5[i] = sum / 5.0;
        } else {
            sma5[i] = 0.00;
        }

        if (i < 19) {
            sma20[i] = 0.00;
        } else {
            float sum = 0.00;
            for (int k = i - 19; k <= i; k++) {
                sum += stocks[k].close;
            }
            sma20[i] = (sum / 20);
        }

        if (i == 0) {
            dailyReturn[i] = 0.00;
        } else {
            dailyReturn[i] = (stocks[i].close - stocks[i-1].close) / stocks[i - 1].close;
        }

    }

    Signal signal;

    float cash = 10000.00;
    float holdings = 0.0;
    float totalWealth = 0.0;
    float startingCash = 10000.00;

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

        char sig[6];
        if (signal == 0) {
            strcpy(sig, "HOLD");
        } else if (signal == 1) {
            strcpy(sig, "BUY");
        } else if (signal == -1) {
            strcpy(sig, "SELL");
        } else {
            strcpy(sig, "ERROR");
        }

        if (signal == BUY && cash > 0 && holdings == 0) {
            holdings = cash / stocks[i].close;
            cash = 0.0;
        } else if (signal == SELL && holdings > 0) {
            cash = holdings * stocks[i].close;
            holdings = 0.0;
        } 
        totalWealth = cash + (holdings * stocks[i].close);

        printf("%d. %s | C: %.2f | SMA5: %.2f | SMA20: %.2f | Return: %.2f%% |\nSignal: %s | Total Wealth: %.2f\n",
                i + 1, stocks[i].date, stocks[i].close,
                sma5[i], sma20[i], dailyReturn[i] * 100, 
                sig, totalWealth);
    }

    printf("\n--- Portfolio Summary ---\n");
    printf("Starting Cash: $%.2f\n", startingCash);
    printf("Final Cash: $%.2f\n", cash);
    printf("Final Holdings: %.2f shares\n", holdings);
    printf("Total Wealth: $%.2f\n", totalWealth);
    printf("Total Return: %.2f%%\n", (totalWealth - startingCash) / startingCash * 100);

    free(sma5);
    free(sma20);
    free(stocks);
    free(dailyReturn);
    return 0;
}