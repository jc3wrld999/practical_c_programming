#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _callback
{
    int data;

    void (*print)(struct _callback *);
} Callback;


Callback *callback_create(int data)
{
    Callback *c = malloc(sizeof(Callback));
    memset(c, 0, sizeof(Callback));
    c->data = data;
    return c;
}

void callback_register_print(Callback *c, void (*func)(Callback *))
{
    c->print = func;
}

void callback_unregister_print(Callback *c)
{
    c->print = NULL;
}

void callback_print(Callback *c)
{
    if(c->print)
        c->print(c);
    else {
        printf("%d\n", c->data);
    }
}

void my_callback_print(Callback *c)
{
    printf("My data = %d\n", c->data);
}


int main(void)
{
    Callback *c = callback_create(10);

    callback_register_print(c, my_callback_print);
    callback_print(c);

    callback_unregister_print(c);
    callback_print(c);

    return 0;
}