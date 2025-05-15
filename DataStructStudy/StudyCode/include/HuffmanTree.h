#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stack>
using namespace std;
typedef struct{
	int weight;
  	int parent,lch,rch;
}HTNode,*HuffmanTree;

typedef string * HuffmanCode;

void Select(HuffmanTree HT, int n, int *s1, int *s2) {
    // 找第一个最小值
    *s1 = -1;
    int min = 0x3f3f3f3f;
    for(int i = 0; i < n; i++) {
        if(HT[i].parent == -1 && HT[i].weight < min) {
            min = HT[i].weight;
            *s1 = i;
        }
    }
    
    // 找第二个最小值
    *s2 = -1;
    min = 0x3f3f3f3f;
    for(int i = 0; i < n; i++) {
        if(HT[i].parent == -1 && i != *s1 && HT[i].weight < min) {
            min = HT[i].weight;
            *s2 = i;
        }
    }
}
void CreatHUFFMANTree(HuffmanTree *HT, int n) {
    if(n <= 1) return;
    int m = 2*n - 1; // 2n-1个结点
    *HT = (HuffmanTree)malloc(m*sizeof(HTNode)); // 申请空间
    if(!*HT) exit(0); // 申请失败

    // 初始化叶子节点
    for(int i = 0; i < m; i++){
        (*HT)[i].weight = 0; // 初始化权值为0
        (*HT)[i].parent = (*HT)[i].lch = (*HT)[i].rch = -1; // 初始化父结点和左右孩子为-1
    }

    // 输入叶子节点权值
    for(int i = 0; i < n; i++){
        printf("请输入第%d个结点的权值：",i+1);
        scanf("%d", &(*HT)[i].weight); // 修正输入权值的方式
    }

    // 构建哈夫曼树
    for(int i = n; i < m; i++){
        int s1, s2;
        Select(*HT, i, &s1, &s2); // 选择两个权值最小的节点
        (*HT)[s1].parent = (*HT)[s2].parent = i;
        (*HT)[i].lch = s1;
        (*HT)[i].rch = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
}

// 打印哈夫曼树
void PrintHuffmanTree(HuffmanTree HT, int m) {
    printf("\n哈夫曼树结构：\n");
    printf("结点  权值  父结点  左孩子  右孩子\n");
    for (int i = 0; i < m; i++) {
        printf("%-4d  %-4d  %-6d  %-6d  %-6d\n", 
               i, HT[i].weight, HT[i].parent, HT[i].lch, HT[i].rch);
    }
}

void CreatHuffmanCode(HuffmanTree HT , HuffmanCode &HC , int n){
    HC = new string[n]; // 创建哈夫曼编码数组
    stack<char> cd;
    for(int i = 0;i < n;i++){
        int start = n - 1; // 编码起始位置
        int c = i, f = HT[i].parent; // 当前结点和父结点
        while(f != -1){
            if(HT[f].lch == c) cd.push('0'); // 左孩子编码为0
            else cd.push('1'); // 右孩子编码为1
            c = f; // 更新当前结点
            f = HT[f].parent; // 更新父结点
        }
        while(!cd.empty()){
            HC[i] += cd.top(); // 取出栈顶元素
            cd.pop(); // 弹出栈顶元素
        }
    }
}

void PrintHuffmanCode(HuffmanCode HC, int n) {
    printf("\n哈夫曼编码：\n");
    for (int i = 0; i < n; i++) {
        printf("结点 %d: %s\n", i, HC[i].c_str()); // 打印哈夫曼编码
    }
}