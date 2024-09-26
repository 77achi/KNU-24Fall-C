#include<stdio.h>

void swap(int* pnum1, int* pnum2) {
	int temp = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = temp;
}

int main(void) {
	int num1, num2;
	scanf_s("%d %d", &num1, &num2);
	printf("%d, %d\n", num1, num2);

	swap(&num1, &num2);

	printf("%d, %d\n", num1, num2);

	return 0;
}