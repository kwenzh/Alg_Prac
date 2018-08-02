/*
题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

*/


//这不就是层次遍历的吗 每一层树换行一下
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
public class Solution {
    ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
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

    		return result;
    }

}
