#ifndef _KWEN_ARRAY_TOOL_H
#define _KWEN_ARRAY_TOOL_H

#ifndef _STDIOMALLOC_KWEN_
#define _STDIOMALLOC_KWEN_
#include<malloc.h>
#include<time.h>
#include<stdlib.h>

#include"KWENBASE.h"

#endif

#ifndef _KWEN_GET_ARRAYAND_MATRIX_
#define _KWEN_GET_ARRAYAND_MATRIX_
//得到任何行列的二维整形数据数组
int **getMatrix(int row, int col);

int *getArray(int length);

//得到随机数据
int *createArray(int count, int maxValue, int minValue);

int *createArray(int count, int maxValue, int minValue)  {
	int *result = NULL;
	int index = 0;

	result = (int *)calloc(sizeof(int), count);

	srand(time(NULL));
	for(index = 0; index < count; index++) {
		result[index] = rand()%(maxValue - minValue + 1) + minValue;
	}

	return result;
}

int *getArray(int length) {
	int *array;

	array = (int *)calloc(sizeof(int), length);

	return array;
}

int **getMatrix(int row, int col) {
	int i;
	int j;
	int **array;

	array = (int **)calloc(row, sizeof(int *));
//先为矩阵分配好所有的空间
	*array = (int *)calloc(sizeof(int), row * col);
	for(i = 0; i < row; i++) {
		array[i] = *array + i * col;
	}

	return array;
}
#endif

#ifndef _KWEN_SHOW_ARRAY_AND_MATRIX_
#define _KWEN_SHOW_ARRAY_AND_MATRIX_
//打印一个n阶的方阵
void showMatrix(int *ArrayFirstAddress, int row, int col);

// 打印阶数为row, col矩阵的每个元素地址
void showMatrixAddress(int *MatrixFisrtAddress, int row, int col);

void showArrayAddress(int *ArrayFirstAddress, int length);

// 打印一个长度为array_length的数组
void showArray(int *ArrayFirstAddress, int array_length);

void showMatrix(int *MatrixFisrtAddress, int row, int col) {
	int i;
	int j;

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			printf("%5d", *(MatrixFisrtAddress++));
		}
		printf("\n");
	}
	printf("\n\n");
}

void showArray(int *ArrayFirstAddress, int array_length) {
	int i;

	for(i = 0; i < array_length; i++) {
		// printf("%d ", array[i]);
		printf("%5d", *(ArrayFirstAddress + i));
	}

	printf("\n\n");
}

void showArrayAddress(int *ArrayFirstAddress, int length) {
	int i;

	for(i = 0; i < length; i++) {
		printf("%p ", ArrayFirstAddress++);
	}
	printf("\n\n");
}

void showMatrixAddress(int *MatrixFisrtAddress, int row, int col) {
	int i;
	int j;

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			printf("%p ", MatrixFisrtAddress++);
		}
		printf("\n");
	}
	printf("\n\n");
}
#endif


#ifndef _KWEN_REVERSE_ARRAY_AND_MATRIX_
#define _KWEN_REVERSE_ARRAY_AND_MATRIX_

// 根据传递进来的前后地址翻转数组
void reverseArray(int *beginAddress, int *endAddress);

//翻转矩阵的行 首行和末行翻转
//无论是翻转一个一维数组中的元素还是二维数组中行翻转 要真正意义的去翻转值
//不能将指向地址改变 要改变改地址存放的值交换 才算真正意义上的翻转 交换
void reverseMatrix(int *MatrixFisrtAddress, int row, int col);

void reverseMatrix(int *MatrixFisrtAddress, int row, int col) {
	int i;
	int j;

	for(i = 0; i < row / 2; i++) {
		for(j = 0; j < col; j++) {
			swapData(MatrixFisrtAddress + i * col + j, MatrixFisrtAddress + (row - 1 - i)*col + j );
			// int temp = MatrixFisrtAddress[i * col + j];
			// MatrixFisrtAddress[i * col + j] = MatrixFisrtAddress[(row - 1 - i) * col + j];
			// MatrixFisrtAddress[(row - 1 - i) * col + j] = temp;
		}
	}
}

void reverseArray(int *beginAddress, int *endAddress) {
	int temp;

	for(; beginAddress <= endAddress;  beginAddress++,endAddress--) {
		// temp = endAddress[0];
		// endAddress[0] = beginAddress[0];
		// beginAddress[0] = temp;
		swapData(beginAddress, endAddress);
	}
}
#endif

//转置一个阶数为order的方阵
void transposeArray(int *array, int row);


#ifndef _KWEN_GET_MAX_AND_MIN_ARRAY_
#define _KWEN_GET_MAX_AND_MIN_ARRAY_
//得到数组中最大的元素
int getArrayMaxValue(int *array, int array_length);

//得到数组中第一次出现最小的元素
int getArrayMinValue(int *array, int array_length);


int getArrayMinValue(int *array, int array_length) {
	int i = 1;
	int min = array[0];

	while(i < array_length) {
		min = min > array[i] ? array[i] : min;
		i++;
	}

	return min;
}

int getArrayMaxValue(int *array, int array_length) {
	int i = 1;
	int max = array[0];

	while(i < array_length) {
		max = max < array[i] ? array[i] : max;
		i++;
	}

	return max;
}
#endif


#ifndef _KWEN_DESTROY_MATRIX_AND_ARRAY_
#define _KWEN_DESTROY_MATRIX_AND_ARRAY_
//销毁一个row*col的矩阵
void destoryMatrix(int ***array, int row);

//销毁数组
void destoryArray(int **array);

void destoryMatrix(int ***array, int row) {
	int i;

	for(i = 0; i < row; i++) {
		free((*array)[i]);
		(*array)[i] = NULL;
	}
}

void destoryArray(int **array) {
	if(*array == NULL) {
		return;
	}

	free(*array);
	*array = NULL;   //这是为什么用指向指针的指针的原因所在
}
#endif


#ifndef _KWEN_TRANSPOSE_MATRIX_
#define _KWEN_TRANSPOSE_MATRIX_

//对一个矩阵转置 如果是方阵 转置前后矩阵行列没变化
//如果不是一个方阵 转置使矩阵行列变化
void transposeMatrix(int *MatrixFisrtAddress, int *row, int *col);

void transposeMatrix(int *MatrixFisrtAddress, int *row, int *col) {
	int i;
	int j;

	if(*row == *col) {
		for(i = 0; i < *row; i++) {
			for(j = i + 1; j < *col; j++) {
				swapData(MatrixFisrtAddress + i * (*col) + j, MatrixFisrtAddress + j * (*col) + i);
			}
		}
	}else {
		int *array = (int *)calloc(sizeof(int), (*row) * (*col));
		//先将矩阵中的数据存放到一个数组中去 一次性放到转置后的位置
		//最后将数组中的元素还给矩阵完成转置 并且交换行列值
		for(i = 0; i < *row; i++) {
			for(j = 0; j < *col; j++) {
				array[j * (*row) + i] = MatrixFisrtAddress[i * (*col) + j];
			}
		}

		for(i = 0; i < (*row) * (*col); i++) {
			MatrixFisrtAddress[i] = array[i];
		}
		swapData(row, col);

		free(array);
	}


}
#endif
#endif
