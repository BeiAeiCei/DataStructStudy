#include <stdio.h>
#include <string.h>

int main()
{
    char A[10] = "mmdhellof";
    char B[6] = "hello";
    int Alenth = strlen(A);
    int Blenth = strlen(B);
    for (int i = 0; i <= Alenth - Blenth; i++) {
        int j;
        for (j = 0; j < Blenth; j++) {
            if(A[i+j] != B[j]) {
                break;
            }
        }
        if (j == Blenth) {
            printf("find it in %d\n", i+1);
            return 0;
        }
    }
    printf("not found\n");
    return 0;
}