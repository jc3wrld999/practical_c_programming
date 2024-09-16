#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main(void)
{
    Person *p = person_create("sungju", 27);
    printf("%s, %d\n", p->get_name(p), p->get_age(p));
    free(p);
}