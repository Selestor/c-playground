#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct List* newListNode(int i) {
    struct List *node = malloc(sizeof(struct List));

    if (node == NULL) {
        // handle malloc fail
        return NULL;
    }

    node->val = i;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void printListFromHead(struct List *head) {
    struct List *current = head;

    while (current->next != head) {
        printf("previous value=%d, value=%d, next value=%d\n",current->prev->val, current->val, current->next->val);
        current = current->next;
    }
    printf("previous value=%d, value=%d, next value=%d\n",current->prev->val, current->val, current->next->val);
    printf("List printed from head!\n\n");
}

void printListFromTail(struct List *tail) {
    struct List *current = tail;

    while (current->prev != tail) {
        printf("previous value=%d, value=%d, next value=%d\n",current->prev->val, current->val, current->next->val);
        current = current->prev;
    }
    printf("previous value=%d, value=%d, next value=%d\n",current->prev->val, current->val, current->next->val);
    printf("List printed from tail!\n\n");
}

struct List* newList(int length) {
    struct List *head = newListNode(0);
    struct List *current = head;
    struct List *node = NULL;
    int i;

    if (head == NULL) {
        // handle malloc fail
        return NULL;
    }

    for (i = 1; i < length; i++) {
        node = newListNode(i);
        
        if (node == NULL) {
            // handle malloc fail, free whatever was allocated up to this point
            freeList(head);
            return NULL;
        } 

        node->prev = current;
        current->next = node;
        current = node;
    }
    current->next = head;
    head->prev = current;
    return head;
}

struct List* findListValue(struct List *head, int value) {
    struct List *current = head;
    struct List *searchedNode = NULL;

    while (current->next != head) {
        if (current->val == value) {
            searchedNode = current;
            printf("Searched node found! Node value=%d\n", searchedNode->val);
            return searchedNode;
        }
        current = current->next;
    }
    printf("Searched node could not be located.\n");
    return NULL;
}

void removeListNode(struct List *head, int value) {
    struct List *nodeToRemove = findListValue(head, value);
    struct List *prevNode = NULL;
    struct List *nextNode = NULL;

    if (nodeToRemove) {
        printf("Node located, removing...");
        prevNode = nodeToRemove->prev;
        nextNode = nodeToRemove->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        free(nodeToRemove);
        printf("Node was removed successfully!\n");
    }
}

void addListNode(struct List *head, int newValue) {
    struct List *newNode = newListNode(newValue);
    struct List *tail = head->prev;

    if (newNode == NULL) {
        // handle malloc fail
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

struct List* getListTail(struct List *head) {
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

void freeList(struct List *head) {
    struct List *tmp;

    if (head->prev != NULL) {
        head->prev->next = NULL;
        head->prev = NULL;
    }

    while (head != NULL) {
       tmp = head;
       head = head->next;
       printf("Freeing memory of a node value=%d...", tmp->val);
       free(tmp);
       printf("Done!\n");
    }
}