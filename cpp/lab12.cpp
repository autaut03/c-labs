#include<stdio.h>

#define STRINGS_COUNT 3
#define CUT_OF_EACH 5

int main() {
    char strings[STRINGS_COUNT][20] = {
            "Hello31203123",
            " worl39210392103",
            "d! =)123"
    };

    char res[STRINGS_COUNT * CUT_OF_EACH];

    for(int i = 0; i < STRINGS_COUNT; i++) {
        for(int j = 0; j < CUT_OF_EACH; j++) {
            res[i * CUT_OF_EACH + j] = strings[i][j];
        }
    }

    printf("Resulting string: %s", res);
}