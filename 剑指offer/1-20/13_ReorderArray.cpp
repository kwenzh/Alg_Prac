/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/


// 先把奇数挑出来 放好 再放偶数  需要额外的空间
void reOrderArray(vector<int> &array) {
  int size = array.size();
  int *temp = (int *)calloc(sizeof(int), size);
  int i;
  int index = 0;

  for(i = 0; i < size; i++) {
  	if(array[i] & 1) {
  		temp[index++] = array[i];
  	}
  }
  for(i = 0; i < size; i++) {
  	if((array[i] & 1) == 0) {
  		temp[index++] = array[i];
  	}
  }

  for(i = 0; i < size; i++) {
  	array[i] = temp[i];
  }
  free(temp);
}
