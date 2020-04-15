#ifndef PROGRAM_OUTPUT_H_INCLUDED
#define PROGRAM_OUTPUT_H_INCLUDED
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

void print_list(node **head);
void print_header();

#endif // PROGRAM_OUTPUT_H_INCLUDED
