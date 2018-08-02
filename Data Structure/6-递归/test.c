#include<stdio.h>

#define MAX_N	100

int array[MAX_N][3] = {0};

int main(void) {
	int a;
	int b;
	int i;
	int N;
	int c;

	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d%d%d", &a, &b, &c);
		array[i][0] = a;
		array[i][1] = b;
		array[i][2] = c;
	}

	


	return 0;
}