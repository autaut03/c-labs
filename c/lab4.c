#include<stdio.h>
#include<math.h>

int main() {
    float a, b;
    puts("Type values a and b divided with whitespace (as such: 0.85 0.92):");
    scanf("%f %f", &a, &b);

    for(float x = 0.5; x <= 8.5; x += 0.05) {
        float y_num = b * cos(x);
        float y_denum = a * pow(x, 2) + b * pow(x, 3) * sin(x);
        float y = y_num / y_denum;

        if(fabs(y_denum) < 1e-3) {
            y = 1e6;
        }

        printf("\nX: %f, Y: %f", x, y);
    }
}