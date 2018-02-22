#include<stdio.h>
#include<math.h>

const float a = 4.735;
const float b = 8.216;

int main() {
    float l, m;
    puts("Please type the value of l (2.685, 7.21):\n");
    scanf("%f", &l);

    if(a >= l) {
        m = sqrt( fabs(a - exp(l - 0.5)) * b );
    } else if(b >= l && l >= (a + b) / 2) {
        m = a * log(b);
    } else {
        puts("The value you typed is invalid.");
        return 0;
    }

    printf("\nResult: %f", m);
}