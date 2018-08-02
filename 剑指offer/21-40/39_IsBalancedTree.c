/*
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/


// 求左右子树高度之差判断
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

//判断一棵树是不是平衡二叉树
//定义：平衡二叉搜索树具有以下性质：
//它是一 棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。
bool IsBalanced_Solution(TreeNode* pRoot) {
	if(pRoot == NULL){
		return true;
	}

	int left_high = TreeDepth(pRoot->left);
	int right_high = TreeDepth(pRoot->right);

	return abs(right_high - left_high) <= 1;
}
