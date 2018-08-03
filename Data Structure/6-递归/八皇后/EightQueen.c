#include<stdio.h>

#include"../../include/KWENBASE.h"

#define EIGHT	8

#define EXIST		'1'
#define NO_EXIST	'0'

boolean isSafe(int (*chess)[EIGHT], int row, int col);
void showEightQueen(int (*chess)[EIGHT]);
void EightQueen(int (*chess)[EIGHT], int row);
void writeToFile(int (*chess)[EIGHT], int count);

void writeToFile(int (*chess)[EIGHT], int count) {
	FILE *fp;
	int i;
	int j;

	fp = fopen("EightQueenInput/EightQueenResult.txt","a+");
	fprintf(fp, "The %d solution is :\n", count);
	for(i = 0; i < EIGHT; i++) {
		for(j = 0; j < EIGHT; j++) {
			fprintf(fp, "%d  ", chess[i][j]);
		}
		fprintf(fp, "%s", "\n");
	}
	fprintf(fp, "%s", "\n");
	fclose(fp);
}

void EightQueen(int (*chess)[EIGHT], int row) {
	int col;

	if(row >= EIGHT) {
		showEightQueen(chess);
		return;
	}

	for(col = 0; col < EIGHT; col++) {
		if(isSafe(chess, row, col)) {
			chess[row][col] = 1;
			EightQueen(chess, row + 1);
			chess[row][col] = 0;
		}
	}

}

void showEightQueen(int (*chess)[EIGHT]) {
	int i;
	int j;
	FILE *fp;
	static int count = 0;

	++count;
	printf("The %d solution is :\n", count);
	for(i = 0; i < EIGHT; i++) {
		for(j = 0; j < EIGHT; j++) {
			printf("%d  ", chess[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	writeToFile(chess, count);
}

boolean isSafe(int (*chess)[EIGHT], int row, int col) {
	int i;
	int j;

//The upper left
	for(i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if(chess[i][j]) {
			return false;
		}
	}
//Just above
	for(i = row - 1, j = col; i >= 0; i--) {
		if(chess[i][j]) {
			return false;
		}
	}
//The upper right

	for(i = row - 1, j = col + 1; i >= 0 && j < EIGHT; i--, j++) {
		if(chess[i][j]) {
			return false;
		}
	}

	return true;
}


int main(void) {
	int EIGHTQUEEN[EIGHT][EIGHT] = {0};

	EightQueen(EIGHTQUEEN, 0);

	return 0;
}
