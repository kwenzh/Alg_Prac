#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#include"../../../../include/kwenarraytools.h"

typedef int DataType;

typedef struct NODE{
	DataType key;
	struct NODE *leftChild;
	struct NODE *rightChild;	
}BSTree, NODE;

void CreateBSTree(BSTree **root, DataType *array, int array_length);
void InsertBSTree(BSTree **root, DataType key);
void destoryBSTree(BSTree **root);
void showTree(BSTree *root);
//二叉搜索树的递归实现 返回一个节点
NODE *SearchFromBSTree(BSTree *root, DataType targetValue);

//删除的时候要考虑删除的节点的三种情况嗯嗯
//1、节点是叶子节点，没有孩子
//2、节点有一个孩子 左孩子或者右孩子
//3、节点有两个孩子
boolean delelteBSTree(BSTree *root, DataType targetValue);
void PrintTree(BSTree *root, int depth);
void PrintTreeInWinDow(BSTree *root, int depth);


void PrintTreeInWinDow(BSTree *root, int depth) {
	PrintTree(root, depth);
	printf("\nTurn your head 90 degrees by left and can see tree!\n");
}
void PrintTree(BSTree *root, int depth) {
	int i;

	if(root == NULL) {
		return;
	}

	PrintTree(root->rightChild, depth + 1);
	for(i = 0; i < depth; i++) {
		printf("  ");
	}
	printf("%d\n", root->key);
	PrintTree(root->leftChild, depth + 1);

}

boolean delelteBSTree(BSTree *root, DataType targetValue) {
	NODE *p = root;
	NODE *pre_p = NULL;
	NODE *s;
	NODE *q;

	while(NULL != p) {
		if(p->key == targetValue) {
			break;
		}
		pre_p = p;							//f用来记录p的前驱节点
		if(p->key > targetValue) {
			
			p = p->leftChild;
		}else{
			p = p->rightChild;
		}
	}
	if(p == NULL) {
		printf("The %d is not exist, delete faild !\n");
		return false;
	}
	if(p->leftChild == NULL) {		//这里考虑的是要删除的节点是一个叶子节点的话或者只有一个右孩子
		if(pre_p == NULL) {
			root = p->rightChild;
		}else if(pre_p->leftChild == p) {     //在左子树上面
			pre_p->leftChild = p->rightChild;
		}else{								//在右子树上面
			pre_p->rightChild = p->rightChild;
		}
		free(p);
		p = NULL;
	}else {
		q = p;
		s = p->leftChild;
		while(s->rightChild) {
			q = s;
			s = s->rightChild;
		}
		if(q == p) {
			q->leftChild = s->leftChild;
		}else {
			q->rightChild = s->leftChild;
		}
		p->key = s->key;      //用赋值去覆盖掉
		free(s);
		s = NULL;
	}

	return true;
}

NODE *SearchFromBSTree(BSTree *root, DataType targetValue) {
	if(root == NULL) {
		return NULL;
	}else if(targetValue == root->key) {
		return root;
	}else if(root->key > targetValue) {
		return SearchFromBSTree(root->leftChild, targetValue);
	}else {
		return SearchFromBSTree(root->rightChild, targetValue);
	}
}


void Visit(DataType data) {
	printf("%d ", data);
}

void showTree(BSTree *root) {
	if(root == NULL) {
		return;
	}

	showTree(root->leftChild);
	Visit(root->key);
	showTree(root->rightChild);
}

void destoryBSTree(BSTree **root) {
	if(*root == NULL) {
		return;
	}

	destoryBSTree(&((*root)->leftChild));
	destoryBSTree(&((*root)->rightChild));

	free(*root);
	*root = NULL;
}

//需要通过递归找到适合插入的地方
void InsertBSTree(BSTree **root, DataType key) {
	if(*root == NULL) {
		*root = (BSTree *)calloc(sizeof(BSTree), 1);
		(*root)->key = key;
		(*root)->leftChild = NULL;
		(*root)->rightChild = NULL;
	}else if(key <= (*root)->key) {
		InsertBSTree(&((*root)->leftChild), key);
	}else{
		InsertBSTree(&((*root)->rightChild), key);
	}
}


void CreateBSTree(BSTree **root, DataType *array, int array_length) {
	int i = 0;

	while(i < array_length) {
		InsertBSTree(root, array[i++]);
	}
}

#endif