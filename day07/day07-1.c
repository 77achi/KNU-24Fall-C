#include<stdio.h>

int main(void) {
	int num1;
	scanf_s("%d", &num1);

	for (int i = 1; i < num1 + 1; i++) {
		for (int s = i; s < num1; s++)
			printf(" ");
		for (int p = 0; p <= (i - 1)+(i - 1); p++)
			printf("*");
		printf("\n");
	}
}