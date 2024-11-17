#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum rank {
	r1 = 1, r2 = 2, r3 = 3, r4 = 4, r5 = 5
};

struct Customer {

	char* customerName;
	enum rank rank;
	int order_amount;
	int point;
	struct Customer* prev;
	struct Customer* next;

};

struct Customer* head = NULL;

struct Customer* create_customer(int rank, int point, int order_amount, char* customerName)
{
	struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
	new_customer->rank = (enum rank)rank;
	new_customer->customerName = (char*)malloc(sizeof(customerName));
	strcpy_s(new_customer->customerName, strlen(customerName) + 1, customerName);
	new_customer->order_amount = order_amount;
	new_customer->point = point;
	new_customer->next = NULL;
	new_customer->prev = NULL;

	return new_customer;
};

struct Customer* find_customers(int rank, int point, int order_amount) {
	struct Customer* prev = head;
	struct Customer* cur = head->next;
	if (cur == NULL)
		return head;

	while (cur != NULL) {
		if (cur->rank <= rank && cur->point > point && cur->order_amount > order_amount) {
			if (cur->next == NULL)
				return cur;
			prev = cur;
			cur = cur->next;
		}
		else {
			return prev;
		}
	}
}

void insert_customer_priority(struct Customer* new_customer) {
	struct Customer* n = find_customers(new_customer->rank, new_customer->point, new_customer->order_amount);
	if(n->next != NULL) {
		new_customer->next = n->next;
		n->next->prev = new_customer;
	}
	n->next = new_customer;
	new_customer->prev = n;
}

void print_customers() {
	struct Customer* cur = head->next;
	for (int i = 0; i < 27; i++) {
		printf("-");
	}
	printf("\n");
	while (cur != NULL) {
		printf("%s\t:\t%d랭크\t%d개\t%d포인트\n", cur->customerName, cur->rank, cur->order_amount, cur->point);
		cur = cur->next;
	}
	for (int i = 0; i < 27; i++) {
		printf("-");
	}
	printf("\n");
}

int delete_customer(char* customerName) {
	struct Customer* prev = head;
	struct Customer* cur = head->next;
	while (cur != NULL) {
		if (strcmp(cur->customerName, customerName) == 0) {
			prev->next = cur->next;
			free(cur->customerName);
			free(cur);
			return 1;
		}

		prev = cur;
		cur = cur->next;
	}
	return 0;
}

int change_customer(char* customerName) {
	char* changeName = NULL;
	int rank = 0, point = 0, order_amount = 0;
	struct Customer* prev = head;
	struct Customer* cur = head->next;
	while (cur != NULL) {
		if (strcmp(cur->customerName, customerName) == 0) {
			changeName = customerName;
			rank = cur->rank;
			point = cur->point;
			order_amount = cur->order_amount;
		}
		prev = cur;
		cur = cur->next;
	}
	delete_customer(customerName);
	int num, i = 1;
	while (i) {
		for (int i = 0; i < 27; i++) {
			printf("-");
		}
		printf("\n1. 이름 수정\n");
		printf("2. 랭크 수정\n");
		printf("3. 전체 주문량 수정\n");
		printf("4. 포인트 수정\n");
		printf("번호 입력 : ");
		scanf_s("%d", &num);

		switch (num)
		{
		case 1:
			printf("수정할 이름을 입력 : ");
			scanf_s("%s", changeName, 100);
			i = 0;
			break;
		case 2:
			printf("%s님의 수정할 등급 : ", customerName);
			scanf_s("%d", &rank);
			i = 0;
			break;
		case 3:
			printf("%s님의 수정할 전체 주문량 : ", customerName);
			scanf_s("%d", &order_amount);
			i = 0;
			break;
		case 4:
			printf("%s님의 수정할 포인트 : ", customerName);
			scanf_s("%d", &point);
			i = 0;
			break;
		default:
			printf("잘 못된 번호입니다.\n");
			break;
		}
	}

	insert_customer_priority(create_customer(rank, point, order_amount, changeName));
	return 0;
}

int main() {
	head = (struct Customer*)malloc(sizeof(struct Customer));
	head->next = NULL;

	char customerName[100];
	int rank, point, order_amount;
	int num, i = 1;
	while (i) {
		printf("1. 고객 추가\n");
		printf("2. 고객 정보 제거\n");
		printf("3. 고객 정보 수정\n");
		printf("4. 프로그램 종료\n");
		printf("번호 입력 : ");
		scanf_s("%d", &num);

		switch (num)
		{
		case 1:
			printf("고객님 이름 : ");
			scanf_s("%s", customerName, 100);
			printf("%s님의 등급 : ", customerName);
			scanf_s("%d", &rank);
			printf("%s님의 전체 주문량 : ", customerName);
			scanf_s("%d", &order_amount);
			printf("%s님의 포인트 : ", customerName);
			scanf_s("%d", &point);
			insert_customer_priority(create_customer(rank, point, order_amount, customerName));
			break;
		case 2:
			printf("삭제 할 고객 : ");
			scanf_s("%s", customerName, 100);
			delete_customer(customerName);
			break;
		case 3:
			printf("수정 할 고객 : ");
			scanf_s("%s", customerName, 100);
			change_customer(customerName);
			break;
		case 4:
			printf("프로그램을 종료합니다.\n");
			i = 0;
			break;
		default:
			printf("잘 못된 입력입니다.\n");
			break;
		}

		print_customers();
	}

	return 0;
}