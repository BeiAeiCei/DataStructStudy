#include<bits/stdc++.h>
using namespace std;

/* 
Hello!
The char 'a' does not exist.
Hll!
Holl!
The first node: 6421968, 6421968, 6421984
The second node: 6421936, 6421936, 6421952
*/

typedef struct DoubleLinkedNode{
    char data;
    struct DoubleLinkedNode *previous;
    struct DoubleLinkedNode *next;
} DLNode, *DLNodePtr;
DLNodePtr initLinkList(){
    DLNodePtr tempHeader = (DLNodePtr)malloc(sizeof(struct DoubleLinkedNode));
    tempHeader->data = '\0';
    tempHeader->previous = NULL;
    tempHeader->next = NULL;
    return tempHeader;
}
void printList(DLNodePtr paraHeader){
    DLNodePtr p = paraHeader->next;
    while (p != NULL) {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\r\n");
}
void insertElement(DLNodePtr paraHeader, char paraChar, int paraPosition){
    DLNodePtr p, q, r;
    p = paraHeader;
    for (int i = 0; i < paraPosition; i ++) {
        p = p->next;
        if (p == NULL) {
            printf("The position %d is beyond the scope of the list.", paraPosition);
            return;
        }
    }
    q = (DLNodePtr)malloc(sizeof(struct DoubleLinkedNode));
    q->data = paraChar;
    r = p->next;
    q->next = p->next;
    q->previous = p;
    p->next = q;
    if (r != NULL) {
        r->previous = q;
    }
}
void deleteElement(DLNodePtr paraHeader, char paraChar){
    DLNodePtr p, q, r;
    p = paraHeader;
    while ((p->next != NULL) && (p->next->data != paraChar)){
        p = p->next;
    }
    if (p->next == NULL) {
        printf("The char '%c' does not exist.\r\n", paraChar);
        return;
    }
    q = p->next;
    r = q->next;
    p->next = r;
    if (r != NULL) {
        r->previous = p;
    }
    free(q);
}
void insertDeleteTest(){
    DLNodePtr tempList = initLinkList();
    printList(tempList);
    insertElement(tempList, 'H', 0);
    insertElement(tempList, 'e', 1);
    insertElement(tempList, 'l', 2);
    insertElement(tempList, 'l', 3);
    insertElement(tempList, 'o', 4);
    insertElement(tempList, '!', 5);
    printList(tempList);
    deleteElement(tempList, 'e');
    deleteElement(tempList, 'a');
    deleteElement(tempList, 'o');
    printList(tempList);
    insertElement(tempList, 'o', 1);
    printList(tempList);
}
void basicAddressTest(){
    DLNode tempNode1, tempNode2;

    tempNode1.data = 4;
    tempNode1.next = NULL;

    tempNode2.data = 6;
    tempNode2.next = NULL;

    printf("The first node: %d, %d, %d\r\n",
        &tempNode1, &tempNode1.data, &tempNode1.next);
    printf("The second node: %d, %d, %d\r\n",
        &tempNode2, &tempNode2.data, &tempNode2.next);

    tempNode1.next = &tempNode2;
}
int main(){
    insertDeleteTest();
    basicAddressTest();
    return 0;
}
