#include <bits/stdc++.h>

using namespace std;
#define ElemType int // 定义元素类型为int

typedef struct {
    ElemType *elem;
    int Tablelen;
} SSTable;

int BS(SSTable L , ElemType key){
    int low = 0 , high = L.Tablelen - 1 , mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(L.elem[mid] == key){
            return mid; // 找到元素，返回下标
        } else if(L.elem[mid] < key){
            low = mid + 1; // 在右半部分继续查找
        } else {
            high = mid - 1; // 在左半部分继续查找
        }
    }
    return -1; // 如果未找到元素，返回-1
}

int main(){
    SSTable L;
    L.Tablelen = 10; // 假设表长为10
    L.elem = new ElemType[L.Tablelen]; // 动态分配内存
    for(int i = 0; i < L.Tablelen; i++){
        L.elem[i] = i * 2; // 初始化元素为偶数
    }
    
    ElemType key = 6; // 要查找的元素
    int index = BS(L, key);
    
    if(index != -1){
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }
    
    delete[] L.elem; // 释放动态分配的内存
    return 0;
}