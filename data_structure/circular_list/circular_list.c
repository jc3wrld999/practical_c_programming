#include "circular_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List *createList() {
  List *pList = (List *)malloc(sizeof(List));
  if(pList == NULL)
    return NULL;

  memset(pList, 0, sizeof(List));
  pList->size = 0;
  pList->pLink = NULL;
  return pList;
}

void deleteList(List *pList) {
  if(pList == NULL)
    return;
  clearList(pList);
  free(pList);
}

int addElement(List *pList, int position, int data) {
  if(pList == NULL)
    return FALSE;
  if(position < 0 || position > getListLength(pList))
    return FALSE;

  ListNode *pNewNode = (ListNode *)malloc(sizeof(ListNode));
  if(pNewNode == NULL)
    return FALSE;
  pNewNode->data = data;

  ListNode *pPreNode = NULL, *pLastNode;

  if(position == 0) {
    if(getListLength(pList) == 0) {
      pList->pLink = pNewNode;
      pNewNode->pLink = pNewNode;
    } else {
      pLastNode = pList->pLink;
      while (pLastNode->pLink != pList->pLink) n{
          pLastNode = pLastNode

