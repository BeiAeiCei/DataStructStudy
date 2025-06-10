#include <bits/stdc++.h>

#include <bits/stdc++.h>
#include "DataStructStudy\StudyCode\include\GraphL.h"
#include "DataStructStudy\StudyCode\include\UTF-8.h"

bool visited[100]; // 访问标记数组
void DFS(ALGraph G, int v, int visited[]) {
    visited[v] = 1;       // 标记已访问
    printf("%d ", v);     // 访问顶点
    ArcNode *p = G.vertices[v].first;
    while (p != NULL) {
        int w = p->adjvex;
        if (!visited[w]) {
            DFS(G, w, visited); // 递归遍历邻接顶点
        }
        p = p->nextarc;
    }
}