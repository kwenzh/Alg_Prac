/*
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/


// 这里先考虑当n为1,2的时候 那么只有n中方法
// 把矩形看做横向2 竖向为n
// 开始铺的时候 2*1的小矩形 可以横着放也可以竖着放
// 所带来的效果是在2*n矩形 竖向消耗1个或者2个
// 那么递归 计算所有的可能求和

int rectCover(int number) {
  if(number <= 2) {
		  return number;
	}

	return rectCover(number - 1) + rectCover(number - 2);
}
