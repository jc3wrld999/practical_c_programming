#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person
{
    char name[100];
    int age;

    char *(*get_name)(struct _person *);
    void (*set_name)(struct _person *, const char *name);
    int (*get_age)(struct _person *);
    void (*set_age)(struct _person *, int);
    void (*init)(struct _person *, const char *, int);
} Person;

char *get_person_name(Person *p)
{
    return p->name;
}

void set_person_name(Person *p, const char *name)
{
    strncpy(p->name, name, sizeof(p->name)-1);
    p->name[sizeof(p->name)-1] = '\0';
}

int get_person_age(Person *p)
{
    return p->age;
}

void set_person_age(Person *p, int age)
{
    p->age = age;
}

void init_person(Person *p, const char *name, int age)
{
    p->init = init_person;
    
    p->get_name = get_person_name;
    p->get_age = get_person_age;
    p->set_name = set_person_name;
    p->set_age = set_person_age;

    p->set_name(p, name);
    p->set_age(p, age);

}

Person *create_person(const char *name, int age)
{
    Person *p = malloc(sizeof(Person));
    init_person(p, name, age);
    return p;
}


int main(void)
{
    Person *p = create_person("sungju", 27);
    printf("%s, %d\n", p->get_name(p), p->get_age(p));
}