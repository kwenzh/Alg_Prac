/*
题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/

import java.util.ArrayList;

/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/

// 层次遍历 不过就是每一行需要换行了 每一行用一个队列来保存 隔行反向添加
public class Solution {
    public ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
    		ArrayList<TreeNode> quene = new ArrayList<>();

    		if(pRoot == null) {
    			return result;
    		}
    		quene.add(pRoot);
    		while(quene.size() != 0) {
    			ArrayList<Integer> listTemp = new ArrayList<>();
    			int quene_len = quene.size();
    			for(int i = 0; i < quene_len; i++) {
    				TreeNode temp  = quene.remove(0);
    				if(temp.left != null) {
    			       quene.add(temp.left);
    			    }
    				if(temp.right != null) {
    			       quene.add(temp.right);
    			    }

    				listTemp.add(temp.val);
    			}
          result.add(listTemp);
    		}
        // 就笨办法自己翻转
    		reverseList(result);

    		return result;
    }

    public void reverseList(ArrayList<ArrayList<Integer>> result) {
  		int len = result.size();

  		for(int i = 1; i < len; i = i+ 2) {
  			ArrayList<Integer> perList = result.get(i);
  			int length = perList.size();
  			for(int j = 0; j < length / 2; j++) {
  				int temp = perList.get(j);
  				perList.set(j, perList.get(length - j - 1));
  				perList.set(length - j - 1, temp);
  			}
  		}
  	}

}
