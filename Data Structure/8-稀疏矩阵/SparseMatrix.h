#ifndef _SPARSE_MATRIX_H
#define _SPARSE_MATRIX_H

typedef struct  TRIPLE{
	int row;
	int col;
	int value;
}TRIPLE;

typedef struct TSMATRIX {
	TRIPLE *triple;	
	int matrix_row;
	int matrix_col;
	int num_count;    //这个相当于triple数组的长度
}TSMATRIX;

void initSparseMatrix(TSMATRIX **tsMatrix, int matrix_row, int matrix_col, int num_count);
void destorySparseMatrix(TSMATRIX **tsMatrix);
void showSparseMatrix(const TSMATRIX *tsMatrix);
void insertDataToMatrix(TSMATRIX *tsMatrix);
//对一个矩阵进行转置
TSMATRIX *transposeSparseMatrix_1(const TSMATRIX *tsMatrix);

//一次定位转置 较前两种转置降低时间复杂度对一个矩阵进行转置
TSMATRIX *transposeSparseMatrix_3(const TSMATRIX *tsMatrix);

//打印矩阵的三元表
void showThreeTable(const TSMATRIX *tsMatrix);

#endif