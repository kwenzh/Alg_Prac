#include<stdio.h>

typedef  char DataType;

void show(void *p);

void show(void *p) {
	DataType *x;

	x = (DataType *)p;

	printf("%c\n", *x);
}

int main(void){
	DataType num = 4;
	void *p = &num;
	DataType *p2 = (DataType *)p;

	show(p);

	printf("%c\n", *p2);
	
	return 0;
}