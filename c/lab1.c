#include<stdio.h>
#include<math.h>

const int w = 700;
const float L = 0.1;
const float R = 32.5;
const float Um = 320.4;

int main() {
   float t;
   printf("Please type the value of t, as \"0.225\":\n");
   scanf("%f", &t);
   
   float f = atan(L * w / R);
   float i = (Um / (
            R * sqrt(
                pow(w * L / R, 2) + 1
            )
       )) * sin(w * t - f);
       
    printf("\nThe result is %f", i);
}