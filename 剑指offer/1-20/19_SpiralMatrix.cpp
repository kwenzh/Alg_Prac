/*
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

*/



// 螺旋矩阵的打印
// 1  2  3  4
// 12 13 14 5
// 11 16 15 6
// 10 9  8  7
// 用4个变量确定边界上下左右 然后四个方向打印即可 方向依次是向右 下 左 上
class Solution {
public:

  vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> result;
    int row = matrix.size();
    int col = matrix[0].size();

    if(row == 0 || col == 0) {
      return result;
    }
    int left = 0;
    int up = 0;
    int right = col - 1;
    int down = row - 1;
    int i;

    while(left <= right && up <= down) {
      for(i = left; i <= right; i++) {
      	result.push_back(matrix[up][i]);
      }
      for(i =  up + 1; i <= down; i++) {
      	 result.push_back(matrix[i][right]);
      }

    	for(i = right - 1; i >= left && up != down; i--) {
    		result.push_back(matrix[down][i]);
    	}

    	for(i = down - 1; i > up && left != right; i--) {
    		result.push_back(matrix[i][left]);
    	}

      left++;
      up++;
      right--;
      down--;
    }

    return result;
  }
};
