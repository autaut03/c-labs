#include<stdio.h>
#include<math.h>

int main() {
    for(float a = 2.45; a <= 3.16; a += 0.35) {
        for(float b = 6.82; b <= 10.3; b += 1.15) {
            printf("\nA: %f, B: %f, value: %f", a, b,
                   sqrt((pow(a, 3) + pow(b, 1.3)) / log2(a))
            );
        }
    }
}