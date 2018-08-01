/*
题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数
判断数组中是否含有该整数。

*/

// 对每一行都进行二分查找 这是java中有自带的二分查找
public class Solution {
    private static int BinarySearch(int array[], int target) {
		int fromIndex = 0;
		int toIndex = array.length - 1;

		while(fromIndex <= toIndex) {
			int mid = (fromIndex + toIndex) >>> 1;
			int midValue = array[mid];

			if(midValue > target) {
				toIndex = mid -1;
			}else if(midValue < target) {
				fromIndex = mid + 1;
			}else {
				return mid;
			}
		}

		return -1;
	}

    public boolean Find(int target, int [][] array) {
      int row = array.length;

		for(int i = 0; i < row; i++) {
			if(BinarySearch(array[i], target) >= 0) {
				return true;
			}
		}

		return false;
    }
}
