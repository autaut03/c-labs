#include<stdio.h>
#include<math.h>

void convert();

typedef struct {
    float x;
    float y;
    float polarRadius;
    float polarAngle;
} Point;

#define ARR_SIZE 5
Point points[ARR_SIZE] = {
        {1, 3},
        {5, -5},
        {7, 2},
        {-9, 0},
        {4, 6}
};

int main() {
    convert();

    for(int j = 0; j < ARR_SIZE; j++) {
        for(int i = ARR_SIZE - 1; i > j; i --) {
            if(points[i].polarRadius < points[i - 1].polarRadius)
                continue;

            // swap
            Point temp = points[i - 1];
            points[i - 1] = points[i];
            points[i] = temp;
        }
    }

    printf("Sorted array: ");
    for(int i = 0; i < ARR_SIZE; i++) {
        printf("\nx: %.2f, y: %.2f, polarRadius: %.2f, polarAngle: %.2f", points[i].x, points[i].y, points[i].polarRadius, points[i].polarAngle);
    }
}

void convert() {
    for(int i = 0; i < ARR_SIZE; i++) {
        points[i].polarRadius = sqrt(pow(points[i].x, 2) + pow(points[i].y, 2));
        points[i].polarAngle = atan(points[i].y / points[i].x);
    }
}