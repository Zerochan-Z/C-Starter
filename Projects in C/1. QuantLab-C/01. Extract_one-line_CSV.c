#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char date[12];
    float open;
    float high;
    float low;
    float close;
    int volume;
} Stocks;

int main() {
    char *path = "D:/Users/Zac Tee/Documents/GitHub/C-Starter/Projects in C/QuantLab-C/data.csv";
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        printf("No certain file.\n");
        return 1;
    }

    char line[200];
    fgets(line, sizeof(line), file);
    // Discard first line

    fgets(line, sizeof(line), file);
    // Read the first line of actual stock data
    Stocks s;

    char *token = strtok(line, ","); 
    // strtok replaces the first comma delimiter with a null terminal ('\0')
    // and returns a pointer to the start of the first token
    strcpy(s.date, token);
    // copy to s.date from token
    token = strtok(NULL, ","); 
    // Parse subsequent tokens. strtok maintains its own internal pointer
    // so passing NULL tells it to continue where it left off.
    s.open = atof(token);
    // string to float (atof)
    // Like stof in C++
    token = strtok(NULL, ",");
    s.high = atof(token);
    token = strtok(NULL, ",");
    s.low = atof(token);
    token = strtok(NULL, ",");
    s.close = atof(token);
    token = strtok(NULL, ",");
    s.volume = atoi(token);

    printf("Date: %s\n", s.date);
    printf("Open: %.2f\n", s.open);
    printf("High: %.2f\n", s.high);
    printf("Low: %.2f\n", s.low);
    printf("Close: %.2f\n", s.close);
    printf("Volume: %d\n", s.volume);

    fclose(file);
    return 0;
}