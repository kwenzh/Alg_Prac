/*
一个工具头文件
*/

#ifndef _KWEN_BASE_H_
#define _KWEN_BASE_H_


#define true	1
#define false	0
#define ture 	1
#define TRUE 	1

#define FALSE 	0

#define flase 	0

#define ERROR	-1

#define mian 	main

typedef char* string;

typedef unsigned char boolean;

#ifndef _SWAP_DATA_INT_
#define _SWAP_DATA_INT_
// 交换x，y的值
void swapData(int *, int *);

void swapData(int *x, int *y) {
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

#endif

#define max(a,b) ((a)>(b)?(a):(b))

#define min(a,b) ((a)>(b)?(b):(a))

#define max3Num(a,b,c) (((a)>(b)?(a):(b)) > (c) ? ((a)>(b)?(a):(b)) : (c))

#define min3Num(a,b,c) (((a)>(b)?(b):(a)) < (c) ? ((a)>(b)?(b):(a)) : (c))

#ifndef _COUNTING_BITS_COUNTS_
#define _COUNTING_BITS_COUNTS_

int NumberCountsOf1(int n);

int  NumberCountsOf1(int n) {
	if(n == 0) {
		return 0;
	}else if(n < 0) {
		return 32 - NumberCountsOf1(-1 * n - 1);
	}else {
		int count = 0;
		while(n != 0) {
			count++;
			n = (n - 1) & n;
		}

		return count;
	}
}

#endif

#endif
