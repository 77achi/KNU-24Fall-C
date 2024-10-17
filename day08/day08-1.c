#include<stdio.h>
#include<string.h>

void rev(char* k);

int main(void) {
	char a[100];
	
	printf("문자열을 입력하세요 : ");
	scanf_s("%s", a, sizeof(a));

	rev(a);

	printf("뒤집어진 문자열 : %s", a);
	
	return 0;
}

void rev(char* k) {

	char c;
	char* f1 = k;
	size_t len = strlen(k);
	char* la = k + len - 1;


	while (f1 < la) {
		c = *f1;
		*f1 = *la;
		*la = c;

		f1++;
		la--;
	}
}