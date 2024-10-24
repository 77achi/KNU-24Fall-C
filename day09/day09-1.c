#include<stdio.h>

struct Vector {
	int x;
	int y;
	int z;
};

int main(void) {
	struct Vector vec1;
	struct Vector vec2;

	printf("첫 번째 벡터(x, y, z) : ");
	scanf_s("%d, %d, %d", &vec1.x, &vec1.y, &vec1.z);

	printf("두 번째 벡터(x, y, z) : ");
	scanf_s("%d, %d, %d", &vec2.x, &vec2.y, &vec2.z);

	printf("입력된 첫 번째 벡터\t%d,\t%d,\t%d\n", vec1.x, vec1.y, vec1.z);
	printf("입력된 두 번째 벡터\t%d,\t%d,\t%d\n\n", vec2.x, vec2.y, vec2.z);

	for (int i = 0; i < 35; i++)
		printf("-");
	printf("\n1. 벡터의 합\n");
	printf("2. 벡터의 차\n");
	printf("3. 벡터의 내적\n");
	printf("4. 벡터의 외적\n");
	printf("5. 종료\n");
	for (int i = 0; i < 35; i++)
		printf("-");

	while (1) {
		int n = 0;
		printf("\n명령 입력 : ");
		scanf_s("%d", &n);

		switch (n) {
		case 1: {
			printf("벡터의 합은 v1 + v2 = ( %d, %d, %d)\n", vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
			break;
		}

		case 2: {
			printf("벡터의 차는 v1 - v2 = ( %d, %d, %d)\n", vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
			break;
		}

		case 3: {
			printf("벡터의 내적은 v1 * v2 = %d\n", vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
			break;
		}

		case 4: {
			printf("벡터의 외적은 v1 x v2 = ( %d, %d, %d)\n", 
				(vec1.y * vec2.z) - (vec1.z * vec2.y), (vec1.z * vec2.x) - (vec1.x * vec2.z), (vec1.x * vec2.y) - (vec1.y * vec2.x));
			break;
		}

		case 5: {
			printf("프로그램을 종료합니다.\n");
			for (int i = 0; i < 35; i++)
				printf("-");
			return 0;
		}

		default: {
			printf("잘 못 된 명령입니다.\n");
			printf("다시 입력해주세요.\n");
			break;
		}
		}
		for (int i = 0; i < 35; i++)
			printf("-");
	}
}