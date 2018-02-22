#include<stdio.h>
#include<math.h>

#define E 1e-4

int main() {
    float x, y = 1.5;

    do {
        x = y;
        y = (6*pow(x, 3) - 4*pow(x, 2) + 3)
            / (9*pow(x, 2) - 8*x + 2);
    } while (fabs(x - y) > E);

    printf("\nResult: %f", x);
}