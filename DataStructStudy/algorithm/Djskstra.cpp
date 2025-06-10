#include <bits/stdc++.h>

#include "DataStructStudy\StudyCode\include\GraphL.h"
#include "DataStructStudy\StudyCode\include\UTF-8.h"

using namespace std;
#define INT_MAX 2147483647 // 定义一个很大的整数作为无穷大
bool final[100]; // 最短路径标记数组
int dist[100];   // 目前存储最短路径长度
int path[100];   // 目前存储当前结点的直接前驱

void Dijkstra(ALGraph G , int v){
    // 初始化
    for(int i = 0;i < G.vexnum; i++){
        final[i] = false; // 初始化所有结点为未处理
        dist[i] = INT_MAX; // 初始化所有结点的距离为无穷大
        path[i] = -1; // 初始化所有结点的前驱为-1
    }
    dist[v] = 0; // 起始结点到自身的距离为0
    final[v] = true; // 标记起始结点为已处理
    ArcNode *p = G.vertices[v].first; // 获取起始结点的邻接点
    while(p != NULL){
        int w = p->adjvex; // 获取邻接点的下标
        dist[w] = p->weight; // 更新邻接点的距离
        path[w] = v; // 更新邻接点的前驱为起始结点
        p = p->nextarc; // 继续遍历下一个邻接点
    }
    for(int i = 1;i < G.vexnum; i++){
        int u = -1;
        int minDist = INT_MAX; // 初始化最小距离为无穷大
        // 找到未处理结点中距离最小的结点
        for(int j = 0; j < G.vexnum; j++){
            if(!final[j] && dist[j] < minDist){
                u = j; // 更新最小距离结点
                minDist = dist[j]; // 更新最小距离
            }
        }
        if(u == -1) break; // 如果没有未处理结点，退出循环
        final[u] = true; // 标记当前结点为已处理

        p = G.vertices[u].first; // 获取当前结点的邻接点
        while(p != NULL){
            int j = p->adjvex; // 获取邻接点的下标
            if(!final[j] && dist[u] + p->weight < dist[j]){
                dist[j] = dist[u] + p->weight; // 更新邻接点的距离
                path[j] = u; // 更新邻接点的前驱为当前结点
            }
            p = p->nextarc; // 继续遍历下一个邻接点
        }
    }
}