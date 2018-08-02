/*
题目描述
请实现两个函数，分别用来序列化和反序列化二叉树
*/

// 就是将二叉树解析成固定格式的字符串 可以根据字符串来构造二叉树 通过设置标志符来确定哪些是叶子节点
//你也可以用(, )这样子来构造 解析字符串
public class Solution {
    String Serialize(TreeNode root) {
		 StringBuffer str_bf = new StringBuffer();
		 if(root == null) {
			 str_bf.append("#,");
			 return str_bf.toString();
		 }

		 str_bf.append("" + root.val + ",");
		 str_bf.append(Serialize(root.left));
		 str_bf.append(Serialize(root.right));

		 return  str_bf.toString();
	 }
	 int index = -1;
	 TreeNode Deserialize(String str) {
	       index++;
	       if(index >= str.length()) {
	    	   return null;
	       }

	       String[] str_ar = str.split(",");
	       TreeNode node = null;
	       if(!str_ar[index].equals("#")) {
	    	   node = new TreeNode(Integer.valueOf(str_ar[index]));
	    	   node.left = Deserialize(str);
	    	   node.right = Deserialize(str);
	       }

	       return node;
	 }
}
