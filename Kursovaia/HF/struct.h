#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdlib.h>

typedef struct ZNAK {
    int face_value;
    char *currency;
    char *type_of_money;
    char *country;
    int DATE;
    char *name;
} group;


typedef struct node{
    int id;
    group *data;
    struct node *prev;
    struct node *next;
}node;


typedef struct head{
    int N;
    struct node *first;
    struct node *last;
}head;

#endif // STRUCT_H_INCLUDED
