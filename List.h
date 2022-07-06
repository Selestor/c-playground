#ifndef LIST_HEADER
#define LIST_HEADER

struct List {
    int val;
    struct List *next;
    struct List *prev;
};

struct List* newListNode(int i);
void printListFromHead(struct List *head);
void printListFromTail(struct List *tail);
struct List* newList(int length);
struct List* findListValue(struct List *head, int value);
void removeListNode(struct List *head, int value);
void addListNode(struct List *head, int newValue);
struct List* getListTail(struct List *head);
void freeList(struct List *head);

#endif