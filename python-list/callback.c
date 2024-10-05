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


// int main(void)
// {
//     Callback *c = callback_create(10);
//
//     callback_register_print(c, my_callback_print);
//     callback_print(c);
//
//     callback_unregister_print(c);
//     callback_print(c);
//
//     return 0;
// }

#define COMMAND_ARGS    int data, int data2, int data3
#define CALLBACK_PRINT_FORMAT   "%s() called! data = %d, data2 = %d, data3 = %d\n"
#define CALLBACK_PRINT_ARGS    data, data2, data3

#ifdef True
#undef True
#undef False
#endif

#ifndef True
    #define True 1
    #define False !True
#endif

typedef struct _command {
    char *command;
    void (*func)(COMMAND_ARGS);
} Command;

void connect_function(COMMAND_ARGS) {
    printf(CALLBACK_PRINT_FORMAT, __func__, CALLBACK_PRINT_ARGS);
}

void open_function(COMMAND_ARGS) {
    printf(CALLBACK_PRINT_FORMAT, __func__, CALLBACK_PRINT_ARGS);
}

void load_function(COMMAND_ARGS) {
    printf(CALLBACK_PRINT_FORMAT, __func__, CALLBACK_PRINT_ARGS);
}

void save_function(COMMAND_ARGS) {
    printf(CALLBACK_PRINT_FORMAT, __func__, CALLBACK_PRINT_ARGS);
}

void close_function(COMMAND_ARGS) {
    printf(CALLBACK_PRINT_FORMAT, __func__, CALLBACK_PRINT_ARGS);
}

int main(void) {
    // char *(*)(int, int, char *) (*callback)(int, int, char *);
    char *(*(*callback)(int))(int, int, char *);

    Command commands[] = {
        {"connect", connect_function},
        {"open", open_function},
        {"load", load_function},
        {"save", save_function},
        {"close", close_function},
    };
    int command_length = sizeof(commands) / sizeof(Command);

    char command[100];
    int data, data2, data3;

    char message[1024];
    fgets(message, sizeof(message), stdin);
    printf("'%s'\n", message);

    sscanf(message, "%s %d %d %d", command, &data, &data2, &data3);


    for(int i = 0; i < command_length; i++) {
        if(strcmp(commands[i].command, command) == 0) {
            commands[i].func(CALLBACK_PRINT_ARGS);
            break;
        }
    }



    return 0;
}
