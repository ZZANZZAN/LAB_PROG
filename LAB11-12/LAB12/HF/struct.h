#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdlib.h>

typedef struct ZNAK {
    char *NAME;
    char *NIK;
    int DATE[3];
    int chislopole1;
    int chislopole2;
    float chislopole3;
    float chislopole4;
} group;


typedef struct node{
    int id;
    group *data;

    struct node *next;
}node;


typedef struct head{
    int N;
    struct node *first;
    struct node *last;
}head;

#endif // STRUCT_H_INCLUDED
