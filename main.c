#include "List.c"
#include <stdio.h>

int main() {
    struct List *head = newList(10);
    printListFromHead(head);
    struct List *tail = getListTail(head);
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