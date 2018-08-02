#include<stdio.h>

#include"../../include/kwenarraytools.h"

int Fibonacci(int n);
void writeToArray(int **array, int num);

//给一个n阶的矩阵赋值对角线上元素为x，其余地方均为y
//达到矩阵中每一个元素不得被二次赋值 
void creatMatrix(int **array, int n, int x, int y);

void creatMatrix(int **array, int n, int x, int y) {
  int i;
  int j;

  for(i = 0; i < n; i++) {
    for(j = 0; j < i; j++) {
      array[i][j] = y;
    }
    array[i][i] = x;
    for(j = i + 1; j < n; j++) {
      array[i][j] = y;
    }
  }
}


void writeToArray(int **array, int num) {
  int i;

  *array = (int *)calloc(sizeof(int), num);
  for(i = 0; i < num; i++) {
    (*array)[i] = Fibonacci(i);
  }
}

int Fibonacci(int n) {
  int sum;
  if(n <= 1) {
    return 1;
  }

  return Fibonacci(n-1) + Fibonacci(n-2);
}

int main(void) {
  int num = 10;
  int **array_2;
  int x = 1;
  int y = 0;
  int array_length = 10;
  int array[] = {1,2,5,3,5,1,6,5,2};

  showArray_1(array, array_length);
  array_2 = getSquareMatrix(num);
  creatMatrix(array_2, num, x, y);
  showMatrix(array_2, num);
  showArray_2(array_2, num, num);

  destoryMatrix(&array_2, 10);


  return 0;
}
