#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE {
	char name[100];
	int score;
	struct NODE* link;
};

struct NODE* head = NULL;

struct NODE* create_node(int score, char *name)
{
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy_s(new_node->name, 100, name);
	new_node->score = score;
	new_node->link = NULL;

	return new_node;
};

struct NODE* find_nodes(int score) {
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	if (cur == NULL)
		return head;

	while (cur != NULL) {
		if (cur->score > score) {
			if (cur->link == NULL)
				return cur;
			prev = cur;
			cur = cur->link;
		}
		else {
			return prev;
		}
	}
}

void insert_node_priority(struct NODE* new_node) {
	struct NODE* n = find_nodes(new_node->score);
	new_node->link = n->link;
	n->link = new_node;
}

void print_nodes() {
	struct NODE* cur = head->link;
	for (int i = 0; i < 27; i++) {
		printf("-");
	}
	printf("\n");
	while (cur != NULL) {
		printf("%s\t:\t%d\n",cur->name, cur->score);
		cur = cur->link;
	}
	for (int i = 0; i < 27; i++) {
		printf("-");
	}
	printf("\n");
}

int delete_node(char* name) {
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	while (cur != NULL) {
		if (strcmp(cur->name, name) == 0) {
			prev->link = cur->link;
			free(cur);
			return 1;
		}

		prev = cur;
		cur = cur->link;
	}
	return 0;
}

int main() {
	head = (struct NODE*)malloc(sizeof(struct NODE));
	head->link = NULL;
	
	char name[100];
	int score;
	int num, i = 1;
	while (i) {
		printf("1. 학생의 성적을 입력\n");
		printf("2. 학생 정보 제거\n");
		printf("3. 프로그램 종료\n");
		printf("번호 입력 : ");
		scanf_s("%d", &num);

		switch (num)
		{
		case 1:
			printf("학생 이름 : ");
			scanf_s("%s", name, 100);
			printf("%s의 성적 : ", name);
			scanf_s("%d", &score);
			insert_node_priority(create_node(score, name));
			break;
		case 2:
			printf("삭제 할 학생 : ");
			scanf_s("%s", name, 100);
			delete_node(name);
			break;
		case 3:
			printf("프로그램을 종료합니다.\n");
			i = 0;
			break;
		default:
			printf("잘 못된 입력입니다.\n");
			break;
		}

		print_nodes();
	}

	return 0;
}