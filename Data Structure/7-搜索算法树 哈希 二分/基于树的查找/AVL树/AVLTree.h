#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

typedef int DataType;

typedef struct AVLNode{
	int height;
	DataType element;
	struct AVLNode *left;
	struct AVLNode *right;
}AVLTree, AVLNode;

//和构造一颗排序二叉树差不多，给出一个序列，将序列逐个插入到AVL树中去
void createAVLTree(AVLTree **root, DataType *array, int array_length);

//AVL树的销毁，和销毁普通二叉树相同 
void destoryAVLTree(AVLTree **root);

//插入的时候要考虑保持AVL树仍旧平衡
void insertNode(AVLTree **root, DataType element);

//单旋转-向右旋转进行修正AVL树 也就是所说的左左型
void SingleRightRotate(AVLTree **root);

//单旋转 向左旋转进行修正树 也就是所说右右型
void SingleLeftRotate(AVLTree **root);

//需要进行两次旋转 左右型 
//先把根节点root的左孩子左旋转一次，再把根节点右旋一次
void DoubleRightRotate(AVLTree **root);

//需要进行两次旋转 右左型 
//适合左右型堆成的
////先把根节点root的右孩子右旋一次，再把根节点左旋一次
void DoubleLeftRotate(AVLTree **root);

AVLNode *searchFromAVLTree(AVLTree *root, const DataType targetValue);

void deleteFromAVLTree(AVLTree **root, const DataType targetValue);
void repairTree(AVLTree **root);

//得到一个树的最大值 就是最右边的叶子节点
AVLNode *getMaxNodeInAVLTree( AVLTree *root);

//得到一个树的最小值 就是最左边的叶子节点
AVLNode *getMinNodeInAVLTree( AVLTree *root);

//得到二叉树的高度 空的话高度为0
int getHeight(AVLTree *root);
void setHeight(AVLTree *root, int height);

//中序的遍历二叉树 排序树的中序遍历就是升序的输出
//由于是递归的遍历输出 没加换行 就另外再给一函数包围起来
void InorderTree(const AVLTree *root);
void showAVLTree(const AVLTree *root);

void Visit(DataType element) {

}
//按照树的形状打印二叉树 打印出来把头向左偏90度看

void PrintTree(const AVLTree *root, int depth);
void PrintTreeInWinDow(const AVLTree *root);

#endif