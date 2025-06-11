#include <bits/stdc++.h>
#include "DataStructStudy\StudyCode\include\GraphM.h"

using namespace std;

bool TopologicalSort(MGraph G){
    stack <int> S;                  // 用栈来存储入度为0的顶点
    int inDegree[MVNum] = {0};      // 初始化入度数组
    for(int i = 0; i < G.vexnum; i++) {
        for(int j = 0; j < G.vexnum; j++) {
            if(G.arcs[i][j] == 1) { // 如果有边i->j
                inDegree[j]++;      // j的入度加1
            }
        }
    }
    for(int i = 0; i < G.vexnum; i++) {
        if(inDegree[i] == 0) {      // 如果入度为0
            S.push(i);              // 将顶点i入栈
        }
    }
    int count = 0;                 // 计数器，记录已输出的顶点数
    while(!S.empty()){
        int v = S.top();
        S.pop();                   // 弹出栈顶元素
        printf("%c ", G.vexs[v]);  // 输出顶点
        count++;                   // 已输出顶点数加1
        for(int j = 0; j < G.vexnum; j++) {
            if(G.arcs[v][j] == 1) { // 如果有边v->j
                inDegree[j]--;      // j的入度减1
                if(inDegree[j] == 0) { // 如果j的入度变为0
                    S.push(j);       // 将j入栈
                }
            }
        }
        // 如果排序后的顶点数小于图的顶点数，说明图中存在环
        if (count < G.vexnum) {
            return false;  // 排序失败，存在环
        }
        return true;  // 排序成功
    }
}