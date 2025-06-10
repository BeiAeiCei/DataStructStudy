#include <bits/stdc++.h>
#include "DataStructStudy\StudyCode\include\GraphL.h"
#include "DataStructStudy\StudyCode\include\UTF-8.h"

using namespace std;
bool visited[100]; // 访问标记数组


void BFS(ALGraph G , int v){
    visited[v] = true; // 标记顶点为已访问
    queue<int>q; // 创建一个队列
    q.push(v); // 将起始顶点入队

    while (!q.empty()){
        int u = q.front(); // 获取队头元素
        q.pop(); // 出队

        // 遍历u的所有邻接点
        for (ArcNode *p = G.vertices[u].first; p != NULL; p = p->nextarc) {
            printf("%c ", G.vertices[u].data);
            int w = p->adjvex; // 获取邻接点的下标
            if (!visited[w]) { // 如果未访问过
                visited[w] = true; // 标记为已访问
                q.push(w); // 入队
            }
        }
    }
}


int main(){
    int v;
    scanf("%d", &v);
    ALGraph G;
    CreatALGraph(G); 
    // 初始化访问标记
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = 0;
    }
    
    // 从顶点0开始BFS
    printf("BFS traversal starting from vertex 0:\n");
    BFS(G, 0);
    
    return 0;
}