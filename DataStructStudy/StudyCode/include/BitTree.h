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

// 中序遍历
void InOrder(BitTree T){
    if(T == NULL) return; // 递归基：空树
    InOrder(T->lchild); // 遍历左子树
    printf("%d ", T->data); // 访问根节点
    InOrder(T->rchild); // 遍历右子树
}

// 后序遍历
void LastOrder(BitTree T){
    if(T == NULL)return; // 递归基：空树
    LastOrder(T->lchild); // 遍历左子树
    LastOrder(T->rchild); // 遍历右子树
    printf("%d ", T->data); // 访问根节点

}

// 非递归先序遍历
void PreOder_NonRec(BitTree T){
    if(T == NULL) return; // 递归基：空树
    BitTree stack[100]; // 假设树的深度不超过100
    int top = -1; // 栈顶指针
    stack[++top] = T; // 将根节点压入栈中
    while(top != -1){ // 栈不为空
        BitTree node = stack[top--]; // 弹出栈顶节点
        printf("%d ", node->data);   // 访问节点
        if(node->rchild != NULL) stack[++top] = node->rchild; // 先压右子树，后压左子树
        if(node->lchild != NULL) stack[++top] = node->lchild;
    }
}
// 非递归中序遍历
void InOrder_NonRec(BitTree T){
    if(T == NULL) return;
    BitTree stack[100]; // 假设树的深度不超过100
    int top = -1; // 栈顶指针
    BitTree current = T; // 当前节点指针
    while(current || top != -1){ // 栈不为空或当前节点不为空
        while(current){ // 遍历到最左节点
            stack[++top] = current; // 压入栈
            current = current->lchild; // 移动到左子树
        }
        if(top != -1){ // 栈不为空
            current = stack[top--]; // 弹出栈顶节点
            printf("%d ", current->data); // 访问节点
            current = current->rchild; // 移动到右子树
        }
    }
}
// 非递归后序遍历
void LastOrder_NonRec(BitTree T){
    if(T == NULL) return;
    BitTree stack[100]; // 假设树的深度不超过100
    int top = -1; // 栈顶指针
    BitTree current = T; // 当前节点指针
    BitTree lastVisited = NULL; // 上一个访问的节点
    while(current || top != -1){ // 栈不为空或当前节点不为空
        while(current){ // 遍历到最左节点
            stack[++top] = current; // 压入栈
            current = current->lchild; // 移动到左子树
        }
        if(top != -1){ // 栈不为空
            current = stack[top]; // 查看栈顶节点
            if(current->rchild == NULL || current->rchild == lastVisited){ // 右子树为空或已访问过
                printf("%d ", current->data); // 访问节点
                lastVisited = stack[top--]; // 弹出栈顶节点并更新上一个访问的节点
                current = NULL; // 重置当前节点
            } else {
                current = current->rchild; // 移动到右子树
            }
        }
    }
}
// 层次遍历
void LevelOder(BitTree T){
    if(T == NULL) return; // 递归基：空树
    BitTree queue[100]; // 假设树的深度不超过100
    int front = 0, rear = 0; // 队列指针
    queue[rear++] = T; // 将根节点入队
    while(front != rear){ // 队列不为空
        BitTree node = queue[front++]; // 出队
        printf("%d ", node->data); // 访问节点
        if(node->lchild != NULL) queue[rear++] = node->lchild; // 左子树入队
        if(node->rchild != NULL) queue[rear++] = node->rchild; // 右子树入队
    }
}