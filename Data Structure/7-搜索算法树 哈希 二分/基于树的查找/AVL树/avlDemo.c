#include<stdio.h>

#include"AVLTree.h"

int main(void) {
	AVLTree *root = NULL;
	DataType array[] = {1,3,5,7,9,10};
	int array_length = sizeof(array) / sizeof(DataType);
	AVLNode *find_result = NULL;
	DataType targetValue;

	createAVLTree(&root, array, array_length);
	showAVLTree(root);
	scanf("%d", &targetValue);
	//删除操作的测试
	deleteFromAVLTree(&root, targetValue); 
	showAVLTree(root);
	printf("root = %d\n", root->element);
	printf("root->right = %d\n", root->right->element);
	printf("root->right->right = %d\n", root->right->right->element);
	printf("root->left = %d\n", root->left->element);
	printf("root->left->left = %d\n", root->left->left->element);
	// printf("root->left->right = %d\n", root->left->right->element);
	// PrintTreeInWinDow(root);
	//查询操作的测试
	find_result = searchFromAVLTree(root, targetValue);
	if(NULL == find_result) {
		printf("%d is not exist\n", targetValue);
	}else {
		printf("find_result = %d\n", find_result->element);
	}


	destoryAVLTree(&root);

	return 0;
}
