#include<stdio.h>
#include<malloc.h>
#include<string.h>

#include"../../include/KWENBASE.h"


void swapChar(char *x, char *y);
void ArrangeMent(int n, char *str);
int Fibonacci(int n);
int getSum(int n);

void swapChar(char *x, char *y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}

void ArrangeMent(int n, char* str) {
	int str_length = strlen(str);
	int i;

	if(n >= str_length) {
		puts(str);
	}else {
		for(i = n; i < str_length; i++) {
			 if(i!=n && str[i]==str[n]) {//有重复字符时，跳过
                continue;
            }
			swapChar(str + i, str + n);
			ArrangeMent(n + 1, str);
			swapChar(str + i, str + n);
		}
	}
}


int Fibonacci(int n) {
	  if(n <= 1) {
	  	return 1;
	  }

	  return Fibonacci(n- 1) + Fibonacci(n - 2);
}



int main(void) {
	char *str;
	const int str_length = 10;

	str = (char *)calloc(sizeof(char), str_length);
// linux 下的c编译是不支持这个gets函数 可以用fgets 但是fgets是以\n结束的 这一点要注意
// 还是接着让它warnging把 或者选择scanf
	// gets(str);
	// fgets(str,str_length , stdin);
	scanf("%s", str);
	printf("[%s]\n\n", str);
	ArrangeMent(0, str);

	free(str);

	return 0;
}
