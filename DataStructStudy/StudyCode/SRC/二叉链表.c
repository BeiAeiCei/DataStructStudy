#include <stdio.h>
#include <stdlib.h> 
#include "E:\code\DataStructStudy\StudyCode\include\BitTree.h" // 包含二叉树的定义和函数声明

int main() {
    // 创建根节点并检查分配是否成功
    BitTree Head = createNode(1);
    if (Head == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }

    // 创建左子树
    Head->lchild = createNode(2);
    if (Head->lchild == NULL) {
        freeTree(Head);
        return 1;
    }
    Head->lchild->lchild = createNode(4); // 左子节点的左孩子
    if (Head->lchild->lchild == NULL) {
        freeTree(Head);
        return 1;
    }
    Head->lchild->rchild = createNode(0); // 左子节点的右孩子，data=0

    // 创建右子树
    Head->rchild = createNode(3);
    if (Head->rchild == NULL) {
        freeTree(Head);
        return 1;
    }
    Head->rchild->lchild = createNode(5);  // 右子节点的左孩子
    if (Head->rchild->lchild == NULL) {
        freeTree(Head);
        return 1;
    }
    Head->rchild->rchild = createNode(0); // 右子节点的右孩子，data=0
    PreOder(Head); // 先序遍历输出树的节点值
    // 释放所有内存
    freeTree(Head);
    return 0;
}