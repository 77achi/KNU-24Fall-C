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
		printf("��ǰ ������ �Է��ϼ���. (�Է� �ߴ��� ID�� 0 �Է�)\n");
		printf("��ǰ ID : ");
		scanf_s("%d", &pr[i].id);
		if (pr[i].id == 0)
			break;
		printf("��ǰ�� : ");
		scanf_s("%s", pr[i].name, sizeof(pr->name));
		printf("���� : ");
		scanf_s("%d", &pr[i].prc);
		printf("\n");
		num++;
	}

	printProduct(num, pr);

	return 0;
}

int printProduct(int num, struct Product* op) {
	printf("\n<<�Էµ� ��ǰ ���>>\n");
	for (int i = 0; i < num; i++) {
		printf("\n");
		printf("��ǰ ID : %d\n", op[i].id);
		printf("��ǰ�� : %s\n", op[i].name);
		printf("���� : %d\n", op[i].prc);
	}
}