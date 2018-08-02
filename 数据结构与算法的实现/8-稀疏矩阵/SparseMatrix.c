#include<stdio.h>
#include<malloc.h>

#include"SparseMatrix.h"

//一次快速定位转置 总体分三步
//1、先对原三元表中的元素统计 每列有多少个非0元素，也就是转置完B的每行有多少个非0元素
//2、通过第一步计算B矩阵每一行元素在三元表中第几个开始
//3、把三元表A的元素直接放到B的三元表里面去 一次遍历三元表A防止B中去
TSMATRIX *transposeSparseMatrix_3(const TSMATRIX *tsMatrix) {
	int *nums = NULL;
	int *postion = NULL;
	int i;
	TSMATRIX *transposeMatrix = NULL;

//对转转置后的三元表初始化申请空间	
	initSparseMatrix(&transposeMatrix, tsMatrix->matrix_col, tsMatrix->matrix_row, tsMatrix->num_count);
//申请一个记录元素出现位置的矩阵 长度和原稀疏矩阵列保持一致	
	postion = (int *)calloc(sizeof(int), tsMatrix->matrix_col);
	nums = (int *)calloc(sizeof(int), tsMatrix->matrix_col);
	for(i = 0; i < tsMatrix->num_count; i++) {
//遍历原三元表，统计矩阵的每一列有多少个非零元素 
//对于矩阵
//0 14 0 0  -5
//0 -7 0 0   0
//36 0 0 28  0
//每一列包含的元素个数为 1 2 0 1 1		
		nums[tsMatrix->triple[i].col]++;
	}
	for(i = 1, postion[0]= 1; i < tsMatrix->matrix_col; i++) {
//通过上一步计算的矩阵中每一列有多少个非零元素 计算矩阵的每一列元素在三元表出现的位置
//即是1 2 4 4 5	
		postion[i] = nums[i - 1] + postion[i - 1];
	}
	

	for(i = 0; i < tsMatrix->num_count; i++) {
//原三元表当前这一项在转置的三元表中应该出现的位置		
		int index = postion[tsMatrix->triple[i].col];
		transposeMatrix->triple[index - 1].row = tsMatrix->triple[i].col;
		transposeMatrix->triple[index - 1].col = tsMatrix->triple[i].row;
		transposeMatrix->triple[index - 1].value = tsMatrix->triple[i].value;
//该列的一个元素已经有一个放进去 位置往后移一个		
		postion[tsMatrix->triple[i].col]++;    //当前列的开始位置加1
	}

	free(postion);
	free(nums);

	return transposeMatrix;
}

//按照列下标递增的顺序去找tsMatrix->triple[j].col == i
//在三元表里面当前元素的列等于i就找到一个
TSMATRIX *transposeSparseMatrix_1(const TSMATRIX *tsMatrix) {
	int i;
	int j;
	int index = 0;
	TSMATRIX *transposeMatrix = NULL;

	initSparseMatrix(&transposeMatrix, tsMatrix->matrix_col, tsMatrix->matrix_row, tsMatrix->num_count);
	for(i = 0; i < tsMatrix->matrix_col; i++) {
		for(j = 0; j < tsMatrix->num_count; j++) {
			if(tsMatrix->triple[j].col == i) {
				transposeMatrix->triple[index].row = tsMatrix->triple[j].col;
				transposeMatrix->triple[index].col = tsMatrix->triple[j].row;
				transposeMatrix->triple[index++].value = tsMatrix->triple[j].value;
			}	
		}
		if(index >= tsMatrix->num_count) {   //如果发现此时三元表已经填满就可以不用再进行外层循环了
			break;    
		}
	}

	return transposeMatrix;
}

void showThreeTable(const TSMATRIX *tsMatrix) {
	int i;

	for(i = 0; i <tsMatrix->num_count; i++) {
		printf("(%d,%d,%d)\n", 
			tsMatrix->triple[i].row,
			tsMatrix->triple[i].col, 
			tsMatrix->triple[i].value);
	}
}

void showSparseMatrix(const TSMATRIX *tsMatrix) {
	int i;
	int j;
	int index = 0;

	for(i = 0; i < tsMatrix->matrix_row; i++) {
		for(j = 0; j < tsMatrix->matrix_col; j++) {
			if(tsMatrix->triple[index].row == i &&
			 tsMatrix->triple[index].col == j) {
				printf("%3d", tsMatrix->triple[index++].value);
			}else {
				printf("%3d", 0);
			}
		}
		puts("");
	}
	puts("");
}
void insertDataToMatrix(TSMATRIX *tsMatrix)  {
	int i;
	int row;
	int col;
	int value;

	printf("Insert data by row and then col ascending(row, col, value)\n");
	for(i = 0; i < tsMatrix->num_count; i++) {
		printf("[%d/%d] data: ", i+1, tsMatrix->num_count);
		scanf("%d%d%d", &row, &col, &value);
		tsMatrix->triple[i].row = row;
		tsMatrix->triple[i].col = col;
		tsMatrix->triple[i].value = value;
	}
}

void destorySparseMatrix(TSMATRIX **tsMatrix) {
	if(*tsMatrix == NULL) {
		return;
	}

	free((*tsMatrix)->triple);
	free(*tsMatrix);
	*tsMatrix = NULL;
}

void initSparseMatrix(TSMATRIX **tsMatrix, int matrix_row, int matrix_col, int num_count) {
	TSMATRIX *tp;

	if(NULL != (*tsMatrix) || (matrix_row*matrix_col < num_count)
		|| matrix_col <= 0 || matrix_row <= 0) {

		printf("ERROR INPUT DATA\n");
		return;
	}

	tp = (TSMATRIX *)malloc(sizeof(TSMATRIX));

	if(tp != NULL) {  //有没有分配到空间怎么说
		tp->triple = (TRIPLE *)calloc(sizeof(TRIPLE), num_count);
		tp->matrix_row = matrix_row;
		tp->matrix_col = matrix_col;
		tp->num_count = num_count;
		*tsMatrix = tp;
	}
}