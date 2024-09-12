#include<stdio.h>

int main(void) {
	int num1;

	for (num1 = 0; num1 < 100; num1++) {
		if ((num1 % 3 == 0 && num1 % 4 == 0) || num1 % 7 == 0) {
			printf("%d ", num1);
		}
	}
	return 0;
}