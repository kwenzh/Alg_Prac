#include<stdio.h>
#include<malloc.h>
#include<math.h>

#include"AVLTree.h"
#include"../../../include/KWENBASE.h"

void destoryAVLTree(AVLTree **root) {
	if(NULL == *root) {
		return;
	}
	destoryAVLTree(&((*root)->left));
	destoryAVLTree(&((*root)->right));
	free(*root);
	*root = NULL;
}

int getHeight(AVLTree *root) {
	return root == NULL ? 0 : (root->height);
}

void setHeight(AVLTree *root, int height) {
	root->height = height;
}

//单旋转-向右旋转进行修正AVL树 也就是所说的左左型
//在根节点的左孩子左子树下面插入一个新节点 会导致根
//       7
//     5   8
//   3  6
// 1
// 插入新节点1的时候，就要进行一次右旋操作
// 改变7->left = 5->right
// 再让5->right = 7成为了新的根节点 5就是新的根节点
//       5
//     3    7
//   1     6  8
void SingleRightRotate(AVLTree **root) {
	AVLNode *xPNode = *root;
	AVLNode *yPNode = (*root)->left;

//第一步根节点的指向 使其指向左孩子的右孩子
	xPNode->left = yPNode->right;
//然后让根节点的左孩子的右指向去指向右孩子 完成一个树的旋转
	yPNode->right = xPNode;
//左孩子原来的成为新的根节点
	*root = yPNode;
//更新旋转后的二叉树的左右高度
	xPNode->height = max(getHeight(xPNode->left), getHeight(xPNode->right)) + 1;
	yPNode->height = max(getHeight(yPNode->left), getHeight(yPNode->right)) + 1;
}

//一次左旋和一次右旋是对称的 理解一次右旋就不难理解 左旋
//       7
//     5   11
//        8   13
//               15
// 插入新节点15的时候
// 改变7->right = 11->left
// 再让11->left = 7成为了新的根节点 11就是新的根节点
//          11
//       7     13
//     5   8     15
void SingleLeftRotate(AVLTree **root) {
	AVLNode *xPNode = *root;
	AVLNode *yPNode = (*root)->right;

	xPNode->right = yPNode->left;
	yPNode->left = xPNode;
	*root = yPNode;				//原来根节点的右孩子成为新的根节点
	xPNode->height = max(getHeight(xPNode->left), getHeight(xPNode->right)) + 1;
	yPNode->height = max(getHeight(yPNode->left), getHeight(yPNode->right)) + 1;
}

//当在根节点的左子树的右子树上插入一个新节点
//需要进行一次双右旋操作使树保持平衡
//         7
//     5       8
//   3   6
//     1
// 例如1插入在3的右子树 先把根节点的左子树进行左旋操作
//    5                 6
//  3    6            5
//    1             3
//                     1
//再对根节点进行一次右旋操作达到平衡
//          6
//       5    7
//     3         8
//       1
//第一次将根节点的左子树进行单左旋操作
//第二次将根节点进行单右旋操作
//
void DoubleRightRotate(AVLTree **root) {
	if((*root)->left == NULL) {
		printf("DoubleRightRotate Error !\n");
		return;
	}

	SingleLeftRotate(&((*root)->left));
	SingleRightRotate(root);
}

//新插入的节点在右子树的左子树上的时候进行双左旋操作
//例如新插入的15在13的左子树上
//       7
//     5   11
//        8   13
//          15
//第一次将根节点的右子树进行右旋操作
//  8
//    11
//       13
//     5
//第二次将根节点进行单左旋操作
//       8
//     7   11
//   5        13
//         15
void DoubleLeftRotate(AVLTree **root) {
	if((*root)->right == NULL) {
		printf("DoubleRightRotate Error !\n");
		return;
	}

	SingleRightRotate(&((*root)->right));
	SingleLeftRotate(root);
}


void insertNode(AVLTree **root, DataType element) {
	if(NULL == *root) {
		(*root) = (AVLNode *)calloc(sizeof(AVLNode), 1);
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root)->height = 1;
		(*root)->element = element;
		return;
	}
//如果待插入的值小于根节点 应该插入值左子树分支直到找到一个叶子节点
	if(element < (*root)->element) {
		insertNode(&((*root)->left), element);
		if(getHeight((*root)->left) - getHeight((*root)->right) > 1) {
		//插入到左子节点的左子树 进行单右旋操作
			if(element < (*root)->left->element) {
				SingleRightRotate(root);
			}
		//插入到左子节点的右子树 进行双右旋转操作
			else {
				DoubleRightRotate(root);
			}
		}
	}
//如果大于根节点的值，继续递归到右子树找到一个叶子节点
	if(element > (*root)->element){
		insertNode(&((*root)->right), element);
		if(getHeight((*root)->right) - getHeight((*root)->left) > 1) {
		//插入到右子节点的右子树 进行单左旋操作
			if(element > (*root)->right->element) {
				SingleLeftRotate(root);
			}
		//插入到右子节点的左子树 进行双左旋操作
			else {
				DoubleLeftRotate(root);
			}
		}
	}

//设置高度的时机在插入完一个节点 并对树已经做了旋转操作之后了
	setHeight(*root, max(getHeight((*root)->right), getHeight((*root)->left)) + 1);
}

void createAVLTree(AVLTree **root, DataType *array, int array_length) {
	int i = 0;

//树非空 说明树已经建立了 不需要再被初始化建立
	if(*root) {
		printf("The AVL tree has been created!\n");
		return;
	}
//传递进来的数组没有数据
	if(!array || array_length == 0) {
		printf("array = NULL  you insert ni ma\n");
		return;
	}

	for(i = 0; i < array_length; i++) {
		insertNode(root, array[i]);
	}
}

//在AVL树中按照目标值查找一个节点 不存在特征值的节点 返回null
AVLNode *searchFromAVLTree(AVLTree *root, const DataType targetValue) {
	if(root == NULL) {
//找完了这棵树也没有找到这样一个节点 那么一定没有
		return NULL;
	}else if(root->element == targetValue) {
		return root;
	}else if(root->element > targetValue) {
//当前节点的值大于特征值 接着递归往节点的左子树找
		return searchFromAVLTree(root->left, targetValue);
	}else {
//当前节点的值不大于特征值 接着递归往节点的右子树找
		return searchFromAVLTree(root->right, targetValue);
	}
}

//主要是在进行删除一个节点之后 对失去平衡的节点的调整 使其仍保持平衡
void repairTree(AVLTree **root) {
//左子树的高度大于右子树的高度
//为啥啊 左边高了不应该向右旋转吗
	if(getHeight((*root)->left) > getHeight((*root)->right)) {
//左子树的左子树 大于 左子树的右子树 高度 执行单左旋操作
		if(getHeight((*root)->left->left) > getHeight((*root)->left->right)) {
			SingleLeftRotate(root);
		}
//左子树的左子树 小于 左子树的右子树 高度 执行双左旋操作
		else if(getHeight((*root)->left->left) < getHeight((*root)->left->right)){
			DoubleLeftRotate(root);
		}
	}
//左子树的高度小于右子树的高度
	else if(getHeight((*root)->left) < getHeight((*root)->right)) {
		if(getHeight((*root)->right->right) > getHeight((*root)->right->left)) {
			SingleRightRotate(root);
		}

		else if(getHeight((*root)->right->right) < getHeight((*root)->right->left)){
			DoubleRightRotate(root);
		}
	}
}

void deleteFromAVLTree(AVLTree **root, const DataType targetValue) {
	AVLNode *temp = NULL;

	if(*root == NULL) {
		printf("element nor found\n");
	}
	else if((*root)->element > targetValue) {
		deleteFromAVLTree(&((*root)->left), targetValue);
	}
	else if((*root)->element < targetValue) {
		deleteFromAVLTree(&((*root)->right), targetValue);
	}
	//要删除的节点左右孩子都有
	else if((*root)->left && (*root)->right) {
		temp = getMinNodeInAVLTree((*root)->right);
		(*root)->element = temp->element;
		deleteFromAVLTree(&((*root)->right), temp->element);
	}
	//删除的节点只有一个孩子
	else {
		temp = *root;
		if((*root)->left == NULL) {
			*root = (*root)->right;
		}else if((*root)->right == NULL) {
			*root = (*root)->left;
		}
//真正删除节点释放空间的代码在这里
		free(temp);
		temp = NULL;
	}
//对删除完的树进行调整 使其仍旧保持平衡
	if((*root) != NULL) {
		(*root)->height = max(getHeight((*root)->left), getHeight((*root)->right)) + 1;
		 if((getHeight((*root)->left) - getHeight((*root)->right) >= 2)
		 || (getHeight((*root)->right) - getHeight((*root)->left) >= 2)) {
           	repairTree(root);
            //修复完成后更新节点高度
            (*root)->height = max(getHeight((*root)->left), getHeight((*root)->right)) + 1;
        }
	}
}

AVLNode *getMaxNodeInAVLTree(AVLTree *root) {
	AVLNode *maxNode = NULL;

	if(root == NULL) {
		return NULL;
	}
	maxNode = root;
	while(maxNode->right) {
		maxNode = maxNode->right;
	}

	return maxNode;
}

AVLNode *getMinNodeInAVLTree(AVLTree *root) {
	AVLNode *minNode;

	if(root == NULL) {
		return NULL;
	}
	minNode = root;
	while(minNode->left) {
		minNode = minNode->left;
	}

	return minNode;
}


void PrintTreeInWinDow(const AVLTree *root) {
	PrintTree(root, 0);
	printf("\nTurn your head 90 degrees by the left and can see tree!\n");
}

void PrintTree(const AVLTree *root, int depth) {
	int i;

	if(root == NULL) {
		return;
	}

	PrintTree(root->right, depth + 1);
	for(i = 0; i < depth; i++) {
		printf("  ");
	}
	printf("%d\n", root->element);
	PrintTree(root->left, depth + 1);

}

void showAVLTree(const AVLTree *root) {
	InorderTree(root);
	printf("\n");
}

void InorderTree(const AVLTree *root) {
	if(root == NULL) {
		return;
	}

	InorderTree(root->left);
	printf("%d ", root->element);
	InorderTree(root->right);
}
