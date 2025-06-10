#include <bits/stdc++.h>
#include "DataStructStudy\StudyCode\include\GraphM.h"

using namespace std;
#define INT_MAX 2147483647 // 定义一个很大的整数作为无穷大

int PrimMST(MGraph &G , char vvv) {

    int n = G.vexnum;
    bool isJoined[MVNum] = {false};
    int key[MVNum];
    int parent[MVNum];
    // 初始化
    for(int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    int start = locate(G, vvv); // 找到起始顶点的索引
    key[start] = 0; // 起始顶点的权重为0

    for(int count = 0; count < n; count++){
        int u = -1, minkey = INT_MAX;
        for (int v = 0; v < n; v++){
            if (!isJoined[v] && key[v] < minkey) {
                minkey = key[v];
                u = v;
            }
        }
        if(u == -1) break; // 图不连通
        isJoined[u] = true;

        for (int v = 0; v < n; v++) {
            if (G.arcs[u][v] != 0 && G.arcs[u][v] < INT_MAX && !isJoined[v] && G.arcs[u][v] < key[v]) {
                key[v] = G.arcs[u][v];
                parent[v] = u;
            }
        }
    }
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        if(parent[i] != -1)
            totalWeight += G.arcs[i][parent[i]];
    }
    return totalWeight;
}