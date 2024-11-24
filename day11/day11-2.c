#include<stdio.h>
#include<math.h>

int main(void) {
	int start, end, n;
	double n_p, x_n;
	printf("적분할 시작 값을 입력하시오 : ");
	scanf_s("%d", &start);
	printf("적분할 끝 값을 입력하시오 : ");
	scanf_s("%d", &end);
	printf("시행할 최대 구간을 입력하시오(2^n) : ");
	scanf_s("%d", &n);

	n_p = pow(2.0, n);

	for (int i = 1; i <= n_p; i = i * 2) {
		double re = 0, fx = 0;
		x_n = ((double)end - start) / i;

		for (int j = 1; j <= i; j++) {
			double x = (x_n * j) + start;
			fx = -log10(1.0 / x) + sin(x);
			re = re + (fx * x_n);
		}
		printf("구간 \t%d 적분 결과 : %lf\n", i, re);
	}
	return 0;
}