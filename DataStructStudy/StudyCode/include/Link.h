#pragma once
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;// 数据域
    struct Node *next;// 指针域
};
// 初始化链表
struct Node *Init_Link()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    return head;
}
// 创建节点
struct Node *Create_Node(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
// 插入节点
void Insert_Node(struct Node *head, int oldval, int newval)
{
    struct Node *preP = head;
    struct Node *nextP = head->next;
    while(nextP!=NULL){
        if(nextP->data == oldval){
            break;
        }
        preP = nextP;
        nextP = nextP->next;
    }
    if(nextP == NULL){
        printf("未找到值为%d的节点\n",oldval);
        return;
    }else{
        struct Node *newNode = Create_Node(newval);
        preP->next = newNode;
        newNode->next = nextP;
    }
}
// 删除节点
void Delete_Link(struct Node *head,int deleteval){
    struct Node *findP = head;
    while(findP->next!= NULL){
        if(findP->next->data == deleteval){
            break;
        }
        findP = findP->next;
    }
    if(findP->next == NULL){
        printf("未找到值为%d的节点\n",deleteval);
        return;
    }else{
        struct Node* temp = findP->next;
        findP->next = findP->next->next;
        free(temp);
    }
}
// 打印链表
void Print_link(struct Node *head){
    struct Node *p = head->next;
    while(p!=NULL){
        printf("%d\n",p->data);
        p = p->next;
    }
}
