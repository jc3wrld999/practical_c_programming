#include "circular_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List *createList() {
  List *pList = (List *)malloc(sizeof(List));

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
  return 0;
}

