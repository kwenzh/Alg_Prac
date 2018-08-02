#include<stdio.h>

#include"SparseMatrix.h"

int main(void) {
	TSMATRIX *tsMatrix = NULL;
	TSMATRIX *transposeMatrix = NULL;
	int matrix_col;
	int matrix_row;
	int num_count;

	printf("input row col and num_count: ");
	scanf("%d%d%d", &matrix_row, &matrix_col, &num_count);

	initSparseMatrix(&tsMatrix, matrix_row, matrix_col, num_count);
	insertDataToMatrix(tsMatrix);
	showSparseMatrix(tsMatrix);
	transposeMatrix = transposeSparseMatrix_3(tsMatrix);
	showSparseMatrix(transposeMatrix);

	destorySparseMatrix(&tsMatrix);
	destorySparseMatrix(&transposeMatrix);

	return 0;
}
/*
4 5 9
0 0 1
0 2 3
0 3 4
1 1 2
1 3 1
2 2 3
2 4 1
3 1 1
3 3 1

3 5 5
0 1 14
0 4 -5
1 1 -7
2 0 36
2 3 28
*/