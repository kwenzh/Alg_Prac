/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

//递归的判断两个书是否左子树和右子树相同 并且右子树和左子树相同 就是对称的判断
class Solution {
public:
   bool isSymmetrical(TreeNode* pRoot)
  {
  	return isEqual(pRoot, pRoot);
  }
  bool isEqual(TreeNode *left, TreeNode *right) {
  	if(left == NULL && right == NULL) {
  		return  true;
  	}
  	if(left == NULL || right == NULL) {
  		return false;
  	}
      if(left->val != right->val) {
  		return false;
  	}


  	return isEqual(left->left, right->right) && isEqual(left->right, right->left);
  }
};
