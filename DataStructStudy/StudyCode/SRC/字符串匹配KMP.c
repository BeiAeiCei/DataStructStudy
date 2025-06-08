#include <stdio.h>
#include <string.h>
#include "DataStructStudy\StudyCode\include\UTF-8.h"

// UTF-8
// j是当前匹配串的移动位置，next[j]是当前匹配串的最长公共前后缀长度
// 计算next数组
// C A B A B
void computeNext(char* pattern, int* next) {
    int len = strlen(pattern);
    int j = 0;
    next[0] = 0;

    for (int i = 1; i < len; i++) {
        if (j>0 &&  pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
}

// KMP 搜索函数
int kmpSearch(char* text, char* pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int next[patternLen];

    // 计算 next 数组
    computeNext(pattern, next);

    int j = 0;
    for (int i = 0; i < textLen; i++) {
        if (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == patternLen) {
            return i - patternLen + 1; // 找到匹配，返回匹配的起始位置
        }
    }
    return -1; // 未找到匹配
}


int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "BDABA";

   
    if (kmpSearch(text, pattern)) {
        printf("Pattern found at index %d\n", kmpSearch(text, pattern));
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}    