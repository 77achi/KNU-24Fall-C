#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(void) {
	double x = 0;
	double y = 0;

	int count = 0, circle = 0;
	int r = 1;

	srand(time(NULL));

	for (count = 0; count < 1000000000; count++) {
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;

		if (sqrt(pow(x, 2) + pow(y, 2)) < r) {
			circle++;
		}

		if (count % 10000000 == 0) {
			int c = count / 10000000;
			float f = 0;
			f = (float)(4 * circle) / count;
			printf("%d%%진행.. 원주율 : %f", c, f);
			int k = c / 5;

			
			for (int v = 0; v < k; v++)
				printf("■");
			for (int j = 20 - k; j > 0; j--) {
				printf("□");
			}

			
				
			
			printf("\n");
			c++;
		}
	}
	return 0;
}