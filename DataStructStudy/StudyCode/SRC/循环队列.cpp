#include<iostream>
#define MAXSIZE 10
using namespace std;
// 结构体
typedef struct 
{
    int front;
    int rear;
    float *base;
}SqQueue;

// 初始化
void InitQueue(SqQueue &Q)
{
    Q.base = new float[MAXSIZE];
    if(!Q.base) exit;
    Q.front = Q.rear = 0;
    cout << "initial over" <<endl;

}
// 求长度
int QueueLenth(SqQueue Q){
    return ((Q.front - Q.rear + MAXSIZE) % MAXSIZE);
}
// 入队
void InQueue(SqQueue &Q , float e){
    if((Q.rear + 1)%MAXSIZE == Q.front){ 
        cout << " 队满" << endl;
        return; 
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) %MAXSIZE;
    cout << " 入队成功 " << endl;
}
// 出队
void OutQueue(SqQueue &Q , float &e){
    if(Q.front == Q.rear){
        cout << "队空" << endl;
        return;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front+1)%MAXSIZE;
    cout << "出队成功" <<endl;
}
 
int main(){
    SqQueue Q;
    InitQueue(Q);
    for(int i = 0;i<10;i++){
        InQueue(Q , (float)i);
    }
    float output = 0.0;
    for(int i = 0;i<QueueLenth(Q); i++){
        OutQueue(Q , output);
        cout << output << endl;
    }
    return 0;
}