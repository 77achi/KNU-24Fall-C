#include<stdio.h>

int ser(int num1);

int main(void) {
	int num, res;

	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &num);

	res = ser(num);

	if (res == 0) {
		printf("해당 수는 소수가 아닙니다.\n");
	}
	else {
		printf("해당 수는 소수입니다.\n");
	}

	return 0;
}

int ser(int num1) {
	int sum = 0;
	for (int sa = 1; sa <= num1;sa++) {
		if (num1 % sa == 0) {
			sum++;
		}
	}

	if (sum == 2) {
		return 1;
	}
	else {
		return 0;
	}

    /*for (int sa = 2; sa < num1; sa++)
	if (num1 % sa == 0) {
		retrun 0;
	}
    return 1;*/
}