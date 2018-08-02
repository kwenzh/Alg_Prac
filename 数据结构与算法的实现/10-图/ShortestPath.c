#include<stdio.h>
#include<malloc.h>

#include"../../include/kwenarraytools.h"

#define MAXVEXNUM	100

#define INFINITY	99999

typedef struct GRAPH{
	int vexnum;						//顶点个数
	int edgenum;					//边的个数
	int arc[MAXVEXNUM][MAXVEXNUM];	//图的邻接矩阵
	char *vec_infor;					//记录各个顶点的信息 长度和vexnum保持一致
}GRAPH;

void createGraph(GRAPH **graph, int vexnum, int edgenum);
void destoryGraph(GRAPH **graph);


void Dijkstra(const GRAPH *graph, int *dist);
void showMatrix_1(int array[][MAXVEXNUM], int n);

//map_info记录的各点到各点的距离信息， rout_matrix是路由矩阵 达到目标点最后一次经过的结点
void Floy(const GRAPH *graph, int **Map_info, int **rount_matrix);

void showArray(int *ArrayFirstAddress, int array_length);


void Floy(const GRAPH *graph, int **Map_info, int **rount_matrix) {
	int i;
	int j;
	int k;

	for(i = 0; i < graph->vexnum; i++) {
		for(j = 0; j < graph->vexnum; j++) {
			Map_info[i][j] = graph->arc[i][j];
			rount_matrix[i][j] = j;
		}
	}

	for(i = 0; i <  graph->vexnum; i++) {
		for(j = 0; j <  graph->vexnum; j++) {
			for(k = 0; k <  graph->vexnum; k++) {
				if(Map_info[j][k] > Map_info[j][i] + Map_info[i][k]) {
					Map_info[j][k] = Map_info[j][i] + Map_info[i][k];
					rount_matrix[j][k] = i;
				}
			}
		}
	}
}

void Dijkstra(const GRAPH *graph, int *dist) {
	int min;
	int k;
	int j;
	int t;
	int i;
	int *flag;

	flag = (int *)calloc(sizeof(int), graph->vexnum);
	for(j = 1, flag[0] = 1; j < graph->vexnum; j++) {
		dist[j] = graph->arc[0][j];
	}
	for(t = 1; t < graph->vexnum; t++) {
		min = INFINITY;
		k = 0;
		// 找到当前记录最短路径的数组dist 中最小的路径 还有达到的结点
		for(i = 1; i < graph->vexnum; i++) {
			if((flag[i] == 0) && (dist[i] < min)) {
				min = dist[i];
				k = i;
			}
		}
		flag[k] = 1;
		// 以这个找到的k结点 以这个结点为中间结点出发去判断 通过该节点达到其他结点是够更近
		for(i = 1; i < graph->vexnum; i++) {
// 在这里如果发现了 从已经找到最短路径的节点间接达到待解决点 要更近如果有这样的路径
// 就更新记录最短路径的数组
			if((flag[i] == 0) && (dist[k] + graph->arc[k][i] <= dist[i])) {
				dist[i] = dist[k] + graph->arc[k][i];
			}
		}
	}
}



void destoryGraph(GRAPH **graph) {
	if((*graph) == NULL) {
		return;
	}
	free((*graph)->vec_infor);
	free(*graph);
	*graph = NULL;
}

void createGraph(GRAPH **graph, int vexnum, int edgenum) {
	int i;
	int data;
	int from;
	int to;
	int j;

	*graph = (GRAPH *)calloc(sizeof(GRAPH), 1);
	(*graph)->vexnum = vexnum;
	(*graph)->edgenum = edgenum;
	(*graph)->vec_infor = (char *)calloc(sizeof(char), 1);
	for(i = 0; i < vexnum; i++) {
		printf("input the %d/%d vex infor: ", i+1, vexnum);
		setbuf(stdin, NULL);
		(*graph)->vec_infor[i] = getchar();
	}
	for(i = 0; i < vexnum; i++) {
		for(j = 0; j < vexnum; j++) {
			(*graph)->arc[i][j] = INFINITY;
		}
	}

	for(i = 0; i < vexnum; i++) {
		(*graph)->arc[i][i] = 0;
	}

	for(i = 0; i < edgenum; i++) {
		printf("input the %d/%d ede infor(from to power):", i+1, edgenum);
		setbuf(stdin, NULL);
		scanf("%d%d%d", &from, &to, &data);
		// printf("from = %d, to = %d, data = %d\n", from, to, data);
		(*graph)->arc[from][to] = (*graph)->arc[to][from]= data;
	}
}

int main(void) {
	GRAPH *graph = NULL;
	int *dij_dist;
	int vexnum = 4;       		//顶点个数
	int edgenum = 5;			//边数
	int **Floy_result_matrix;
	int **Floy_rount_matrix;

	printf("input vexnum and edgenum: ");
	scanf("%d%d", &vexnum, &edgenum);

	dij_dist = (int *)calloc(sizeof(int), vexnum);
	createGraph(&graph, vexnum, edgenum);
	printf("Map Matrix infor:\n");
	showMatrix_1(graph->arc, vexnum);
	
	Dijkstra(graph, dij_dist);

	printf("Dijkstra result: \n");
	showArray(dij_dist, vexnum);  //这里打印的是第一个节点到其他各点的最短距离信息
	
	Floy_result_matrix = getMatrix(vexnum, vexnum);
	Floy_rount_matrix = getMatrix(vexnum, vexnum);
	Floy(graph, Floy_result_matrix, Floy_rount_matrix);

	printf("Floy result: \n");
	showMatrix(&Floy_result_matrix[0][0], vexnum, vexnum);
	showMatrix(&Floy_rount_matrix[0][0], vexnum, vexnum);


	destoryMatrix(&Floy_result_matrix, vexnum);
	destoryMatrix(&Floy_rount_matrix, vexnum);
	destoryGraph(&graph);
	free(dij_dist);

	return 0;
}

void showMatrix_1(int array[][MAXVEXNUM], int n) {
	int i;
	int j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			// printf("%d ", array[i][j]);
			printf("%6d ", *(*(array + i)+j));
		}
		printf("\n");
	}
	printf("\n");
}
/* 
6 10
1
2
3
4
5
6
0 1 10
0 2 21
0 4 8
1 2 18
1 3 5
1 5 6
2 4 25
2 5 19
3 5 7
4 5 33

*/
