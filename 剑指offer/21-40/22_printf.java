/*
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

*/


import java.util.ArrayList;

//二叉树的层次遍历  用一个队列来保存每一层的节点 然后接着保存这一层节点的所有孩子节点
public class Solution {
    public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
         ArrayList<Integer> result = new ArrayList<>();
        ArrayList<TreeNode> quene = new ArrayList<>();

        if(root ==  null) {
            return result;
        }

        quene.add(root);
        while(quene.size() != 0) {
            TreeNode temp = quene.remove(0);
        	if(temp.left != null) {
        		quene.add(temp.left);

        	}
        	if(temp.right != null) {
        		quene.add(temp.right);
        	}
            result.add(temp.val);
        }

        return result;
    }
}
