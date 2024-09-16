#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#define TRUE 1
#define FALSE 0

typedef struct ListNodeType {
  int data;
  struct ListNodeType *pLink;
} ListNode;

typedef struct ListType {
  int size;
  ListNode *pLink;
} List;

List *createList();
void deleteList(List *);
int addElement(List *, int, int);
int removeElment(List *, int);
ListNode *getElement(List *, int);
int getListLength(List *);
void displayList(List *);
void clearList(List *);

#endif //CIRCULAR_LIST_H