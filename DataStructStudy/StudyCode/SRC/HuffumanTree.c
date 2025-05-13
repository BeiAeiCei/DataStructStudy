#include <stdio.h>
#include "E:\code\study\data-struct-study-1\DataStructStudy-1\DataStructStudy\StudyCode\include\HuffmanTree.h"
#include "E:\code\study\data-struct-study-1\DataStructStudy-1\DataStructStudy\StudyCode\include\UTF-8.h"
int main(){
    HuffmanTree HT;
    int n;
    printf("请输入结点数：");
    scanf("%d",&n);
    CreatHUFFMANTree(&HT,n); // 创建哈夫曼树
    PrintHuffmanTree(HT, 2*n-1); // 打印哈夫曼树
    free(HT); // 释放内存
    return 0;

}