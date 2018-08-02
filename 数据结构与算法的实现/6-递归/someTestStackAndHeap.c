#include<stdio.h>

static int x = 3;

int main(void) {
	int *p;

	p = &x;

	printf("p = %d, x = %d\n", *p, x);
	*p = 2;
	printf("p = %d, x = %d\n", *p, x);
}
/*
char *str = "Hello word!";
	char str2[] = "fujdsifdsig";
	char *str3 = "Hello word!";

	
	printf("str = %s\n", str);
	printf("str2 = %s\n", str2);
	printf("str3 = %s\n", str3);

	str[0] = '4';    //严重的非法内存访问问题 
	str2[0] = 'A';	

	printf("str = %s\n", str);
	printf("str2 = %s\n", str2);
	printf("str3 = %s\n", str3);

	printf("str = %p\n", str);
	printf("str2 = %p\n", str2);
	printf("str3 = %p\n", str3);

	return 0;
void func(char *str) {
	char *str2 = "16555565";

	printf("func_str = %p\n", str);
	printf("str2 = %p\n", str2);
}

int x = 1;
	int y = x;
	int z = 5;
	int z2 = 4;
	int z3 = 5;
	int z4 = 5;
	int z5 = 5;
	char ch = '4';
	static int num = 5;
	char *str= "51626ds";
	
	func(str);	

	printf("int x  = %p\n", &x);
	printf("int y  = %p\n", &y);
	printf("fun_Z  = %p\n", &z);
	printf("int z2 = %p\n", &z2);
	printf("int z3 = %p\n", &z3);
	printf("int z4 = %p\n", &z4);
	printf("int z5 = %p\n", &z5);
	printf("char ch= %p\n", &ch);

	printf("char str = %p\n", str);
	printf("char str = %p\n", &str[0]);
	printf("char str = %p\n", &str[1]);
	printf("char str = %p\n", &str[2]);
	printf("static = %p\n", &num);
	printf("all = %p\n", &all);
	
 */

// char *get() {
// 	char *str = "ds1da62";

// 	return str;
// }

// int main(void) {
// 	char *sr;

// 	sr = get();

// 	puts(sr);
// 	sr[0] = 'A';
// 	puts(sr);

// 	return 0;
// }
// /int array[] = {1,2,3,4};
	// int array_2[] = {5,6,7,8};
	// int i;
	// int *p;

	// p = array;

	// printf("p_address = %p\n", p);
	// printf("p_address = %p\n", p);

	// for(i = 0; i < 10; i++) {
	// 	printf("[%d-%p] ", *p, p);
	// 	p = p + 1;
	// }
	// printf("\n");
	// for(i = 0; i < 4; i++) {
	// 	printf("%p ", &array[i]);
	// }

	// for(i = 0; i < 4; i++) {
	// 	printf("%p ", &array_2[i]);
	// }
	//  */