#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSprt(int A[]){
    int n = sizeof(A) / sizeof(A[0]);   // 获取数组长度
    bool swapped;                       // 标记是否发生交换
    for (int i = 0; i < n - 1; i++) {
        swapped = false;                
        for (int j = n-1; j > i; j-- ){ 
            if (A[j-1] > A[j]) { 
                swap(A[j-1], A[j]); // 交换两个元素
                swapped = true; // 标记发生了交换
            }
        }
        if (!swapped) return; // 如果没有发生交换，说明数组已排序，提前结束
    }
}

void InsertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // 将大于key的元素向后移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // 插入key到正确位置
        arr[j + 1] = key;
    }
}


void ShellSort(int A[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) { // 初始增量为n/2
        for (i = gap; i < n; i++) { // 从gap开始到n
            temp = A[i]; // 保存当前元素
            j = i;
            // 将大于temp的元素向后移动
            while (j >= gap && A[j - gap] > temp) {
                A[j] = A[j - gap];
                j -= gap;
            }
            A[j] = temp; // 插入temp到正确位置
        }
    }

}


int Partition(int A[] , int low , int high){
    int pivot = A[low]; // 选择第一个元素作为基准
    while(low < high){
        while(low < high && A[high] >= pivot) high--; // 从右向左找到第一个大于pivot的元素
        A[low] = A[high]; // 将该元素放到low位置
        while(low < high && A[low] <= pivot) low++; // 从左向右找到第一个小于pivot的元素
        A[high] = A[low]; // 将该元素放到high位置
    }
    A[low] = pivot; // 将基准元素放到正确位置
    return low; // 返回基准元素的最终位置
}

void QuickSort(int A[] , int low , int high){
    if(low < high){
        int pivotIndex = Partition(A, low, high); // 获取基准元素的索引
        QuickSort(A, low, pivotIndex - 1); // 对基准左侧进行快速排序
        QuickSort(A, pivotIndex + 1, high); // 对基准右侧进行快速排序
    }
}


// 堆排序
// 构建最大堆
void BuildMaxHeap(int A[] , int len){
    for(int i = len/2;i>0;i--){
        HeadAdjust(A,i,len);
    }
}

// 调整堆
// A[]为堆数组，k为当前节点的索引，len为堆的长度
void HeadAdjust(int A[] , int k, int len){
    A[0] = A[k];
    for(int i = 2*k; i <= len; i *= 2){     // 从k的左子节点开始
        if(i < len && A[i] < A[i + 1]) i++; // 如果右子节点存在且大于左子节点，则选择右子节点
        if(A[0] >= A[i]) break;             // 如果父节点大于等于子节点，结束调整
        A[k] = A[i];                        // 将子节点上移
        k = i; // 更新k为当前子节点
    }
        A[k] = A[0]; // 将父节点放到正确位置
}


void HeapSort(int A[], int len){
    BuildMaxHeap(A, len); // 构建最大堆
    for(int i = len; i > 1; i--){ // 从最后一个元素开始
        swap(A[1], A[i]); // 将最大元素放到末尾
        HeadAdjust(A, 1, i - 1); // 调整堆
    }
}