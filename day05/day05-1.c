#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	int snum;
	int score;
	char name[100];
};

int main(void) {
	
	int N;
	//int* snum;
	//int* score;
	//char** name;
	struct student* p;
	printf("총 학생이 몇명인지 입력하시오 : ");
	scanf_s("%d", &N);
	p = (struct student*)malloc(N * sizeof(struct student));

	for (int i = 0; i < N; i++) {
		printf("학번 : ");
		scanf_s("%d", &p[i].snum);
		printf("점수 : ");
		scanf_s("%d", &p[i].score);
		printf("이름 : ");
		scanf_s("%s", p[i].name, 100);
		
	}
    /*
	snum = (int*)malloc(N * sizeof(int));
	score = (int*)malloc(N * sizeof(int));
	name = (char**)malloc(N * sizeof(char*));

	
	for (int i = 0; i < N; i++) {
		name = (char*)malloc(100 * sizeof(char));
		
	}

	for (int i = 0; i < N; i++) {
		printf("학번 : ");
		scanf_s("%d", &snum[i]);
		printf("점수 : ");
		scanf_s("%d", &score[i]);
		printf("이름 : ");
		scanf_s("%s", name[i]);
	}

	int sum = 0;
	float avr;

	for (int i = 0; i < N; i++) {
		sum += score[i];
	}

	avr = (float)sum / (float)N;

	for (int i = 0; i < N; i++) {
		printf("%d, %s, %d", snum[i], name[i], score[i]);
	}

	printf("%.2f", avr);

	free(snum);
	snum = NULL;
	free(score);
	score = NULL;
	free(name);
	name = NULL;
	*/
	for (int i = 0; i < N; i++) {
		printf("%d, %s, %d\n", p[i].snum, p[i].name, p[i].score);
	}

	free(p);
	p = NULL;

	return 0;
}