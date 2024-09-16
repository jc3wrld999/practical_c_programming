#include <stdio.h>
#include "array_list.h"

int main(void) {
  List *pList;
  pList = createList(10);

  if(pList != NULL) {

    addElement(pList, 0, 100);
    addElement(pList, 1, 200);
    addElement(pList, 2, 300);
    addElement(pList, 0, 50);
    addElement(pList, 0, 25);
    addElement(pList, 0, 5);

    displayList(pList);

    removeElement(pList, 0);
    displayList(pList);

    removeElement(pList, 2);
    displayList(pList);

    clearList(pList);

    displayList(pList);

    deleteList(pList);
  }

  return 0;
}

