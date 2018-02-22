#include<stdio.h>

#define ARR_SIZE 9

int main() {
    int arr[ARR_SIZE][ARR_SIZE] = {
            { 234, -384, 319, -157, -345, 307, 284, -449, -361 },
            { -263, -144, -64, -133, 381, 104, 291, -309, 403 },
            { -80, 300, 318, 89, -296, 364, -458, 156, -294 },
            { -380, 90, 172, 48, -350, -195, -346, -247, 180 },
            { 443, 278, 73, 455, 414, 124, 82, -361, 204 },
            { -347, 291, 61, -99, 256, -489, -69, -439, 207 },
            { -360, 240, 109, -106, 442, 426, 83, 457, -45 },
            { 329, -372, 368, 260, -138, 349, 456, -310, -465 },
            { -199, 484, 391, 495, 115, -118, 495, 358, 10 }
    };

    // індекс мінімального елементу по двом осям
    int minXIndex = 0, minYIndex = 0;

    // знаходження індексів мінімального елементу
    for(int y = 0; y < ARR_SIZE; y++) {
        for(int x = 0; x < ARR_SIZE; x++) {
            // пропуск значень, що більші за мінімальне
            if(arr[y][x] > arr[minYIndex][minXIndex]) continue;

            minXIndex = x;
            minYIndex = y;
        }
    }

    int resultArrSize = ARR_SIZE - 1;
    int resultArr[resultArrSize][resultArrSize];

    for(int y = 0; y < ARR_SIZE; y++) {
        for(int x = 0; x < ARR_SIZE; x++) {
            int resYIndex = y, resXIndex = x;

            if(y > minYIndex)
                resYIndex--;

            if(x > minXIndex)
                resXIndex--;

            resultArr[resYIndex][resXIndex] = arr[y][x];
        }
    }

    // друк кінцевого масиву
    printf("{");
    for(int x = 0; x < resultArrSize; x++) {
        printf("\n\t{");

        for(int y = 0; y < resultArrSize; y++) {
            printf("%d, ", resultArr[x][y]);
        }

        printf("}, ");
    }
    printf("\n}");

    printf("\nMinimal indexes: x = %d, y = %d and the value is %d", minXIndex, minYIndex, arr[minYIndex][minXIndex]);
}