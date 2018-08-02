/*
题目描述
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/


//就是递归遍历 左右子树
int TreeDepth(TreeNode* pRoot)
{
  int h_left;
  int h_right;

  if(pRoot == NULL) {
    return 0;
  }else {
    h_left = TreeDepth(pRoot->left);
    h_right = TreeDepth(pRoot->right);

    return (h_left > h_right ? h_left : h_right) + 1;
  }
}
