#include<stdio.h>
#include<string.h>

#include"../../include/kwenQUENE.h"

#define MAXVEX			20		//最多存在顶点个数
#define INFINITY		100000	//表示图中两点不存在链接关系 
#define HAS_VISITED		1
#define NOT_VISITED		0

typedef char DataType;

int DfsVisit[MAXVEX] = {NOT_VISITED};
int BfsVisit[MAXVEX] = {NOT_VISITED};

typedef struct AdjMatrix{
	int vertices_count;			//图中顶点的个数
//图中各顶点之间的关系 无权图就是0-1，有权图则是权重或者无穷大这里用INFINITY表示无穷大
	int array[MAXVEX][MAXVEX]; 				
	int arc_count;				//图中边的个数
	DataType vec_info[MAXVEX];				//图中各个顶点信息
}AdjMatrix;

void CreateFigure(AdjMatrix *graph);
void showFigure(const AdjMatrix graph);
void DFS(AdjMatrix graph, int index);
void DFSTraverse(AdjMatrix graph);
void BFSTravese(AdjMatrix graph);

void BFSTravese(AdjMatrix graph) {
	QUENE *quene = NULL;
	int a;
	int i;
	int j;

	initializeQuene(&quene, graph.vertices_count);
	printf("\nBFS travese: ");
	for(i = 0; i < graph.vertices_count; i++) {
		// printf("2222\n");
		if(BfsVisit[i] == NOT_VISITED) {
			BfsVisit[i] = HAS_VISITED;
			printf("%c ", graph.vec_info[i]);
			EnQuene(quene, i);
		
			while(false == isQueneEmpty(quene)) {
				DeQuene(quene, &a);
			
				for(j = 0; j < graph.vertices_count; j++) {
					if(graph.array[a][j] != INFINITY && BfsVisit[j] == NOT_VISITED) {
						BfsVisit[j] = HAS_VISITED;
						printf("%c ", graph.vec_info[j]);
						EnQuene(quene, j);
					}
				}
			}
		}
	}

	destoryQuene(&quene);
}
/*
void BFSTraverse(MGraphy g){
    SeqQueue *queue;
    initQueue(queue);   // 顺序表实现的队列，先初始化
    int visited[] = {0};    // 初始化每个结点对应为未访问
    int a;
    for(int i=0;i<g.vnum;i++){   // 对每个结点进行深度遍历
        if(visited[i] == 0){
            visited[i] = 1;
            printf("%c",g.vexs[i]);  // 深度遍历后对结点进行打印操作
            enQueue(queue,i);        // 将节点放到队列中
            while (queueLength(queue)){
                deQueue(queue,&a); // 取出对头元素，进行广度遍历
                for (int j = 0; j < g.vnum; ++j) {
                    if(g.arc[a][j] == 1 && visited[j]==0){   // 存在边，且对应的店没有方问过
                        visited[j] = 1;
                        printf("%c",g.vexs[j]);
                        enQueue(queue,j);                           // 遍历后再入队
                    }
                }
            }
        }
    }
}*/

void DFS(AdjMatrix graph, int index) {
	int i;

	DfsVisit[index] = HAS_VISITED;
	printf("%c, ", graph.vec_info[index]);
	for(i = 0; i < graph.vertices_count; i++) {
		if(graph.array[index][i] != 0 && graph.array[index][i] != INFINITY
			&& !DfsVisit[i]) {
			DFS(graph, i);
		}
	}
}

void DFSTraverse(AdjMatrix graph) {
	int i;

	printf("DFSTraverse depth first:");
	for(i = 0; i < graph.vertices_count; i++) {
		if(!DfsVisit[i]) {
			DFS(graph, i);
		}
	}
}

void showFigure(const AdjMatrix graph) {
	int i;
	int j;

	printf("the vec_info:");
	for(i = 0; i < graph.vertices_count; i++) {
		printf("%c ", graph.vec_info[i]);
	}
	printf("\nthe matrix infor:\n");
	for(i = 0; i < graph.vertices_count; i++) {
		for(j = 0; j < graph.vertices_count; j++) {
			if(graph.array[i][j] == INFINITY) {
				printf("%4c", '*');
			}else {
				printf("%4d", graph.array[i][j]);
			}
		}
		printf("\n");
	}
}

void CreateFigure(AdjMatrix *graph) {
	int i;
	int j;

	printf("input vec count and arc count:");
	scanf("%d%d", &graph->vertices_count, &graph->arc_count);

//先录入图中存储各个点的数据信息的一维数组
	for(i = 0; i < graph->vertices_count; i++) {
		printf("input the %d/%d vec info:", i+1, graph->vertices_count);
		setbuf(stdin, NULL);
		graph->vec_info[i] = getchar();
	}

//初始化array元素 统一置为无穷大
	for(i = 0; i < graph->vertices_count; i++) {
		for(j = 0; j < graph->vertices_count; j++) {
			graph->array[i][j] = INFINITY;
		}
	}

	for(i = 0; i < graph->arc_count; i++) {
		int point1, point2, weight;
		printf("input the %d/%d arc (point point weight):", i + 1, graph->arc_count);
		scanf("%d%d%d", &point1, &point2, &weight);
		graph->array[point1 - 1][point2 - 1] = weight;
		// graph->array[point2 - 1][point2 - 1] = weight;	//若是无向图 再加一句对称的赋值
	}
}

int main(void){
	AdjMatrix graph = {0};

	CreateFigure(&graph);
	showFigure(graph);
	DFSTraverse(graph);
	BFSTravese(graph);

	return 0;
}
/*
5 7
A
B
C
D
E
1 2 15
1 5 9
2 3 3
3 4 2
4 1 11
4 1 7
5 3 21
 */