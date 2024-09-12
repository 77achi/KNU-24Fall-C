#include<stdio.h>
int main(void) {
	int num;
	printf("원하는 기능을 입력하시오.\n");
	printf("1.더하기, 2.빼기, 3.곱하기, 4. 나누기\n");

	scanf_s("%d", &num);

	double num1, num2, result = 0.;

	printf("첫번째 숫자: ");
	scanf_s("%lf", &num1);
	printf("두번째 숫자: ");
	scanf_s("%lf", &num2);


	if (num == 1) 
	{
		result = num1 + num2;
	}
	else if (num == 2) {
		result = num1 - num2;
	}
	else if (num == 2) {
		result = num1 * num2;
	}
	else if (num == 2) {
		result = num1 / num2;
	}
	else {
		printf("잘못 입력하였습니다.");
	}
	printf("%.2lf", result);
	return 0;
}
