#include<stdio.h>

int main() {
	FILE* fp = NULL;
	
	fopen_s(&fp, "data.txt", "wt");

	fprintf("%d, %d, %d\n", 100, 200, 300);
	fprintf("%d, %d, %d\n", 400, 500, 600);

	fclose(fp);
	return 0;
}