/*
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

*/


/*
将一个二叉搜索树转化为有序的链表，搜索树的中序遍历是升序。二叉树本身就是一个二叉链表，
将一个二叉树转化为链表主要难点在如何改变孩子和根节点的指向关系，并且将整个树串起来。

这个二叉搜索树最右边的孩子一定是最大值，最左的孩子一定是最小的孩子，这里的算法链表的时候是从大往小链接的。

进行递归，递归到最右边的的孩子，这个节点就是链表的第一个节点，递归往上返回，链接的时候最后更新链表头结点。
*/
TreeNode *resultList = NULL;

TreeNode* Convert(TreeNode* pRootOfTree)
{
	if(!pRootOfTree) {
		return NULL;
	}
	Convert(pRootOfTree->right);
	if(!resultList) {
		resultList = pRootOfTree;
	}else {
		resultList->left = pRootOfTree;
		pRootOfTree->right = resultList;
		resultList = pRootOfTree;
	}
	Convert(pRootOfTree->left);

	return resultList;
}
