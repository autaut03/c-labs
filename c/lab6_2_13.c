#include<stdio.h>
#include<math.h>

#define ARR_SIZE 15 // розмір массиву

int main() {
    // ввід данних з клавіатури по порядку
    /*

    int arr[ARR_SIZE];
    printf("Please type in %d integer values one by one:", ARR_SIZE);
    for(int i = 0; i < ARR_SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    */

    // заповнений массив
    int arr[ARR_SIZE] = {2, -32, 582, 893, 28, 56, 1238, 10924, -23, -10322, 40, 12, 792, 7842, -769};

    int minIndex = 0; // індекс мінімального елементу масиву

    // знаходження індекса мінімального елементу
    for(int i = 1; i < ARR_SIZE; i++) {
        if(arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    int resultArrSize = ARR_SIZE - minIndex;
    int resultArr[resultArrSize]; // результативний массив відповідного розміру

    // заповнення
    for(int i = 0; i < resultArrSize; i++) {
        resultArr[i] = arr[minIndex + i];
    }

    printf("Resulting array is ");
    for(int i = 0; i < resultArrSize; i++) {
        printf("%d ", resultArr[i]);
    }
}