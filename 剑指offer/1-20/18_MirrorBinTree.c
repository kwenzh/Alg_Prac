/*
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:

二叉树的镜像定义：源二叉树
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
*/

// 递归左右　交换
// 类似后序遍历的方式
void Mirror(TreeNode *pRoot) {
  if(pRoot == NULL) {
    return;
  }

  Mirror(pRoot->left);
  Mirror(pRoot->right);

  TreeNode *temp = pRoot->left;
  pRoot->left = pRoot->right;
  pRoot->right = temp;
}
