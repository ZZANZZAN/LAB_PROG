#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 256

typedef struct ZNAK {
    char NAME[MAXLEN];
    char NIK[MAXLEN];
    int DATE[3];
    int chislopole1;
    int chislopole2;
    float chislopole3;
    float chislopole4;
} group;

struct node{

    group *data;
    struct node *next;
};
typedef struct node node;

void print_header() {
    printf("Initial array:\n");
    printf("| %20s|%10s|%10s|%5s|%5s|%10s|%10s|\n", "NAME", "Nik", "Date", "int1", "int2", "float1", "float2");
    printf("+---------------------+----------+----+--+--+-----+-----+----------+----------+\n");
}

void print_list(node **head){
      node *p;
      p = *head;
      while(p != NULL){
          printf("|%20s |%10s|%4d|%2d|%2d|%5d|%5d|%10f|%10f|\n",
            p -> data ->NAME,
            p -> data ->NIK,
            p -> data ->DATE[0],
            p -> data ->DATE[1],
            p -> data ->DATE[2],
            p -> data ->chislopole1,
            p -> data ->chislopole2,
            p -> data ->chislopole3,
            p -> data ->chislopole4);
          p = p->next;
      }
      printf("\n");
}
