#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct List {
    int val;
    struct List *next;
    struct List *prev;
};

struct List *newListNode(int i) {
        struct List *node = (struct List *)malloc(sizeof(struct List));
        node->val = i;
        node->next = NULL;
        node->prev = NULL;
        return node;
}

void printListFromHead(struct List *head) {
    struct List *current = head;
    printf("previous value=%d, value=%d, next value=%d\n", current->prev->val, current->val, current->next->val);
    current = current->next;
    while(current->next != head){
        printf("previous value=%d, value=%d, next value=%d\n",current->prev->val, current->val, current->next->val);
        current = current->next;
    }
    printf("previous value=%d, value=%d, next value=%d\n",current->prev->val, current->val, current->next->val);
    printf("List printed from head!\n\n");
}

void printListFromTail(struct List *tail) {
    struct List *current = tail;
    printf("previous value=%d, value=%d, next value=%d\n", current->prev->val, current->val, current->next->val);
    current = current->prev;
    while(current->prev != tail){
        printf("previous value=%d, value=%d, next value=%d\n",current->prev->val, current->val, current->next->val);
        current = current->prev;
    }
    printf("previous value=%d, value=%d, next value=%d\n",current->prev->val, current->val, current->next->val);
    printf("List printed from tail!\n\n");
}

struct List *newList(int length) {
    struct List *head = newListNode(0);
    struct List *current = head;
    for(int i = 1; i < length; i++) {
        struct List *node = newListNode(i);
        node->prev = current;
        current->next = node;
        current = node;
    }
    current->next = head;
    head->prev = current;
    return head;
}

struct List *findListValue(struct List *head, int value) {
    struct List *current = head;
    struct List *searchedNode = NULL;
    bool isFound = false;
    while(current->next != head) {
        if(current->val == value) {
            isFound = true;
            searchedNode = current;
            printf("Searched node found! Node value=%d\n", searchedNode->val);
            return searchedNode;
        }
        else {
            current = current->next;
        }
    }
    printf("Searched node could not be located.\n");
    return NULL;
}

void removeListNode(struct List *head, int value) {
    struct List *nodeToRemove = findListValue(head, value);
    if(nodeToRemove) {
        printf("Node located, removing...");
        struct List *prevNode = nodeToRemove->prev;
        struct List *nextNode = nodeToRemove->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        free(nodeToRemove);
        printf("Node was removed successfully!\n");
    }
}

struct List *getListTail(struct List *head) {
    // Tail for circular list is trivial? 
    return head->prev;
    /* This is tail for non-circular list
    struct List *tail = head;
    if(head->next != NULL) {
        tail = getListTail(head->next);
    }
    return tail;
    */
}