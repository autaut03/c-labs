#include <stdio.h>
#include <string.h>

typedef struct {
    char city[30];
    char phoneNumber[20];
    float cost;
    float duration;
} PhoneCall;

// ???? ?????? ??????? (60?) = 2???

void putCall(FILE *fp, PhoneCall call) {
    fprintf(fp, "City: %s, Number: %s, Overall cost: %.2f, Minutes: %.2f\r\n", call.city, call.phoneNumber, call.cost, call.duration);
}

int main() {
    PhoneCall calls[] = {
            {"Ivano-Frankivsk", "+441632960870", 17.23, 8.61},
            {"New York", "+441632960644", 89.61, 44.8},
            {"Walpole", "+441632960609", 32.49, 16.25},
            {"Santa Clara", "+441632960697", 4.92, 2.46}
    };

    FILE *fp1 = fopen("calls.txt", "ab+");
    FILE *fp2 = fopen("filteredCalls.txt", "ab+");
    float totalCost = 0;

    int i;
    for(i = 0; i < sizeof(calls)/sizeof(PhoneCall); i++) {
        putCall(fp1, calls[i]);
        totalCost += calls[i].duration;

        if(calls[i].duration > 10 && calls[i].cost > 30)
            putCall(fp2, calls[i]);
    }

    printf("Total cost is %.2f", totalCost);

    fclose(fp1);
    fclose(fp2);

    getchar();
    return 0;
}