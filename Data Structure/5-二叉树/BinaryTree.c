#include<stdio.h>
#include<malloc.h>
#include<string.h>

#include"BinaryTree.h"


void PrintTreeInWinDow(BinaryTree *root, int depth) {
	PrintTree(root, depth);
	printf("\nTurn your head 90 degrees t4i8kto the left and can see tree!\n");
}

void PrintTree(BinaryTree *root, int depth) {
	int i;

	if(root == NULL) {
		return;
	}

	PrintTree(root->RightChild, depth + 1);
	for(i = 0; i < depth; i++) {
		printf("  ");
	}
	printf("%c\n", root->data);
	PrintTree(root->LeftChild, depth + 1);

}

int getLeaveCount(BinaryTree *root) {
	int left_count;
	int right_count;

	if(root == NULL) {
		return 0;
	}
	if(root->LeftChild == NULL && root->RightChild == NULL) {
		return 1;
	}
	left_count = getLeaveCount(root->LeftChild);
	right_count = getLeaveCount(root->RightChild);

	return left_count + right_count;
}

void StatisticalLeftCount(BinaryTree *root) {
	if(root == NULL) {
		return;
	}

	if(root->LeftChild == NULL && root->RightChild == NULL) {
		Visit(root->data);
	}
	StatisticalLeftCount(root->LeftChild);
	StatisticalLeftCount(root->RightChild);
}

//递归求二叉树的高度
int PostTreeDepth(BinaryTree *root) {
	int h_left;
	int h_right;

	if(root == NULL) {
		return 0;
	}else {
		h_left = PostTreeDepth(root->LeftChild);
		h_right = PostTreeDepth(root->RightChild);

		return (h_left > h_right ? h_left : h_right) + 1;
	}
}

void Visit(USER_TYPE data) {
	printf("%c ", data);
}

//A(B(*C(**))D(E(**)F(**)))
void createBinTree(BinaryTree **root, char *strBinTree, int *index) {
	while(')' == strBinTree[*index] || strBinTree[*index] == '(') {
		(*index)++;
	}
	if('*' == strBinTree[*index] || (*index) >= strlen(strBinTree)) {
		*root = NULL;
		(*index)++;
		return;
	}

	*root = (BinaryTree *)calloc(sizeof(BinaryTree), 1);
	(*root)->data = strBinTree[(*index)++];

	createBinTree(&((*root)->LeftChild), strBinTree, index);
	createBinTree(&((*root)->RightChild), strBinTree, index);
}

//完全二叉树的构造 把传递进来的字符串看成堆来构造二叉树
//ABCDEFG
void createCompleteBinTree(BinaryTree **root, char *str, int index) {
	if(index >= strlen(str)) {
		return;
	}

	*root = (BinaryTree *)calloc(sizeof(BinaryTree), 1);
	(*root)->data = str[index];

	createCompleteBinTree(&((*root)->LeftChild), str, 2*index + 1);
	createCompleteBinTree(&((*root)->RightChild), str, 2*index + 2);
}

void PreOrder(BinaryTree *root) {
	if(root == NULL) {
		return;
	}
	Visit(root->data);
	PreOrder(root->LeftChild);
	PreOrder(root->RightChild);
}


void InOrder(BinaryTree *root) {
	if(root == NULL) {
		return;
	}

	InOrder(root->LeftChild);
	Visit(root->data);
	InOrder(root->RightChild);
}


void PostOrder(BinaryTree *root) {
	if(root == NULL) {
		return;
	}

	PostOrder(root->LeftChild);
	PostOrder(root->RightChild);
	Visit(root->data);
}

void destory(BinaryTree **root) {
	if(*root == NULL) {
		return;
	}

	destory(&((*root)->LeftChild));
	destory(&((*root)->RightChild));

	free(*root);
	*root = NULL;
}
