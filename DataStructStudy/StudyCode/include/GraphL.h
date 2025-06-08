#include <bits/stdc++.h>
#include "DataStructStudy\StudyCode\include\UTF-8.h"
using namespace std;
#define MVNum 100                   //最大顶点数
typedef char VertexType;   

// 顶点
typedef struct VNode{
    VertexType data;                // 顶点信息
    struct ArcNode *first;          // 指向第一个邻接点的指针
}VNode,AdjList[MVNum];

//被指向的顶点
typedef struct ArcNode{
    int adjvex;                     // 边指向哪一个结点(就是顶点下标)
    struct ArcNode *nextarc;        // 指向下一个邻接点的指针
}ArcNode;

// 图的邻接表表示
typedef struct ALGraph{
    AdjList vertices;               // 顶点数组
    int vexnum,arcnum;              // 图的总顶点数和边数
}ALGraph;

int locate(ALGraph G, char v) {
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data == v) {
            return i;
        }
    }
    return -1; // 未找到返回-1
}


void CreatALGraph(ALGraph &G){
    int i,j,k;
    char v1,v2;
    ArcNode *p;
    scanf("%d%d",&G.vexnum,&G.arcnum);
    getchar(); // 处理换行符
    // 读取顶点信息
    for (i = 0; i < G.vexnum; i++) {
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].first = NULL; // 初始化每个顶点的邻接点链表为空
    }
    // 读取边信息并建立邻接表
    for (k = 0; k < G.arcnum; k++){  // 修改这里，使用arcnum而不是vexnum
        scanf(" %c %c",&v1,&v2);     // 添加前导空格处理空白字符
        getchar();

        i = locate(G , v1);
        j = locate(G , v2);
        
        if(i == -1 || j == -1) {     // 添加错误检查
            printf("输入的顶点不存在！\n");
            continue;
        }

        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = j;                      // 被指向的顶点的下标
        p->nextarc = G.vertices[i].first;   // 头插法
        G.vertices[i].first = p;

        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = i;
        p->nextarc = G.vertices[j].first;
        G.vertices[j].first = p;
    }
    
}