#include <iostream>
#include <cmath>

using namespace std;

string labNames[] = {
        "lab1", "lab2", "lab3", "lab3_2", "lab3_3", "lab4", "lab5", "lab6", "lab6_2_13",
        "lab7", "lab8", "lab9", "lab9_19", "lab9_39", "lab10_17", "lab11_10", "lab12", "lab13"
};

void runLabByNumber(int number);

int main() {
    // Print available options.
    for(size_t i = 0; i < 17; i++) {
        cout << i + 1 << ") " << labNames[i] << endl;
    }

    cout << "Choose the lab you want to run and enter it's number: " << endl;

    // Read the option chosen.
    int labNumber;
    cin >> labNumber;

    // Check if it's valid.
    if(labNumber < 1 || labNumber > 17) {
        cout << "The lab number you've chosen isn't valid.";
        return 1;
    }

    cout << "Running lab #" << labNumber << endl;

    runLabByNumber(labNumber);
}

void lab1() {
    const int w = 700;
    const float L = 0.1;
    const float R = 32.5;
    const float Um = 320.4;

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

void lab2() {
    const float a = 4.735;
    const float b = 8.216;

    float l, m;
    puts("Please type the value of l (2.685, 7.21):\n");
    scanf("%f", &l);

    if(a >= l) {
        m = sqrt( fabs(a - exp(l - 0.5)) * b );
    } else if(b >= l && l >= (a + b) / 2) {
        m = a * log(b);
    } else {
        puts("The value you typed is invalid.");
        return;
    }

    printf("\nResult: %f", m);
}

void lab3() {
    const float a = 1.42;
    const float b = 0.85;

    float z;
    puts("Please type the value of z (any valid floating point number):");
    scanf("%f", &z);

    for(float t = 1.6; t > 0.35; t -= 0.3125) {
        float y = sqrt(pow(t, 3) + pow(b, 2)) / sin(atan(z + b));

        printf("\nX: %f, Y: %f", t, y);
    }
}

void lab3_2() {
    const float a = 1.42;
    const float b = 0.85;

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

void lab3_3() {
    const float a = 1.42;
    const float b = 0.85;

    float z;
    puts("Please type the value of z (any valid floating point number):");
    scanf("%f", &z);

    float t = 1.6;
    do {
        float y = sqrt(pow(t, 3) + pow(b, 2)) / sin(atan(z + b));
        printf("\nX: %f, Y: %f", t, y);

        t -= 0.3125;
    } while(t > 0.35);
}

void lab4() {
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

#define E 1e-4

void lab5() {
    float x, y = 1.5;

    do {
        x = y;
        y = (6*pow(x, 3) - 4*pow(x, 2) + 3)
            / (9*pow(x, 2) - 8*x + 2);
    } while (fabs(x - y) > E);

    printf("\nResult: %f", x);
}

void lab6_2_13() {
    int ARR_SIZE = 15;
    // ввід данних з клавіатури по порядку
    /*

    int arr[ARR_SIZE];
    printf("Please type in %d integer values one by one:", ARR_SIZE);
    for(int i = 0; i < ARR_SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    */

    // заповнений массив
    int arr[ARR_SIZE] = {2, -32, 582, 893, 28, 56, 1238, 10924, -23, -10322, 40, 12, 792, 7842, -769};

    int minIndex = 0; // індекс мінімального елементу масиву

    // знаходження індекса мінімального елементу
    for(int i = 1; i < ARR_SIZE; i++) {
        if(arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    int resultArrSize = ARR_SIZE - minIndex;
    int resultArr[resultArrSize]; // результативний массив відповідного розміру

    // заповнення
    for(int i = 0; i < resultArrSize; i++) {
        resultArr[i] = arr[minIndex + i];
    }

    printf("Resulting array is ");
    for(int i = 0; i < resultArrSize; i++) {
        printf("%d ", resultArr[i]);
    }
}

void lab7() {
    int ARR_SIZE = 16;

    int arr[ARR_SIZE] = {2, -32, 582, 893, 28, 56, 1238, 10924, -23, -10322, 40, 12, 792, 7842, -769};
    int sum = 0;
    int count = 0;

    for(int i = 0; i < ARR_SIZE; i++) {
        int el = arr[i];

        if(el % 2 != 0 || el % 3 != 1) continue;

        sum += el;
        count++;
    }

    if(count == 0) {
        puts("There are no matching values");
        return;
    }

    printf("Result is %f", (float) sum / count);
}

void lab8() {
    for(float a = 2.45; a <= 3.16; a += 0.35) {
        for(float b = 6.82; b <= 10.3; b += 1.15) {
            printf("\nA: %f, B: %f, value: %f", a, b,
                   sqrt((pow(a, 3) + pow(b, 1.3)) / log2(a))
            );
        }
    }
}

void lab9() {
    int ARR_SIZE = 15;

    int arr[ARR_SIZE][ARR_SIZE] = {
            {84, 11, -68, -61, -53, 9, 14, -69, 50, -64, 6, -93, -98, -85, 94},
            {67, -33, 81, -6, -92, 83, 36, -87, 85, -62, -9, -41, -73, 42, -78},
            {78, -50, 96, 16, -31, -73, 49, -73, -91, -66, -2, 11, -55, 30, 13},
            {-77, -86, -66, 70, 87, -22, 19, 98, -17, 17, 93, -46, 35, 29, 44},
            {-98, 26, -89, 16, -15, -36, -26, -17, 82, 20, 98, -4, 15, -49, 51},
            {-55, -91, 79, 63, -82, 82, -76, -19, 32, -65, 67, -23, 73, 12, -95},
            {-43, -13, -34, -53, -65, 50, 12, 52, 55, -22, -9, -20, -66, -86, -50},
            {48, -93, 44, 62, 86, -62, 7, -5, 98, 75, -6, 49, 2, -51, 17},
            {29, 69, 50, -11, -25, -39, -84, 15, 72, 88, 99, 46, -89, 89, 20},
            {-36, -43, 24, 31, 36, 60, -99, -21, 90, 1, 1, -48, -43, -67, 50},
            {69, 17, 23, -21, 45, 57, -71, -63, -95, -1, -28, 29, -93, -14, 21},
            {81, 39, -7, -6, 69, 54, -14, -67, -94, -8, 80, 33, 16, 55, -2},
            {89, 39, -78, -40, -67, -47, 41, 88, -58, 87, 76, 47, 60, -21, 13},
            {2, 0, 52, -33, 94, 16, 82, 77, -54, -61, -79, 36, 35, 29, 83},
            {-74, 13, -45, 16, 6, -63, 37, -8, -80, 44, -74, -43, -45, 99, 53}
    };

    int sum = 0;

    for(int i = 0; i < ARR_SIZE; i++) {
        for(int j = 0; j < ARR_SIZE; j++) {
            if(i == j)
                continue;

            sum += arr[i][j];
        }
    }

    printf("%d", sum);
}

void lab9_19() {
    int ARR_SIZE = 9;

    int arr[ARR_SIZE][ARR_SIZE] = {
            { 234, -384, 319, -157, -345, 307, 284, -449, -361 },
            { -263, -144, -64, -133, 381, 104, 291, -309, 403 },
            { -80, 300, 318, 89, -296, 364, -458, 156, -294 },
            { -380, 90, 172, 48, -350, -195, -346, -247, 180 },
            { 443, 278, 73, 455, 414, 124, 82, -361, 204 },
            { -347, 291, 61, -99, 256, -489, -69, -439, 207 },
            { -360, 240, 109, -106, 442, 426, 83, 457, -45 },
            { 329, -372, 368, 260, -138, 349, 456, -310, -465 },
            { -199, 484, 391, 495, 115, -118, 495, 358, 10 }
    };

    // індекс мінімального елементу по двом осям
    int minXIndex = 0, minYIndex = 0;

    // знаходження індексів мінімального елементу
    for(int y = 0; y < ARR_SIZE; y++) {
        for(int x = 0; x < ARR_SIZE; x++) {
            // пропуск значень, що більші за мінімальне
            if(arr[y][x] > arr[minYIndex][minXIndex]) continue;

            minXIndex = x;
            minYIndex = y;
        }
    }

    int resultArrSize = ARR_SIZE - 1;
    int resultArr[resultArrSize][resultArrSize];

    for(int y = 0; y < ARR_SIZE; y++) {
        for(int x = 0; x < ARR_SIZE; x++) {
            int resYIndex = y, resXIndex = x;

            if(y > minYIndex)
                resYIndex--;

            if(x > minXIndex)
                resXIndex--;

            resultArr[resYIndex][resXIndex] = arr[y][x];
        }
    }

    // друк кінцевого масиву
    printf("{");
    for(int x = 0; x < resultArrSize; x++) {
        printf("\n\t{");

        for(int y = 0; y < resultArrSize; y++) {
            printf("%d, ", resultArr[x][y]);
        }

        printf("}, ");
    }
    printf("\n}");

    printf("\nMinimal indexes: x = %d, y = %d and the value is %d", minXIndex, minYIndex, arr[minYIndex][minXIndex]);
}

void lab9_39() {
    int ARR_SIZE = 12;

    int arr[ARR_SIZE] = { 234, -384, 319, -157, -345, 307, 284, -449, 403, 291, -309, -361 };
    // -449 min, 403 max

    for(int j = 0; j < ARR_SIZE; j++) {
        for(int i = ARR_SIZE - 1; i > j; i --) {
            if(arr[i] < arr[i - 1])
                continue;

            // swap
            int temp = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = temp;
        }
    }

    printf("Sorted array: ");
    for(int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", arr[i]);
    }
}

void lab10_17_convert();

typedef struct {
    float x;
    float y;
    float polarRadius;
    float polarAngle;
} Point;

#define lab10_17_ARR_SIZE 5
Point points[lab10_17_ARR_SIZE] = {
        {1, 3},
        {5, -5},
        {7, 2},
        {-9, 0},
        {4, 6}
};

void lab10_17() {
    lab10_17_convert();

    for(int j = 0; j < lab10_17_ARR_SIZE; j++) {
        for(int i = lab10_17_ARR_SIZE - 1; i > j; i --) {
            if(points[i].polarRadius < points[i - 1].polarRadius)
                continue;

            // swap
            Point temp = points[i - 1];
            points[i - 1] = points[i];
            points[i] = temp;
        }
    }

    printf("Sorted array: ");
    for(int i = 0; i < lab10_17_ARR_SIZE; i++) {
        printf("\nx: %.2f, y: %.2f, polarRadius: %.2f, polarAngle: %.2f", points[i].x, points[i].y, points[i].polarRadius, points[i].polarAngle);
    }
}

void lab10_17_convert() {
    for(int i = 0; i < lab10_17_ARR_SIZE; i++) {
        points[i].polarRadius = sqrt(pow(points[i].x, 2) + pow(points[i].y, 2));
        points[i].polarAngle = atan(points[i].y / points[i].x);
    }
}

float lab11_10_fun(float x) {
    return x + log(x);
}

void lab11_10() {
    printf("Result: %.2f", cbrt(sqrt(lab11_10_fun(6.5))) / cbrt(sqrt(lab11_10_fun(0.7))));
}

void lab12() {
    int STRINGS_COUNT = 3;
    int CUT_OF_EACH = 5;

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

typedef struct {
    char city[30];
    char phoneNumber[20];
    float cost;
    float duration;
} PhoneCall;

void lab13_putCall(FILE *fp, PhoneCall call) {
    fprintf(fp, "City: %s, Number: %s, Overall cost: %.2f, Minutes: %.2f\r\n", call.city, call.phoneNumber, call.cost, call.duration);
}

void lab13() {
    PhoneCall calls[] = {
            {"Ivano-Frankivsk", "+441632960870", 17.23, 8.61},
            {"New York", "+441632960644", 89.61, 44.8},
            {"Walpole", "+441632960609", 32.49, 16.25},
            {"Santa Clara", "+441632960697", 4.92, 2.46}
    };

    FILE *fp1 = fopen("calls.txt", "ab+");
    FILE *fp2 = fopen("filteredCalls.txt", "ab+");
    float totalCost = 0;

    int i;
    for(i = 0; i < sizeof(calls)/sizeof(PhoneCall); i++) {
        lab13_putCall(fp1, calls[i]);
        totalCost += calls[i].duration;

        if(calls[i].duration > 10 && calls[i].cost > 30)
            lab13_putCall(fp2, calls[i]);
    }

    printf("Total cost is %.2f", totalCost);

    fclose(fp1);
    fclose(fp2);
}

void runLabByNumber(int number) {
    switch(number) {
        case 1:
            lab1();
            break;
        case 2:
            lab2();
            break;
        case 3:
            lab3();
            break;
        case 4:
            lab3_2();
            break;
        case 5:
            lab3_3();
            break;
        case 6:
            lab4();
            break;
        case 7:
            lab5();
            break;
        case 8:
            lab6_2_13();
            break;
        case 9:
            lab7();
            break;
        case 10:
            lab8();
            break;
        case 11:
            lab9();
            break;
        case 12:
            lab9_19();
            break;
        case 13:
            lab9_39();
            break;
        case 14:
            lab10_17();
            break;
        case 15:
            lab11_10();
            break;
        case 16:
            lab12();
            break;
        case 17:
            lab13();
            break;
    }
}