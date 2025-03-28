#include <stdio.h>
#include <stdlib.h>

// ******************************** // 
// 对角线对称矩阵
void compresssymmetricGEMM(float **a, int n, float *compressed) 
{
    int totalelements = n*(n+1)/2;
    compressed = (float*)malloc(totalelements * sizeof(float));
    int idx = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            compressed[idx++] = a[i][j];
        }
    }
}
// ******************************** // 


// ******************************** // 
// 上三三角形 ... 下三角形同理
float* compressUpperTriangle(float** matrix, int n) {
    int totalElements = n * (n + 1) / 2 + 1;
    float* compressed = (float*)malloc(totalElements * sizeof(float));

    int k = 0;
    for (int j = 0; j < n; j++) { // 按列遍历
        for (int i = 0; i <= j; i++) { // 遍历列中的上三角部分
            compressed[k++] = matrix[i][j];
        }
    }
    compressed[k] = matrix[0][1];
    return compressed;
}
// ******************************** // 

// ******************************** // 
// 对角矩阵
float* compressDiagonal(float** matrix, int n) {
    float* compressed = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        compressed[i] = matrix[i][i]; // 仅存储对角线元素
    }
    return compressed;
}
// ******************************** // 


// ******************************** // 
#define MAX_SIZE 100
// 稀疏矩阵
typedef struct {
    int row;
    int col;
    int value;
} Triple;

// 稀疏矩阵结构体
typedef struct {
    int rows;
    int cols;
    int non_zero;
    Triple data[MAX_SIZE];
} SparseMatrix;
void convertToTriplet(int matrix[][MAX_SIZE], int rows, int cols, SparseMatrix *sparse) {
    int count = 0;
    sparse->rows = rows;
    sparse->cols = cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse->data[count].row = i;
                sparse->data[count].col = j;
                sparse->data[count].value = matrix[i][j];
                count++;
            }
        }
    }
    sparse->non_zero = count;
}

// 打印三元组
void printTriplet(SparseMatrix *sparse) {
    printf("Rows: %d, Cols: %d, Non-zero elements: %d\n", sparse->rows, sparse->cols, sparse->non_zero);
    for (int i = 0; i < sparse->non_zero; i++) {
        printf("Row: %d, Col: %d, Value: %d\n", sparse->data[i].row, sparse->data[i].col, sparse->data[i].value);
    }
}
// ******************************** //
