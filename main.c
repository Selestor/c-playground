#include "List.h"
#include <stdio.h>

int main() {
    struct List *head = newList(10);
    struct List *tail = getListTail(head);
    
    printListFromHead(head);
    printListFromTail(tail);

    removeListNode(head, 5);
    printListFromHead(head);

    addListNode(head, 15);
    printListFromHead(head);
    tail = getListTail(head);
    printListFromTail(tail);

    freeList(head);

    printf("Success!");
    return 0;
} 