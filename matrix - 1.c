#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTEX_NUM 10000
typedef int VertexType;

typedef enum{
    DG, UDG
}GraphType;

typedef struct{
    VertexType vertex[MAX_VERTEX_NUM]; //顶点向量
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
    int vexnum, arcnum;   //图的当前顶点数和弧数
    GraphType type;     //图的种类标志
}MatrixGraph;

int matrix_locate_vertex(MatrixGraph *MG, VertexType vex); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool matrix_insert_vertex(MatrixGraph *G, VertexType v);
bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w);

bool matrix_insert_vertex(MatrixGraph *G, VertexType v){
	if((*G).vexnum >= MAX_VERTEX_NUM) {
		return false;
	}
	if(matrix_locate_vertex(G, v) == -1) {
		(*G).vertex[(*G).vexnum] = v;
		for(int i = 0; i <= (*G).vexnum; i++) {
			(*G).arcs[(*G).vexnum][i] = 0;
			(*G).arcs[i][(*G).vexnum] = 0;
		}
		(*G).vexnum++;
		return true;
	}
	else {
		return false;
	}
}

bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w){
	if(matrix_locate_vertex(G, v) == -1 || matrix_locate_vertex(G, w) == -1) {
		return false;
	}
	else {
		int locV = 0, locW = 0;
		locV = matrix_locate_vertex(G, v);
		locW = matrix_locate_vertex(G, w);
		if((*G).type == DG) {
			if((*G).arcs[locV][locW] == 1) {
				return false;
			}
			else {
				(*G).arcs[locV][locW] = 1;
				(*G).arcnum++;
				return true;
			}
		}
		else if ((*G).type == UDG) {
			if((*G).arcs[locV][locW] == 1 || (*G).arcs[locW][locV] == 1) {
				return false;
			}
			else {
				(*G).arcs[locV][locW] = 1;
				(*G).arcs[locW][locV] = 1;
				(*G).arcnum++;
				return true;
			}
		}
	}
}

int main() {
	return 0;
}