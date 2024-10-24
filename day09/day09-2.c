#include<stdio.h>
#include<stdlib.h>

struct Product {
	int id;
	char name[10];
	int prc;
};

int printProduct(int num, struct Product * op);

int main(void) {
	int num = 0;

	struct Product pr[5];

	for (int i = 0; i < 5; i++) {
		printf("상품 정보를 입력하세요. (입력 중단은 ID에 0 입력)\n");
		printf("상품 ID : ");
		scanf_s("%d", &pr[i].id);
		if (pr[i].id == 0)
			break;
		printf("상품명 : ");
		scanf_s("%s", pr[i].name, sizeof(pr->name));
		printf("가격 : ");
		scanf_s("%d", &pr[i].prc);
		printf("\n");
		num++;
	}

	printProduct(num, pr);

	return 0;
}

int printProduct(int num, struct Product* op) {
	printf("\n<<입력된 상품 목록>>\n");
	for (int i = 0; i < num; i++) {
		printf("\n");
		printf("상품 ID : %d\n", op[i].id);
		printf("상품명 : %s\n", op[i].name);
		printf("가격 : %d\n", op[i].prc);
	}
}