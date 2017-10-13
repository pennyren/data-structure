#ifndef __GRAPH_H
#define __GRAPH_H

#include <stdlib.h>
#define maxVertex 20;
#define true 1;
#define false 0;
typedef int boolean;

//有向图，有向网
typedef enum {DG, DN, UDG, UDN} GraphType;

//邻接矩阵
typedef struct {
    char vex[maxVertex];
    int arc[maxVertex][maxVertex];
    int vexnum, arcnum; //顶点数，边数
}MGraph;

//邻接表
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *next;
}ArcNode; //边表

typedef struct VexNode {
    char data;
    ArcNode *first;
}VexNode, AdjList[maxVertex]; //顶点

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;

//十字链表
typedef struct ArcNode {
    int tailvex, headvex;
    struct ArcNode *hlink, *tlink;
}ArcNode; //弧
typedef struct VexNode {
    char data;
    ArcNode *firstin, *firstout;
}VexNode;
typedef struct {
    VexNode xlist[maxVertex];
    int vexnum, arcnum;
}OLGraph;

//邻接多重表
typedef struct ArcNode {
    boolean visited;
    int ivex, jvex; //该边依附的两个顶点位置
    strcut ArcNode *ilink, *jlink;//分别指向依附这两个定点的下一条边
}ArcNode;

typedef struct VexNode {
    char data;
    ArcNode *firstedge;
}VexNode;

typedef struct {
    VexNode adjmulist[maxVertex];
    int vexnum, edgenum;
}AMLGraph;

void createGraph() {

}

#endif
