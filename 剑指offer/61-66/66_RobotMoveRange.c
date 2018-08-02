/*
题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

//还是递归 将递归终止返回的条件要考虑仔细
int movingCount(int threshold, int rows, int cols)
{
  // 这里完了要释放内存 不要学我这样子 不是在自己电脑跑的
  int **hasVisited = (int **)calloc(sizeof(int*), rows);

  for(int i = 0; i < rows; i++) {
    hasVisited[i] = (int *)calloc(sizeof(int), cols);
  }

  return traverse(threshold, rows, cols, 0, 0, hasVisited);
}

//核心递归部分
int traverse(int threshold, int row, int col, int x, int y, int **hasVisited) {
//所有的终止递归返回条件
  if(x < 0 || x >= row || y < 0 || y >= col ||
  hasVisited[x][y] == 1 || designSum(x, y) > threshold) {

    return 0;
  }

  hasVisited[x][y] = 1;

//这里和计算二叉树深度相似 将各个方向所到达的单元格求和
  return traverse(threshold, row, col, x - 1, y, hasVisited) +
  		traverse(threshold, row, col, x + 1, y, hasVisited) +
  		traverse(threshold, row, col, x, y - 1, hasVisited) +
  		traverse(threshold, row, col, x, y + 1, hasVisited) + 1;
  }

//计算行列坐标之和
int designSum(int x, int y) {
	int sum = 0;

	while(x != 0) {
		sum  = sum + x % 10;
		x = x / 10;
	}

	while(y != 0) {
		sum = sum + y % 10;
		y = y / 10;
	}

	return sum;
}
