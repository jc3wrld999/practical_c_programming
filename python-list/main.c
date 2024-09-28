#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT     0
#define FLOAT   1
#define STRING  2
#define AA_OBJECT   3

typedef struct _AA {
    int count;
    char *(*__repr__)(struct _AA);
} AA;

typedef union _var {
    int int_num;
    float float_num;
    char *string;
    AA AA_object;
} Var;

typedef struct _node {
    int type;
    Var var;
    struct _node *next;
} Node;

// node 를 생성 
Node *node_create(Var var, int type) {
    Node *node = malloc(sizeof(Node));
    node->type = type;
    node->var = var;
    node->next = NULL;
    return node; 
}

void node_print(Node *n)
{
    if(n->type == INT)
        printf("%d\n", n->var.int_num);
    else if(n->type == FLOAT)
        printf("%f\n", n->var.float_num);
    else if(n->type == STRING)
        printf("%s\n", n->var.string);
    else if(n->type == AA_OBJECT)
        if(n->var.AA_object.__repr__)
        {
            char *s = n->var.AA_object.__repr__(n->var.AA_object);
            printf("%s\n", s);
            free(s);
        }
        else
            printf("<AA_OBJECT 0x%X>\n", &n->var.AA_object);
}

typedef struct _list {
    Node *head;
    int length;
} List;


// List 생성
List *list_create() {
    List *list = malloc(sizeof(List));
    memset(list, 0, sizeof(List));
    return list;
}

Node *list_append(List *list, Var var, int type)
{
    Node *n = node_create(var, type);
    if(list->head == NULL) list->head = n;
    else
    {
        Node *t = list->head;
        for(; t->next; t = t->next);
        t->next = n;
    }
    return n;
}

Node *list_get(List *list, int index)
{
    Node *n = list->head;
    for(int i = 0; i < index; i++, n = n->next);
    return n;
}

void list_print(List *list)
{
    printf("[");
    if(list->head)
    {
        for(Node *t = list->head; t; t = t->next)
        {
            if(t->next)
            {
                if(t->type == INT)
                    printf("%d, ", t->var.int_num);
                else if(t->type == FLOAT)
                    printf("%f, ", t->var.float_num);
                else if(t->type == STRING)
                    printf("%s, ", t->var.string);
                else if(t->type == AA_OBJECT)
                    if(t->var.AA_object.__repr__)
                    {
                        char *s = t->var.AA_object.__repr__(t->var.AA_object);
                        printf("%s, ", s);
                        free(s);
                    }
                    else
                        printf("<AA_OBJECT 0x%X>, ", &t->var.AA_object);
            }
            else
            {
                if(t->type == INT)
                    printf("%d]", t->var.int_num);
                else if(t->type == FLOAT)
                    printf("%f]", t->var.float_num);
                else if(t->type == STRING)
                    printf("%s]", t->var.string);
                else if(t->type == AA_OBJECT)
                    if(t->var.AA_object.__repr__)
                    {
                        char *s = t->var.AA_object.__repr__(t->var.AA_object);
                        printf("%s]", s);
                        free(s);
                    }
                    else
                        printf("<AA_OBJECT 0x%X>]", &t->var.AA_object);

            }
        }
    }
    else
        printf("]");

    printf("\n");

}


#define list_append_int(list, num) list_append(list, (Var){.int_num = num}, INT)
#define list_append_float(list, num) list_append(list, (Var){.float_num = num}, FLOAT)
#define list_append_string(list, str) list_append(list, (Var){.string = str}, STRING)
#define list_append_AA(list, aa) list_append(list, (Var){.AA_object = aa}, AA_OBJECT)

char *aa_repr_func(AA a)
{
    char buffer[1024];
    char *s;
    sprintf(buffer, "count = %d", a.count);
    s = malloc(strlen(buffer) + 1);
    strcpy(s, buffer);
    return s;
}

int main(void)
{
    printf("sizeof(Var) = %d\n", sizeof(Var));

    List *list = list_create();

    list_append_int(list, 10);
    list_append_float(list, 0.5);
    list_append_string(list, "천승주");
    list_append_float(list, 0.05);

    AA a = {
        .count = 400,
        .__repr__ = aa_repr_func
    };
    
    AA b = {
        .count = 1000,
        .__repr__ = NULL
    };

    list_append_AA(list, a);
    list_append_AA(list, b);

    list_print(list);

    Node *n = list_get(list, 0);
    node_print(n);
    n = list_get(list, 4);
    node_print(n);
    n = list_get(list, 5);
    node_print(n);

    return 0;
}

// Stack, Queue
