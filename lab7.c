#include<stdio.h>

#define ARR_SIZE 16

int main() {
    int arr[ARR_SIZE] = {2, -32, 582, 893, 28, 56, 1238, 10924, -23, -10322, 40, 12, 792, 7842, -769};
    int sum = 0;
    int count = 0;

    for(int i = 0; i < ARR_SIZE; i++) {
        int el = arr[i];

        if(el % 2 != 0 || el % 3 != 1) continue;

        sum += el;
        count++;
    }

    if(count == 0) {
        puts("There are no matching values");
        return 0;
    }

    printf("Result is %f", (float) sum / count);
}