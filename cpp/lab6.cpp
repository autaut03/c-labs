#include<stdio.h>

//#define TYPE_FROM_KEYBOARD // comment this to get pre-filled array
#define ARR_SIZE 15 // розмір массиву

int isOdd(int num) {
    return num % 2 != 0;
}

int main() {

    // ввід данних з клавіатури по порядку
#ifdef TYPE_FROM_KEYBOARD
    int arr[ARR_SIZE];
   printf("Please type in %d integer values one by one:", ARR_SIZE);
   for(int i = 0; i < ARR_SIZE; i++) {
       scanf("%d", &arr[i]);
   }
#else
    // заповнений массив
    int arr[ARR_SIZE] = {2, -32, 582, 893, 28, 56, 1238, 10924, -23, -10322, 40, 12, 792, 7842, -769};
#endif

    int resultArr[ARR_SIZE]; // результативний массив
    int maxIndex = 0; // індекс максимального елементу кінцевого массиву

    // знаходження індекса максимального елементу і одночасне заповення елементів
    // кінцевого массиву
    for(int i = 1; i < ARR_SIZE; i++) {
        if(arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }

        resultArr[i] = arr[i];
    }

    // піднесення до квадрату усіх НЕПАРНИХ чисел, після індексу maxIndex
    for(int i = (maxIndex + 1); i < ARR_SIZE; i++) {
        resultArr[i] = pow(resultArr[i], 2);
    }

    printf("\nGiven array is: \n");
    for(int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nResulting array is: \n");
    for(int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\nMax index and number: [%d] = %d", maxIndex, arr[maxIndex]);
}