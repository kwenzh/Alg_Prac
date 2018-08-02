/*
题目描述
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)

*/


import java.util.ArrayList;

// 递归左右路径 用数组记录和值 有一点笨办法的做法
public class Solution {
   ArrayList<ArrayList<Integer>> resultList = new ArrayList<>();

	public ArrayList<ArrayList<Integer>> FindPath(TreeNode root,int target) {
		int array[] = new int[100];

		printPaths(root, array, 0, target);

		return resultList;
	}

	private void printPaths(TreeNode node, int[] path, int pathLen, int target) {
	    if (node == null) return;
	        path[pathLen++] = node.val;

	    if (node.left == null && node.right == null) {
	    	  //到这里就已经是一个路径了 判断一下这个之和是不是为目标值
	        if(designSum(path, pathLen, target)) {
	        	toList(path, pathLen);
	        }
	    }
	    else {
	        printPaths(node.left, path, pathLen, target);
	        printPaths(node.right, path, pathLen, target);
	    }
	}

	private boolean designSum(int[] array,int len, int targetSum) {
		int sum = 0;

		for(int i = 0; i < len; i++) {
			sum = sum + array[i];
		}

		return sum == targetSum;
	}

	private void toList(int[] array, int len) {
		ArrayList<Integer> list = new ArrayList<>();

		for(int i = 0; i < len; i++) {
			list.add(array[i]);
		}
		resultList.add(list);
	}
}
