#include<stdio.h>

int cal(int num1);

int main(void) {

	int num;
	printf("����� ���丮�� �� �Է� : ");
	scanf_s("%d", &num);

	int res = cal(num);

	printf("%d! = %d\n", num, res);
	return 0;
}

int cal(int num1) {
	int res;
	if ((num1 == 0) || (num1 == 1)) {
		return 1;
	}
	res = num1 * cal(num1 - 1);
	return res;
}