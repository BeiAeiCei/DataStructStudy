#include <stdlib.h>
#include <stdio.h>

typedef struct BitNode {
    char data;
    struct BitNode *lchild, *rchild;
}BitNode, *BitTree;

typedef struct BiThrNode{
    char data;
    struct BiThrNode *lchild, *rchild;
    int ltag, rtag; // 0表示指向孩子，1表示指向前驱或后继
}BiThrNode, *BiThrTree;

// 辅助函数：安全创建并初始化节点
BitTree createNode(char data) {
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
    printf("%c", T->data); // 访问根节点
    PreOder(T->lchild); // 遍历左子树
    PreOder(T->rchild); // 遍历右子树
}

void PreOder_Thr(BiThrTree T) {
    if (T == NULL) return;
    printf("%c", T->data); // 访问根节点

    // 如果左子节点是孩子节点（ltag == 0），递归遍历左子树
    if (T->ltag == 0) {
        PreOder_Thr(T->lchild);
    }

    // 如果右子节点是孩子节点（rtag == 0），递归遍历右子树
    if (T->rtag == 0) {
        PreOder_Thr(T->rchild);
    }
}

// 中序遍历
void InOrder(BitTree T){
    if(T == NULL) return; // 递归基：空树
    InOrder(T->lchild); // 遍历左子树
    printf("%c ", T->data); // 访问根节点
    InOrder(T->rchild); // 遍历右子树
}

// 后序遍历
void LastOrder(BitTree T){
    if(T == NULL)return; // 递归基：空树
    LastOrder(T->lchild); // 遍历左子树
    LastOrder(T->rchild); // 遍历右子树
    printf("%c ", T->data); // 访问根节点

}

// 非递归先序遍历
void PreOder_NonRec(BitTree T){
    if(T == NULL) return; // 递归基：空树
    BitTree stack[100]; // 假设树的深度不超过100
    int top = -1; // 栈顶指针
    stack[++top] = T; // 将根节点压入栈中
    while(top != -1){ // 栈不为空
        BitTree node = stack[top--]; // 弹出栈顶节点
        printf("%c ", node->data);   // 访问节点
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
            printf("%c ", current->data); // 访问节点
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
                printf("%c ", current->data); // 访问节点
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
        printf("%c ", node->data); // 访问节点
        if(node->lchild != NULL) queue[rear++] = node->lchild; // 左子树入队
        if(node->rchild != NULL) queue[rear++] = node->rchild; // 右子树入队
    }
}
// 先序创建二叉树
void create(BitTree *T) {
    char a;
    scanf(" %c", &a); // 注意前面的空格，用于跳过缓冲区中的换行符
    if (a == '#') {
        *T = NULL; // 如果输入为 '#'，表示空节点
    } else {
        *T = (BitNode *)malloc(sizeof(BitNode)); // 分配新节点
        if (*T == NULL) {
            printf("内存分配失败！\n");
            exit(1);
        }
        (*T)->data = a; // 将输入的字符赋值给节点的 data 成员
        create(&((*T)->lchild)); // 创建左子树
        create(&((*T)->rchild)); // 创建右子树
    }
}

// 复制二叉树
void copy(BitTree T,BitTree *Tn)
{
    if(T == NULL){
        return;
    }
    else{
        *Tn = (BitNode *)malloc(sizeof(BitNode)); // 分配新节点
        *Tn = createNode(T->data); // 复制节点数据
        copy(T->lchild,&((*Tn)->lchild)); // 递归复制左子树
        copy(T->rchild,&((*Tn)->rchild)); // 递归复制右子树
    }
}

// 计算二叉树结点总数
int NodeCount(BitTree T) {
    if (T == NULL) return 0; // 递归基：空树
    return 1 + NodeCount(T->lchild) + NodeCount(T->rchild); // 计算当前节点和左右子树的节点数
}

// 计算二叉树叶子结点总数
int LeafCount(BitTree T) {
    if (T == NULL) return 0; // 递归基：空树
    if (T->lchild == NULL && T->rchild == NULL) return 1; // 叶子节点
    return LeafCount(T->lchild) + LeafCount(T->rchild); // 计算左右子树的叶子节点数
}

// 计算二叉树的高度
int TreeHeight(BitTree T) {
    if (T == NULL) return 0; // 递归基：空树
    int leftHeight = TreeHeight(T->lchild); // 左子树高度
    int rightHeight = TreeHeight(T->rchild); // 右子树高度
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; // 返回较大高度加1
}

// 先序线索二叉树
static BiThrTree pre_thread(BiThrTree root, BiThrTree *pre) {
    if (root) {
        // 处理当前节点的前驱线索
        if (!root->lchild) {          // 左子节点为空，建立前驱线索
            root->lchild = *pre;
            root->ltag = 1;
        }
        // 处理前驱节点的后继线索（当前节点是前驱的后继）
        if (*pre && !(*pre)->rchild) {
            (*pre)->rchild = root;
            (*pre)->rtag = 1;
        }
        *pre = root;  // 更新前驱为当前节点
        
        // 先序遍历：左子树线索化前需要判断是否是子节点（避免线索循环）
        if (root->ltag == 0)  // 左指针是子节点，递归线索化左子树
            pre_thread(root->lchild, pre);
        // 右子树线索化（同样先判断是否是子节点）
        if (root->rtag == 0)  // 右指针是子节点，递归线索化右子树
            pre_thread(root->rchild, pre);
    }
    return root;
}

// 先序线索化二叉树
void preorder_thread(BiThrTree root) {
    BiThrTree pre = NULL;  // 前驱节点初始化为NULL
    pre_thread(root, &pre);  // 递归线索化
    // 处理最后一个节点的后继线索（指向NULL）
    if (pre) pre->rchild = NULL;
}
