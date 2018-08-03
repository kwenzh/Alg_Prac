#include<stdio.h>


#define INFINITY 	 9999
#define POINTCOUNT		6

void initRount(int *firstAddress);
void showMatrix(int *MatrixFisrtAddress, int row, int col);

void showMatrix(int *MatrixFisrtAddress, int row, int col) {
	int i;
	int j;

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			printf("%5d", *(MatrixFisrtAddress++));
		}
		printf("\n");
	}
	printf("\n");
}

void initRount(int *firstAddress) {
	int i;
	int j;

	for(i = 0; i < POINTCOUNT; i++) {
		for(j = 0; j < POINTCOUNT; j++) {
			*(firstAddress + i * POINTCOUNT + j) = j;
		}
	}
}

int main(void) {

	int Map_info[6][6] = {0,10,21,9999,8, 9999,
						10,0,18,5,9999,6,
						21,18,0,9999, 25,19,
						9999,5,9999,0,9999,7,
						 8, 9999,25,9999,0,33,
						 9999,6,19,7,33,0};
	int rount_matrix[6][6];
	int i;
	int j;
	int k;

	initRount(&rount_matrix[0][0]);

	showMatrix(&rount_matrix[0][0], 6, 6);
	showMatrix(&Map_info[0][0], 6, 6);

	for(i = 0; i < POINTCOUNT; i++) {
		for(j = 0; j < POINTCOUNT; j++) {
			for(k = 0; k < POINTCOUNT; k++) {
				if(Map_info[j][k] > Map_info[j][i] + Map_info[i][k]) {
					Map_info[j][k] = Map_info[j][i] + Map_info[i][k];
					rount_matrix[j][k] = i;
				}
			}
		}
		// showMatrix(&Map_info[0][0], 6, 6);
	}

	showMatrix(&rount_matrix[0][0], 6, 6);
	showMatrix(&Map_info[0][0], 6, 6);


	return 0;
}
