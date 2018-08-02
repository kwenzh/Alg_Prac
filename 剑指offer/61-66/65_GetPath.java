/*
题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，
向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，
则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/


//考察回溯法
// 题目要求起点可以是任意一个位置开始 移动是可以向四个方向的 循环加四个方向的递归
// 同时需要一个标记数组 记录走过的路径 在图中的递归 这样的数字是不可或缺的
public class Solution {
    int row;
	  int col;
	  public boolean hasPath(char[] matrix, int rows, int cols, char[] str)
	  {
		  boolean hasVistied[] = new boolean[matrix.length];
		  this.row = rows;
		  this.col = cols;
      //可以从任何一个点出发
		  for(int i = 0; i < rows; i++) {
			  for(int j = 0; j < cols; j++) {
				  if(traverse(matrix, i, j, 0, str, hasVistied)) {
					  return true;
				  }
			  }
		  }

		  return false;
	  }
	  /**
	   *
	   * @param matrix 字符矩阵
	   * @param x 当前矩阵中横坐标位置
	   * @param y 看上一行
	   * @param k 记录str下标位置
	   * @param str
	   * @return
	   */
	  private boolean traverse(char[] matrix, int x,  int y, int k, char[] str, boolean[] hasVistied) {
		 int index = x * this.col + y;
		 if(x < 0 || x >= this.row ||  y < 0 || y >= this.col || matrix[index] != str[k] || hasVistied[index] ==  true) {
			 return false;
		 }
		 if(k ==  str.length - 1) {
			 return true;
		 }
		 hasVistied[index] = true;
     //只要走法中有一个 可以找到路径 就说明存在
		 if(traverse(matrix, x - 1, y, k + 1, str, hasVistied) ||
			traverse(matrix, x + 1, y, k + 1, str, hasVistied) ||
			traverse(matrix, x, y - 1, k + 1, str, hasVistied) ||
			traverse(matrix, x, y + 1, k + 1, str, hasVistied)) {
			 return true;
		 }
		 hasVistied[index] = false;

		 return false;
	  }
}
