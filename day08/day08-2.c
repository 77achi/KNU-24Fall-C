#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

int main(void) {
    int array[SIZE][SIZE];

    fillRandom(array);
    printArray(array);
    movePointer(array);
    
    return 0;
}

void fillRandom(int array[SIZE][SIZE]) {


    srand(time(NULL));

    for (int i1 = 0; i1 < SIZE; i1++) {
        for (int i2 = 0; i2 < SIZE; i2++) {
            array[i1][i2] = 1 + rand() % 20;
        }
    }


}

void printArray(int array[SIZE][SIZE]) {

    for (int i1 = 0; i1 < SIZE; i1++) {
        for (int i2 = 0; i2 < SIZE; i2++) {
            printf("%3d", array[i1][i2]);
        }
        printf("\n");
    }
}

void movePointer(void* array) {
    int n = 0;
    int *taget;
    int value = 0;
    int num = 0;

    while (1) {
        taget = ((int*)array + n);
        value = *taget;

        printf("현재 위치 : (%d, %d), 배열의 값 : %2d\n", n / 10, n % 10, value);
        
        n += value;

        if (n / 10 == 10) {
            n -= value;
            printf("더 이상 이동할 수 없습니다.\n");
            printf("종료 위치 : (%d, %d), 배열의 값 : %2d\n", n / 10, n % 10, value);
            break;
        }
    }
}