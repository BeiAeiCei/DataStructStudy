#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100 // 定义最大容量
// GB 2312
// 定义栈的结构体
typedef struct Stack {
    int data[MAX_SIZE]; // 顺序栈是由数组实现
    int top; // 栈顶指针
    int base; // 栈底指针
} Stack;

// 初始化栈
void InitialStack(Stack *S){
    S->top = 0;
    S->base = 0;
}

// 判断栈是否空
bool IsEmpty(Stack *S){
    if(S->top == S->base){
        printf("栈空\n");
        return true;
    }
    return false;
}
// 判断栈是否满
bool IsFull(Stack *S){
    if(S->top == MAX_SIZE){
        printf("栈满\n");
        return true;
    }
    return false;
}

// 入栈
void Push(Stack *S , int e){
    if(!IsFull(S)){
        S->data[S->top] = e;
        S->top++;
        printf("入栈成功\n");
    }else{
        printf("入栈失败，栈满\n");
    }
}

// 出栈
void Pop(Stack *S , int* e){
    if(!IsEmpty(S)){
        S->top--;
        *e = S->data[S->top];
        printf("出栈成功 ");
    }else{
        printf("栈空，出栈失败\n");
    }
}

// 获取栈顶元素
int GetTop(Stack *S){
    if(!IsEmpty(S)){
        return S->data[S->top-1];
    }else{
        printf("栈空\n");
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
    printf("栈顶元素为 %d\n", GetTop(&S));
    for(int i = 0; i < 10; i++){
        Pop(&S , &e);
        printf("%d\n", e);
    }
    
    return 0;
}

