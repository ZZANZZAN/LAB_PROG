#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdlib.h>

#ifdef _WIN32
    #define clear() system("cls");
#else
    #define clear() printf("\33[1;1H\33[2J");
#endif


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
