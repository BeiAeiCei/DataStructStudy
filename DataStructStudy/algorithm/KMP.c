#include <stdio.h>
#include <string.h>

void FindNext(char *pattern , int *next)
{
    int len = strlen(pattern);
    next[0] = 0;
    int j = 0;
    for(int i = 1;i<len;i++){
        if( j > 0 && pattern[i] != pattern[j]){
            j = next[j-1];
        }
        if( pattern[i] == pattern[j]){
            j++;
        }
        next[i] = j;
    }
}

int KMP(char *text , char *pattern)
{
    int textlen = strlen(text);
    int patternlen = strlen(pattern);
    int next[patternlen];

    FindNext(pattern , next);
    for(int i = 0;i<textlen;i++){
        int j = 0;
        if(j > 0 && pattern[j] != text[i]){
            j = next[j-1];
        }
        if(pattern[j] == text[i]){
            j++;
        }
        if(j == patternlen){
            return i - patternlen + 1;
        }  
    }
    return -1;
}
int main(){
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "CABAB";
    if(KMP(text , pattern) != -1){
        printf("Pattern found at index %d\n", KMP(text, pattern));
    }else{
        printf("Pattern not found\n");
    }
    return 0;
}