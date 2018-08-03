#include<stdio.h>

#include"KWENSTACK.h"

int main(void) {
	STACK_KWEN *stack = NULL;

	initializeStack(&stack, 10);

	printf("%d\n",push(stack, 2));
	printf("%d\n", push(stack, 3));
	printf("%d\n", push(stack, 4));

	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));

	destoryStack(&stack);

	return 0;
}
