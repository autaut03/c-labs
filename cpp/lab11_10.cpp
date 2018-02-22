#include<stdio.h>
#include<math.h>

float fun(float x) {
    return x + log(x);
}

int main() {
    printf("Result: %.2f", cbrt(sqrt(fun(6.5))) / cbrt(sqrt(fun(0.7))));
}