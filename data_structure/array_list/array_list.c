#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List *createList(int capacity) {
  List *pList = (List *)malloc(sizeof(List));
  if (pList == NULL)
    return NULL;

  pList->capacity = capacity;
  pList->size = 0;

  pList->pElement = (ListNode *)malloc(sizeof(ListNode) * capacity);
  if(pList->pElement == NULL) {
    free(pList);
    return NULL;
  }

  memset(pList->pElement, 0, sizeof(ListNode) * capacity);

  return pList;

}

void deleteList(List *pList) {
  if (pList != NULL) {
    clearList(pList);
    free(pList);
  }
}

int isFull(List *pList) {
  if(pList == NULL)
    return TRUE;
  if(getListLength(pList) == pList->capacity)
    return TRUE;

  return FALSE;
}

int addElement(List *pList, int position, int data) {
  if(pList == NULL)
    return FALSE;
  if(isFull(pList) == TRUE)
    return FALSE;
  if(position < 0 || position > pList->size)
    return FALSE;

  // 하나씩 밀림
  for (int i = getListLength(pList); i >= position; i--) {
    pList->pElement[i + 1] = pList->pElement[i];
  }

  ListNode element;
  element.data = data;

  pList->pElement[position] = element;
  pList->size++;
  return TRUE;
}

int removeElement(List *pList, int position) {
  if(pList == NULL)
    return FALSE;
  if(position < 0 || position >= getListLength(pList))
    return FALSE;

  for(int i = position + 1;i < getListLength(pList); i++) {
    pList->pElement[i - 1] = pList->pElement[i];
  }
  pList->size--;

  return TRUE;
}

ListNode *getElement(List *pList, int position) {
  ListNode *pNode = NULL;
  if(pList == NULL)
    return pNode;
  if(position < 0 || position > getListLength(pList))
    return pNode;

  pNode = &(pList->pElement[position]);
  return pNode;
}

void displayList(List *pList) {

  ListNode *pNode;
  for (int i = 0; i < getListLength(pList); i++) {
    pNode = getElement(pList, i);
    if (pNode != NULL)
      printf("%d ", pNode->data);
  }
  printf("\n");
}

void clearList(List *pList) {
  if(pList != NULL)
    free(pList->pElement);
  pList->size = 0;
}

int getListLength(List *pList) {
  if(pList == NULL)
    return 0;
  return pList->size;
}


