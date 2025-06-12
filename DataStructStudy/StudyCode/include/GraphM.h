#include <bits/stdc++.h>
#include "DataStructStudy\StudyCode\include\UTF-8.h"
using namespace std;
#define MVNum 100                 //最大顶点数
#define INFINITY INT_MAX          //表示无穷大（无边）

typedef struct{
  char vexs[MVNum];           //存放顶点的一维数组
  int  arcs[MVNum][MVNum];     //邻接矩阵（存储权值）
  int  vexnum,arcnum;          //图的当前顶点数和边总数
}MGraph;

void CreatMGraph(MGraph &G)
{
    int i, j, k, weight;
    char v1, v2;
    scanf("%d%d", &G.vexnum, &G.arcnum);
    getchar(); // 处理换行符
    
    // 读取顶点信息
    for (i = 0; i < G.vexnum; i++)
        scanf("%c", &G.vexs[i]);
    
    // 初始化邻接矩阵，全部置为INFINITY（表示无边）
    for (i = 0; i < G.vexnum; i++)
        for (j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = INFINITY;
    
    // 读取边信息和权值并更新邻接矩阵
    for (k = 0; k < G.arcnum; k++) {
        getchar(); // 处理换行符
        scanf("%c %c %d", &v1, &v2, &weight); // 增加读取权值
        i = locate(G, v1); // 查找v1的顶点下标
        j = locate(G, v2); // 查找v2的顶点下标
        G.arcs[i][j] = weight;  // 添加边(v1, v2)及其权值
        G.arcs[j][i] = weight;  // 无向图的对称性：添加边(v2, v1)及其权值
    }
}

int locate(MGraph G, char v)
{
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vexs[i] == v) {
            return i; // 返回顶点v的下标
        }
    }
    return -1; // 如果未找到，返回-1
}
