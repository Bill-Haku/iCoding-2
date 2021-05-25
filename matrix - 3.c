#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX_NUM 10000
typedef int VertexType;

typedef enum{
    DG, UDG
}GraphType;

typedef struct ArcNode{
    int adjvex;
    InfoPtr *info;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *firstarc;
}VNode;
typedef struct{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
}ListGraph;

int locate_vertex(ListGraph *G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool del_vertex(ListGraph *G, VertexType v); //删除顶点 v

bool del_vertex(ListGraph* G, VertexType v) {
   	ArcNode *p, *pre, *del;
    if (locate_vertex(G, v) == -1) {
        return false;
    } 
    else {
        int locV = locate_vertex(G, v);
        (*G).vertex[locV].data = 0; 
        p = (*G).vertex[locV].firstarc;
        (*G).vertex[locV].firstarc = NULL;

        while (p) { 
            del = p;
            p = p->nextarc;
            free(del);
            (*G).arcnum--; 
        }

        for (int j = 0; j < (*G).vexnum; j++) { 
            p = (*G).vertex[j].firstarc;
            while (p) {
                if (p->adjvex == locV) {
                    if (p == (*G).vertex[j].firstarc) {
                        del = p;
                        p = p->nextarc;
                        (*G).vertex[j].firstarc = p;
                        pre = NULL;
                        free(del);
                        (*G).arcnum--;
                        break;
                    } 
                    else {
                        del = p;
                        p = p->nextarc;
                        pre->nextarc = p;
                        free(del);
                        (*G).arcnum--;
                        break;
                    }
                }
                pre = p;
                p = p->nextarc;
            }
        }
        (*G).vexnum--;
        return true;    
    }
}


int main() {
	return 0;
}