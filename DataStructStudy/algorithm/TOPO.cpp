#include <bits/stdc++.h>
#include "DataStructStudy\StudyCode\include\GraphM.h"

using namespace std;

// 修正：拓扑排序函数应返回顶点字符而非索引
bool TopologicalSort(MGraph G, char result[]) {
    stack<int> S;                  // 用栈来存储入度为0的顶点
    int inDegree[MVNum] = {0};     // 初始化入度数组
    
    // 计算每个顶点的入度（注意：使用权值判断边存在）
    for(int i = 0; i < G.vexnum; i++) {
        for(int j = 0; j < G.vexnum; j++) {
            if(G.arcs[i][j] != INFINITY) { // 修正：使用权值判断边存在
                inDegree[j]++;      // j的入度加1
            }
        }
    }
    
    // 将入度为0的顶点入栈
    for(int i = 0; i < G.vexnum; i++) {
        if(inDegree[i] == 0) {      // 如果入度为0
            S.push(i);              // 将顶点i入栈
        }
    }
    
    int count = 0;                 // 计数器，记录已处理的顶点数
    
    while(!S.empty()){
        // 弹出栈顶元素
        int v = S.top();
        S.pop();                   
        result[count] = G.vexs[v]; // 修正：存入顶点字符而非索引
        printf("%c ", G.vexs[v]);  // 输出顶点
        count++;                   
        
        // 更新邻接顶点的入度
        for(int j = 0; j < G.vexnum; j++) {
            if(G.arcs[v][j] != INFINITY) { // 修正：使用权值判断边存在
                inDegree[j]--;      
                if(inDegree[j] == 0) { 
                    S.push(j);       
                }
            }
        }
    }
    
    // 循环结束后检测是否存在环
    if(count < G.vexnum) {
        printf("Graph contains a cycle, topological sort failed.\n");
        return false;  
    }
    
    return true;  
}