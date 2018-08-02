#include<stdio.h>
#include<string.h>


#define NOT_FOUND	-1

int BM_Matching(char *targetStr, char *PatStr);
int getRemoveDistance(char ch, char *PatStr, int place);

int getRemoveDiatance(char ch, char *PatStr, int place) {
	int i;

	for(i = place; i >= 0; i--) {
		if(ch == PatStr[i]) {
//在左侧有这样一个字符的话计算偏移距离			
			return place - i;
		}
	}
//没有这样一个字符就移动整个字符长度距离
	return strlen(PatStr);
}

int BM_Matching(char *targetStr, char *PatStr) {
	int targetStr_len = strlen(targetStr);
	int PatStr_len = strlen(PatStr);
	int Match_index;
	int j;

	for(Match_index = 0; Match_index <= targetStr_len - PatStr_len; ) {
		for(j = PatStr_len - 1; j >= 0 && targetStr[Match_index + j] == PatStr[j]; j--);
		
		if(j == -1) {
			return Match_index;
		}

		Match_index = Match_index + getRemoveDiatance(targetStr[Match_index + j], PatStr, j);
	}

	return NOT_FOUND;
}

int main(void) {
	char *targetStr = "BABCBABCABCAABCABCACABC";
	char *PatStr = "ABCABCACAB";					//模式串
	int index = 0;

	index = BM_Matching(targetStr, PatStr);

	puts(targetStr);
	while(index-- > 0) {
		printf(" ");
	}
	puts(PatStr);
	

	return 0;
}
// if(index != NOT_FOUND) {
// 		char formatString[80];
		
// 		sprintf(formatString, "%%%ds%%s\n", index);
// 		printf("\n%s\n", targetStr);
// 		printf(formatString, "", PatStr);
// 	} else {
// 		printf("[%s] is not exist [%s]\n", PatStr, targetStr);
// 	}