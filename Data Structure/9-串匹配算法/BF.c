#include<stdio.h>
#include<string.h>

//暴力匹配方法  时间复杂度o(n^2)  (libraryStr_len - subStr_len) * subStr_len次数
int BF_StrMatching(char *libraryStr, char *subStr);

int BF_StrMatching(char *libraryStr, char *subStr) {
	size_t i;
	size_t j;
	size_t libraryStr_len = strlen(libraryStr);
	size_t subStr_len = strlen(subStr);

	for(i = 0; i <= (libraryStr_len- subStr_len); i++) {

		for(j = 0; subStr[j] && libraryStr[i+j] == subStr[j]; j++) {
		}

		if(j == subStr_len) {
			return i;
		}
	}
	return -1;
}

int main(void) {
	char *libraryStr = "BABCBABCABCAABCABCACABC";
	char *subStr = "ABCABCACAB";

	int matchedIndex = BF_StrMatching(libraryStr, subStr);

	printf("matchedIndex = %d\n", matchedIndex);
	printf("libraryStr_len = %zu, subStr_len = %zu\n", strlen(libraryStr), strlen(subStr));

	puts(libraryStr);
	while(matchedIndex-- > 0) {
		putchar(' ');
	}
	puts(subStr);


	return 0;
}
