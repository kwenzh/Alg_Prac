/*
题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
*/

//把二叉树按照中序遍历出来 就是升序的 放进数组 直接那kthnode 这样子容易理解
import java.util.*;

public class Solution {
    ArrayList<TreeNode> list = new ArrayList<>();
    TreeNode KthNode(TreeNode pRoot, int k)
    {

		 if(pRoot == null) {
			 return null;
		 }
		 order(pRoot);
		  if(k <= 0 || k > list.size()) {
			 return null;
		 }
		 return list.get(k - 1);
    }
    void order(TreeNode root) {
		 if(root == null) {
			 return;
		 }
		 order(root.left);
		 list.add(root);
		 order(root.right);
	 }


}
