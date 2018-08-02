#include<stdio.h>

#include"../../include/kwenquene.h"

int main(void) {
	QUENE *quene = NULL;
	int i;
	const int maxRoom = 5;
	int dequenedata;

	initializeQuene(&quene, maxRoom);
	EnQuene(quene, 2);
	EnQuene(quene, 3);
	EnQuene(quene, 4);
	EnQuene(quene, 5);
	EnQuene(quene, 6);

	while(0 == isQueneEmpty(quene)) {
		DeQuene(quene, &dequenedata);
		printf("%d\n", dequenedata);
	}

	destoryQuene(&quene);

	return 0;
}