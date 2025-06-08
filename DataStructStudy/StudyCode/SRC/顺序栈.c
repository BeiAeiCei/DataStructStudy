#include<stdio.h>
#include<stdbool.h>
#include "DataStructStudy\StudyCode\include\UTF-8.h"

#define MAX_SIZE 100 // 

typedef struct Stack {
    int data[MAX_SIZE]; 
    int top; 
    int base; 
} Stack;

// 
void InitialStack(Stack *S){
    S->top = 0;
    S->base = 0;
}


bool IsEmpty(Stack *S){
    if(S->top == S->base){
        printf("???\n");
        return true;
    }
    return false;
}

bool IsFull(Stack *S){
    if(S->top == MAX_SIZE){
        printf("???\n");
        return true;
    }
    return false;
}


void Push(Stack *S , int e){
    if(!IsFull(S)){
        S->data[S->top] = e;
        S->top++;
        printf("??????\n");
    }else{
        printf("??????????\n");
    }
}

// ???
void Pop(Stack *S , int* e){
    if(!IsEmpty(S)){
        S->top--;
        *e = S->data[S->top];
        printf("?????? ");
    }else{
        printf("??????????\n");
    }
}

// ?????????
int GetTop(Stack *S){
    if(!IsEmpty(S)){
        return S->data[S->top-1];
    }else{
        printf("???\n");
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
    printf("??????? %d\n", GetTop(&S));
    for(int i = 0; i < 10; i++){
        Pop(&S , &e);
        printf("%d\n", e);
    }
    
    return 0;
}

