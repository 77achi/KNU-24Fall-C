#include<stdio.h>
#include<math.h>

int main(void) {
	int a, b, c;
	double d;

	printf("이차방정식을 입력하시오. (예 : ax^2 + bx + c)\n");
	printf("a: ");
	scanf_s("%d", &a);
	printf("b: ");
	scanf_s("%d", &b);
	printf("c: ");
	scanf_s("%d", &c);

	d = (b * b) - (4 * (a * c));

	if (d > 0) {
		printf("서로 다른 두 실근 : %.2lf, %.2lf\n", (-b + sqrt(d) / (2.0 * a)), (-b - sqrt(d) / (2.0 * a)));
	} 
	else if(d == 0){
		printf("실중근 : %.2lf\n", (-b / (2.0 * a)));
	}
	else {
		printf("허근을 갖습니다.\n");
	}

	return 0;
}