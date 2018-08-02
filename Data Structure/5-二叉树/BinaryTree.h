#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

typedef char USER_TYPE;

typedef struct BinaryTree {
	USER_TYPE data;
	struct BinaryTree *LeftChild;
	struct BinaryTree *RightChild;
}BinaryTree;

//三种遍历方式都是递归实现，对于树这种结构，递归是最合适的 代码量也少
//就是相对非递归理解起来困难
// 先序遍历二叉树 根左右
void PreOrder(BinaryTree *root);
// 中序遍历二叉树 左根右
void InOrder(BinaryTree *root);
// 后序遍历二叉树 左右根
void PostOrder(BinaryTree *root);

// 构造一颗完全二叉树 直接可以通过字符串数组构造 相比构造非完全二叉树要容易的多
void createCompleteBinTree(BinaryTree **root, char *str, int index);
//解析指定格式的字符串去构造二叉树
void createBinTree(BinaryTree **root, char *strBinTree, int *index);
//销毁一颗二叉树 递归实现的是 销毁的顺序是后序销毁
//从二叉树的下面开始向上销毁 如果采取先序销毁就需要额外保存当前根节点 销毁根节点 递归到孩子节点
//就如同链表一样 先保存起来指向下一个节点的指针，再销毁该指针，继续向后销毁
void destory(BinaryTree **root);

//打印叶子节点
void StatisticalLeftCount(BinaryTree *root);
//统计二叉树叶子节点的数量
int getLeaveCount(BinaryTree *root);
//计算一颗二叉树的高度
int PostTreeDepth(BinaryTree *root);

//近似树的形状打印二叉树9
void PrintTreeInWinDow(BinaryTree *root, int depth);
void PrintTree(BinaryTree *root, int depth);



//访问一个节点信息 说白了就是打印
void Visit(USER_TYPE data);

#endif
