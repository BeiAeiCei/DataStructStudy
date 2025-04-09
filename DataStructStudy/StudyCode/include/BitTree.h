#include <stdlib.h>
#include <stdio.h>

typedef struct BitNode {
    int data;
    struct BitNode *lchild, *rchild;
}BitNode, *BitTree;

// 辅助函数：安全创建并初始化节点
BitTree createNode(int data) {
    BitTree node = (BitTree)malloc(sizeof(BitNode));
    if (node != NULL) {
        node->data = data;
        node->lchild = node->rchild = NULL; // 初始化子节点指针
    }
    return node;
}

// 辅助函数：递归释放树内存
void freeTree(BitTree root) {
    if (root == NULL) return;
    freeTree(root->lchild);
    freeTree(root->rchild);
    free(root);
}
// 先序遍历
void PreOder(BitTree T){
    if (T == NULL) return; // 递归基：空树
    printf("%d ", T->data); // 访问根节点
    PreOder(T->lchild); // 遍历左子树
    PreOder(T->rchild); // 遍历右子树
}