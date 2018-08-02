#include<stdio.h>

#include"BinaryTree.h"

//A B C D E F G
//A(B(*C(**))D(E(**)F(**)))
// A(B(*D(G(**)*))C((E(**)F(H*))))
int main(void) {
	char* BinTree = "A(B(*D(G(**)*))C((E(**)F(H*))))";
	BinaryTree *root = NULL;
	int index = 0;

	createBinTree(&root, BinTree, &index);

	printf("1111\n");
	printf("PreOrder: ");
	PreOrder(root);
	printf("\nInOrder: ");
	InOrder(root);
	printf("\nPostOrder: ");
	PostOrder(root);
	printf("\n");

	StatisticalLeftCount(root);

	printf("left count = %d\n", getLeaveCount(root));
	printf("tree depth = %d\n", PostTreeDepth(root));
	PrintTreeInWinDow(root, 0);

	destory(&root);

	return 0;
}
