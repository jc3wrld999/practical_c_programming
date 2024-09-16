#ifndef PERSON_H
#define PERSON_H

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

char *person_get_name(Person *p);
void person_set_name(Person *p, const char *name);
int person_get_age(Person *p);
void person_set_age(Person *p, int age);
void person_init(Person *p, const char *name, int age);
Person *person_create(const char *name, int age);

#endif // PERSON_H
