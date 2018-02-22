#include<stdio.h>
#include<math.h>

const float a = 1.42;
const float b = 0.85;

int main() {
    float z;
    puts("Please type the value of z (any valid floating point number):");
    scanf("%f", &z);

    float t = 1.6;
    while(t > 0.35) {
        float y = sqrt(pow(t, 3) + pow(b, 2)) / sin(atan(z + b));
        printf("\nX: %f, Y: %f", t, y);

        t -= 0.3125;
    }
}