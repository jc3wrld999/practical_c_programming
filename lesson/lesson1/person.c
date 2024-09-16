#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

char *person_get_name(Person *p)
{
    return p->name;
}

void person_set_name(Person *p, const char *name)
{
    strncpy(p->name, name, sizeof(p->name)-1);
    p->name[sizeof(p->name)-1] = '\0';
}

int person_get_age(Person *p)
{
    return p->age;
}

void person_set_age(Person *p, int age)
{
    p->age = age;
}

void person_init(Person *p, const char *name, int age)
{
    p->init = person_init;
    
    p->get_name = person_get_name;
    p->get_age = person_get_age;
    p->set_name = person_set_name;
    p->set_age = person_set_age;

    p->set_name(p, name);
    p->set_age(p, age);

}

Person *person_create(const char *name, int age)
{
    Person *p = malloc(sizeof(Person));
    person_init(p, name, age);
    return p;
}


