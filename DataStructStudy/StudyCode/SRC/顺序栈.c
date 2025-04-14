#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100 // �����������
// GB 2312
// ����ջ�Ľṹ��
typedef struct Stack {
    int data[MAX_SIZE]; // ˳��ջ��������ʵ��
    int top; // ջ��ָ��
    int base; // ջ��ָ��
} Stack;

// ��ʼ��ջ
void InitialStack(Stack *S){
    S->top = 0;
    S->base = 0;
}

// �ж�ջ�Ƿ��
bool IsEmpty(Stack *S){
    if(S->top == S->base){
        printf("ջ��\n");
        return true;
    }
    return false;
}
// �ж�ջ�Ƿ���
bool IsFull(Stack *S){
    if(S->top == MAX_SIZE){
        printf("ջ��\n");
        return true;
    }
    return false;
}

// ��ջ
void Push(Stack *S , int e){
    if(!IsFull(S)){
        S->data[S->top] = e;
        S->top++;
        printf("��ջ�ɹ�\n");
    }else{
        printf("��ջʧ�ܣ�ջ��\n");
    }
}

// ��ջ
void Pop(Stack *S , int* e){
    if(!IsEmpty(S)){
        S->top--;
        *e = S->data[S->top];
        printf("��ջ�ɹ� ");
    }else{
        printf("ջ�գ���ջʧ��\n");
    }
}

// ��ȡջ��Ԫ��
int GetTop(Stack *S){
    if(!IsEmpty(S)){
        return S->data[S->top-1];
    }else{
        printf("ջ��\n");
        return -1;
    }
}

int main(){
    Stack S;
    InitialStack(&S); 
    int e = 0;
    for(int i = 0; i < 10; i++){
        Push(&S , i); 
    }
    printf("ջ��Ԫ��Ϊ %d\n", GetTop(&S));
    for(int i = 0; i < 10; i++){
        Pop(&S , &e);
        printf("%d\n", e);
    }
    
    return 0;
}

