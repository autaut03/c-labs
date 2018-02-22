#include<stdio.h>

#define ARR_SIZE 12

int main() {
    int arr[ARR_SIZE] = { 234, -384, 319, -157, -345, 307, 284, -449, 403, 291, -309, -361 };
    // -449 min, 403 max

    for(int j = 0; j < ARR_SIZE; j++) {
        for(int i = ARR_SIZE - 1; i > j; i --) {
            if(arr[i] < arr[i - 1])
                continue;

            // swap
            int temp = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = temp;
        }
    }

    printf("Sorted array: ");
    for(int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", arr[i]);
    }
}