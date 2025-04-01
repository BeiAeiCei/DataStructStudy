#include <stdio.h>
#include <string.h>

// 计算 next 数组
void GetNext(char *p, int next[]) {
    int plen = strlen(p);
    next[0] = 0;
    int j = 0;
    for (int i = 1; i < plen; i++) {
        if (j > 0 && p[i] != p[j]) {
            j = next[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        next[i] = j;
    }
}

// KMP 搜索函数
int KmpSearch(char *txt, char *p) {
    int tlen = strlen(txt);
    int plen = strlen(p);
    int next[plen];
    GetNext(p, next);
    int j = 0;
    for (int i = 0; i < tlen; i++) {
        if (j > 0 && txt[i] != p[j]) {
            j = next[j - 1];
        }
        if (txt[i] == p[j]) {
            j++;
        }
        if (j == plen) {
            return (i - plen + 1);
        }
    }
    return -1;
}

int main() {
    char *txt = "CAAACBCAACBBCAC";
    char p[100];
    scanf("%s", p);
    int lenp = strlen(p);
    char temp[2 * lenp + 1];
    temp[0] = '\0';  // 初始化 temp 数组

    strcat(temp, p);
    strcat(temp, p);
    printf("temp: %s\n", temp);
    int found = 0;
    for (int i = 0; i < lenp; i++) {
        char shifted_pattern[lenp + 1];
        strncpy(shifted_pattern, temp + i, lenp);
        shifted_pattern[lenp] = '\0';

        int index = KmpSearch(txt, shifted_pattern);
        if (index != -1) {
            printf("Pattern found at index %d\n", index);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Pattern not found\n");
    }

    return 0;
}