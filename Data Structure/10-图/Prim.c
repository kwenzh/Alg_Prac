#include<stdio.h>
#include<malloc.h>


#define MAXVEXNUM	100

#define INFINITY	99999

#define HaveJoined	0

typedef struct GRAPH{
	int vexnum;						//顶点个数
	int edgenum;					//边的个数
	int arc[MAXVEXNUM][MAXVEXNUM];	//图的邻接矩阵
	char *vec_infor;					//记录各个顶点的信息 长度和vexnum保持一致
}GRAPH;

typedef struct CLOSE_EDG {
	int adjvex;
	int lowcost;
}CLOSE_EDG;
void createGraph(GRAPH **graph, int vexnum, int edgenum);
void destoryGraph(GRAPH **graph);
void showMatrix_1(int array[][MAXVEXNUM], int n);
char *Prim(const GRAPH *graph, CLOSE_EDG *closedge);

char *Prim(const GRAPH *graph, CLOSE_EDG *closedge) {
	const int start = 0;
	int i;
	int j;
	int k;
	int min_index;
	int min;
	closedge[start].lowcost = HaveJoined;  		//标记起点start已经加入生成树中
	char *JoinOrder = NULL;					//记录各顶点添加到生成树的先后顺序
	int beginIndex = 0;

	JoinOrder = (char *)calloc(sizeof(char), graph->vexnum + 1);
	JoinOrder[beginIndex++] = graph->vec_infor[start];     //将起始点加进去结果	

// 然后初始化除起始点之外的剩下的节点
	for(i = 0; i < graph->vexnum; i++) {
		if(i != start) {
			closedge[i].adjvex = start;
			// 分别是起始点也就是A到其他各点的距离
			closedge[i].lowcost = graph->arc[start][i];
		}
	}

// 这里只需要再加入n-1个顶点即可 已经加入了起始点了
	for(i = 0; i < graph->vexnum - 1; i++) {
		min = INFINITY;
		// 找一个最小权重的边 以及这条边所到达的顶点
		for(k = 0; k < graph->vexnum; k++) {
			if(closedge[k].lowcost != HaveJoined && closedge[k].lowcost < min) {
				min_index = k;
				min = closedge[k].lowcost;
			}
		}
		// printf("%d ", min_index);
		JoinOrder[beginIndex++] = graph->vec_infor[min_index];   //加入找到的最小权重所达到的点
		closedge[min_index].lowcost = HaveJoined;				//标记该顶点已经加入了生成树中去了
// 在邻接矩阵中比较 新加入的点所能达到的各点 经过的路径是否有小于现在closedge里面记录的路径
		for(j = 0; j < graph->vexnum; j++) {
			if(j != min_index && graph->arc[min_index][j] < closedge[j].lowcost) {
				closedge[j].lowcost = graph->arc[min_index][j];  //更新权重值
				closedge[j].adjvex = min_index;
			}
		}
	}
	JoinOrder[beginIndex] = '\0';

	return JoinOrder;
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
	(*graph)->vec_infor = (char *)calloc(sizeof(char), vexnum + 1);
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

void showCLoseEdge(CLOSE_EDG *closedge, const int vexnum) {
	int i;

	for(i = 0; i < vexnum; i++) {
		printf("%d ", closedge[i].adjvex);
	}
	printf("\n");
	for(i = 0; i < vexnum; i++) {
		printf("%d ", closedge[i].lowcost);
	}
	printf("\n");
}


int main(void) {
	GRAPH *graph = NULL;
	int vexnum = 6;       		//顶点个数
	int edgenum = 10;
	CLOSE_EDG *closedge = NULL;
	char *JoinOrder;

	printf("input vexnum and edgenum: ");
	scanf("%d%d", &vexnum, &edgenum);
	closedge = (CLOSE_EDG *)calloc(sizeof(CLOSE_EDG), vexnum);

	createGraph(&graph, vexnum, edgenum);
	showMatrix_1(graph->arc, vexnum);
	


	JoinOrder = Prim(graph, closedge);
	printf("JoinOrder : %s\n", JoinOrder);

	// showCLoseEdge(closedge, vexnum);


	destoryGraph(&graph);
	free(closedge);
	free(JoinOrder);
	JoinOrder = NULL;
	closedge = NULL;

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
A
B
C
D
E
F
0 1 6
0 2 1
0 3 5
1 2 5
1 4 3
2 3 5
2 4 6
2 5 4
3 5 2
4 5 6



 */