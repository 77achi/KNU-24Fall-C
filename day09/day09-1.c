#include<stdio.h>

struct Vector {
	int x;
	int y;
	int z;
};

int pl(struct Vector v1, struct Vector v2);
int mi(struct Vector v1, struct Vector v2);
int in(struct Vector v1, struct Vector v2);
int out(struct Vector v1, struct Vector v2);

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
			pl(vec1, vec2);
			break;
		}

		case 2: {
			mi(vec1, vec2);
			break;
		}

		case 3: {
			in(vec1, vec2);
			break;
		}

		case 4: {
			out(vec1, vec2);
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

int pl(struct Vector v1, struct Vector v2) {
	printf("벡터의 합은 v1 + v2 = ( %d, %d, %d)\n", v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

int mi(struct Vector v1, struct Vector v2) {
	printf("벡터의 차는 v1 - v2 = ( %d, %d, %d)\n", v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

int in(struct Vector v1, struct Vector v2) {
	printf("벡터의 내적은 v1 * v2 = %d\n", v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

int out(struct Vector v1, struct Vector v2) {
	printf("벡터의 외적은 v1 x v2 = ( %d, %d, %d)\n",
		(v1.y * v2.z) - (v1.z * v2.y), (v1.z * v2.x) - (v1.x * v2.z), (v1.x * v2.y) - (v1.y * v2.x));
}