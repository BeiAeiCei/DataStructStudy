#include <bits/stdc++.h>
#include "DataStructStudy\StudyCode\include\GraphM.h"
#include "DataStructStudy\algorithm\TOPO.cpp"

using namespace std;

void CPM(MGraph G) {
    int ve[MVNum] = {0};      // 每个顶点的最早发生时间
    int vl[MVNum];            // 每个顶点的最晚发生时间
    char topo[MVNum];         // 拓扑排序结果（直接存储顶点字符）
    int i, j, k;
    
    // 获取拓扑排序结果（直接存储字符）
    if (!TopologicalSort(G, topo)) {
        printf("图中存在环，无法计算关键路径\n");
        return;
    }
    
    // 初始化最晚发生时间
    for(i = 0; i < G.vexnum; i++) {
        vl[i] = INT_MAX;
    }
    
    // 计算最早发生时间（按拓扑序）
    // 构建拓扑序对应的顶点索引数组
    int topoIndices[MVNum];
    for(i = 0; i < G.vexnum; i++) {
        for(j = 0; j < G.vexnum; j++) {
            if (G.vexs[j] == topo[i]) {
                topoIndices[i] = j;
                break;
            }
        }
    }
    
    for(i = 0; i < G.vexnum; i++) {
        k = topoIndices[i];  // 当前处理的顶点索引
        for(j = 0; j < G.vexnum; j++) {
            if(G.arcs[k][j] != INFINITY) {  
                ve[j] = max(ve[j], ve[k] + G.arcs[k][j]);
            }
        }
    }
    
    // 计算最晚发生时间（按拓扑逆序）
    int lastIndex = topoIndices[G.vexnum - 1];  // 拓扑排序最后一个顶点的索引
    vl[lastIndex] = ve[lastIndex];      
    
    for(i = G.vexnum - 2; i >= 0; i--) {  
        k = topoIndices[i];  
        for(j = 0; j < G.vexnum; j++) {
            if(G.arcs[k][j] != INFINITY) {  
                vl[k] = min(vl[k], vl[j] - G.arcs[k][j]);
            }
        }
    }
    
    // 输出关键路径
    printf("关键路径：\n");
    bool isCriticalPath = false;
    
    for(i = 0; i < G.vexnum; i++) {
        for(j = 0; j < G.vexnum; j++) {
            if(G.arcs[i][j] != INFINITY) {  
                int e = ve[i];            
                int l = vl[j] - G.arcs[i][j];  
                
                if(e == l) {  
                    printf("%c->%c ", G.vexs[i], G.vexs[j]);
                    isCriticalPath = true;
                }
            }
        }
    }
    
    if(!isCriticalPath) {
        printf("无关键路径\n");
    } else {
        printf("\n");
    }
    
    // 输出关键路径长度
    printf("关键路径长度：%d\n", ve[lastIndex]);
}