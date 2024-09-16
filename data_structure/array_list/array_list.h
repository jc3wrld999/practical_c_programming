
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

typedef struct ListNodeType {
  int data;
} ListNode;

typedef struct ListType {
  int capacity;
  int size;
  ListNode *pElement;
} List;

List *createList(int);
void deleteList(List *);
int isFull(List *);
int addElement(List *, int, int);
int removeElement(List *, int);
ListNode *getElement(List *, int);
void displayList(List *);
void clearList(List *);
int getListLength(List *);

#endif