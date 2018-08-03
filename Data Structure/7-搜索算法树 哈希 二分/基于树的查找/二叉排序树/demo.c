#include<stdio.h>
#include<malloc.h>

#include"BinarySearchTree.h"

int main(void) {
	DataType array[] = {44,21,65,52,14,32,58,72,80};
	int array_length = sizeof(array) / sizeof(DataType);
	BSTree *root = NULL;
	NODE *find_result = NULL;
	DataType targetValue = 65;

	showArray(array, array_length);
	CreateBSTree(&root, array, array_length);
	showTree(root);
	printf("\n");
	find_result = SearchFromBSTree(root, targetValue);
	if(find_result == NULL) {
		printf("%d is not exist\n", targetValue);
	}else {
		printf("%d find successful!\n", find_result->key);
	}
	PrintTreeInWinDow(root, 0);
	delelteBSTree(root, targetValue);
	showTree(root);printf("\nroot data = %d\n",root->key);
	PrintTreeInWinDow(root, 0);
	destoryBSTree(&root);

	return 0;
}
