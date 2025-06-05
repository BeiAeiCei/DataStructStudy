#include <stdio.h>
#include <stdlib.h>
#include"DataStructStudy\StudyCode\include\Link.h"
#include "DataStructStudy\DataStructStudy\StudyCode\include\UTF-8.h"

int main(){
    struct Node *list = Init_Link();
    int num = 0;
    scanf("%d",&num);
    int caozuo = 0;
    int caozuodata = -1;
    int adddata = -1;
    struct Node *node = Create_Node(1);
    for(int i =0;i<num;i++){
        scanf("%d",&caozuo);
        switch (caozuo)
        {
        case 1:
            scanf("%d %d",&caozuodata, &adddata);
            Insert_Node(list,caozuodata,adddata);
            break;
        case 2:
            scanf("%d",&caozuodata);
            struct Node *P = list;
            while(P->next!= NULL){
                if(P->data == caozuodata && P->next!= NULL){
                    printf("%d\n",P->next->data);
                    break;
                }else if(P->next == NULL){
                    printf("0");
                    break;
                }
                P = P->next;
            }
            break;
        case 3:
            scanf("%d",&caozuodata);
            struct Node *P = list;
            while(P->next!= NULL){
                if(P->next->data == caozuodata){
                    break;
                }
                P = P->next;
            }
            if(P->next!= NULL){
                P->next = P->next->next;
            }
            break;
        }
    }
    return 0;
}