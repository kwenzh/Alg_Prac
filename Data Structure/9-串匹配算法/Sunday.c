#include<stdio.h>
#include<string.h>

#define NOT_FOUND		-1

int Sunday_Matching(char *targetStr, char *PatStr);
int getRemoveDiatance(char *PatStr, char ch, int length);

int getRemoveDiatance(char *PatStr, char ch, int length) {
	int i;

	for(i = length - 1; i >= 0; i--) {
		if(ch == PatStr[i]) {
			return length - i;
		}
	}

	return length + 1;
}

int Sunday_Matching(char *targetStr, char *PatStr) {
	int matchedIndex = 0;
	int j;
	int targetStr_len = strlen(targetStr);
	int PatStr_len = strlen(PatStr);

	printf("len1 = %d, len2 = %d\n", targetStr_len, PatStr_len);

	while(matchedIndex <= targetStr_len - PatStr_len) {
		for(j = 0; j < PatStr_len && targetStr[matchedIndex + j] == PatStr[j]; j++);
		if(j == PatStr_len) {
			return matchedIndex;
		}

		matchedIndex += getRemoveDiatance(PatStr, targetStr[matchedIndex + PatStr_len], PatStr_len);
	}

	return NOT_FOUND;

}

int main(void) {
	char *targetStr = "BABCBABCABCAABCABCACABC";
	char *PatStr = "ABCABCACAB";					//模式串
	int index = 0;

	puts(targetStr);
	index = Sunday_Matching(targetStr, PatStr);
	if(index != NOT_FOUND) {
		while(index-- > 0) {
			printf(" ");
		}
		puts(PatStr);
	}else {
		printf("[%s] in [%s] not found\n", PatStr, targetStr);
	}
	
	

	return 0;
}