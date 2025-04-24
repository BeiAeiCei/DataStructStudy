#include <stdio.h>
#include <stdlib.h> 
#include "E:\code\DataStructStudy\StudyCode\include\BitTree.h" // 包含二叉树的定义和函数声明

int main() {
    // 创建根节点并检查分配是否成功
    BitTree Head = createNode('H');
    if (Head == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }

    // 创建左子树
    Head->lchild = createNode('A');
    if (Head->lchild == NULL) {
        freeTree(Head);
        return 1;
    }
    Head->lchild->lchild = createNode('B'); // 左子节点的左孩子
    if (Head->lchild->lchild == NULL) {
        freeTree(Head);
        return 1;
    }
    Head->lchild->rchild = createNode('C'); // 左子节点的右孩子，data=0

    // 创建右子树
    Head->rchild = createNode('D');
    if (Head->rchild == NULL) {
        freeTree(Head);
        return 1;
    }
    Head->rchild->lchild = createNode('E');  // 右子节点的左孩子
    if (Head->rchild->lchild == NULL) {
        freeTree(Head);
        return 1;
    }
    Head->rchild->rchild = createNode('0'); // 右子节点的右孩子，data=0
    PreOder(Head); // 先序遍历输出树的节点值
    printf("\n");
    InOrder(Head); // 中序遍历输出树的节点值
    printf("\n");
    LastOrder(Head); // 后序遍历输出树的节点值
    printf("\n");
    PreOder_NonRec(Head); // 非递归先序遍历输出树的节点值
    printf("\n");
    InOrder_NonRec(Head); // 非递归中序遍历输出树的节点值
    printf("\n");
    LastOrder_NonRec(Head); // 非递归后序遍历输出树的节点值
    printf("\n");
    LevelOder(Head); // 层序遍历输出树的节点值
    printf("\n");
    
    BitTree Tree1 = NULL;
    create(&Tree1); // 创建二叉树
    PreOder(Tree1); // 先序遍历输出树的节点值

    BitTree Tree2 = NULL;
    copy(Tree1, &Tree2); // 复制二叉树
    printf("\nnew node:\n");
    LevelOder(Tree2); // 层序遍历输出复制的树的节点值

    BiThrTree Th = NULL;
    BiThrTree pre = NULL; // 前驱节点初始化为 NULL
    pre_thread(Th, &pre); // 先序线索化二叉树
    PreOder_Thr(Th); // 中序线索遍历输出树的节点值
    printf("\n");

    // 释放所有内存
    freeTree(Tree1); // 释放原树的内存
    freeTree(Tree2); // 释放复制树的内存
    freeTree(Head);
    return 0;
}