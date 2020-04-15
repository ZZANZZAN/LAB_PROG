#include "Filling_from_file_csv.h"
#include "Program_output.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 256

group *new_struct();

group *struct_fill(char **str);

node *create_node(group *data);

void add(node **head, group *data);

void add_last(node **tail, group *data);

void insert_after(node *head, int index, group *value);

void print_header();

void menu(node *head, int number_of_lines);

int main(){
    group **ch=NULL;
    int slen,i,number_of_lines,count;
    char **s2=NULL;
    char **s3=NULL;
    char s1[MAXLEN];
    char sep;
    FILE *df;
    node *head = NULL;
    node *temp, *p;

    sep=';';

    df=fopen("struct-data-03.csv","r");
    if(df!=NULL){
        number_of_lines=0;
        while((fgets(s1,MAXLEN,df))!=NULL) number_of_lines++;
        rewind(df);
        ////////////////
        fgets(s1,MAXLEN,df);
        slen=strlen(s1);
        s1[slen-1]='\0';
        slen=strlen(s1);

        s2=simple_split(s1,slen,sep);
        s3 = struct_fill(s2);
        temp=create_node(s3);
        head = temp;
        for(i=0,count=0;i<number_of_lines-1;i++,count++){
            fgets(s1,MAXLEN,df);
            slen=strlen(s1);
            s1[slen-1]='\0';
            slen=strlen(s1);

            s2=simple_split(s1,slen,sep);
            s3 = struct_fill(s2);
            p = create_node(s3);
            temp -> next = p;
            temp = p;
        }

        print_header();
        print_list(&head);
        ////////////////////////
        menu(head, number_of_lines);
    }
    else puts("File not found!");
}

node *create_node(group *data){
      node *temp;
      temp = (node *)malloc(sizeof(node));
      temp -> data = data;
      temp -> next = NULL;
      return temp;
}

void menu(node *head, int number_of_lines){
    int i = 9;
    while(i!=0){
        printf("| | Menu:         |\n");
        printf("+-+---------------+\n");
        printf("|1| - Add stuct   |\n");
        printf("|2| - Print struct|\n");
        printf("|0| - Exit        |\n");
        printf("Your choice:\n");
        scanf("%d", &i);
        getchar();
        if(i == 1){
            int a = 0;
            printf("\n");
            printf("Index struct:\n");
            scanf("%d", &a);
            if(a > number_of_lines || a < 1){
                a = 1;
            }
            //printf("bingo%d\n", a);
            group *str0=NULL;
            str0=(group*)malloc(sizeof(group));
            str0 = new_struct();
            if(a != 1){
                a--;
                insert_after(head, a, str0);printf("bingo\n");
            }
            else{
                add(&head, str0);
            }
            number_of_lines++;
            }
        if(i == 2){
            print_header();
            print_list(&head);
        }
    }
}

void add(node **head, group *data){
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = (group**)malloc(sizeof(group*));
    temp -> next = *head;
    temp -> data = data;
    *head = temp;
}

void add_last(node **tail, group *data){
    node *temp = (node *)malloc(sizeof(node));
    temp -> next = NULL;
    temp -> data = data;
    (*tail)->next = temp;
    *tail = temp;
}

void insert_after(node *head, int index, group *value){
    int i;
    node *p = head;
    node *temp;
    //p = (node*)malloc(sizeof(node));
    temp = (node*)malloc(sizeof(node));
    //printf("bingo%d\n", index);
    i = 0;
    while (i < index - 1){//printf("bingo\n");
        p = p->next;
        i++;
    }
    temp = create_node(value);
    temp->next = p->next;
    p->next = temp;
}

group *struct_fill(char **str){
    group *str0=NULL;

    str0=(group*)malloc(sizeof(group));
    if(str0!=NULL){
        strcpy(str0 -> NAME, str[0]);
        //temp -> data -> NAME = s2[0];
        strcpy(str0 -> NIK, str[1]);
        //temp -> data -> NIK = s2[1];
        str0-> DATE[0] = atoi(str[2]);
        str0 -> DATE[1] = atoi(str[3]);
        str0 -> DATE[2] = atoi(str[4]);
        str0 -> chislopole1 = atoi(str[5]);
        str0 -> chislopole2 = atoi(str[6]);
        str0 -> chislopole3 = atof(str[7]);
        str0 -> chislopole4 = atof(str[8]);
    }
    return str0;
}

group *new_struct(){

    group *str0=NULL;

    str0=(group*)malloc(sizeof(group));
    if(str0!=NULL){
        getchar();
        puts("Enter name:");
        fgets((*str0).NAME,MAXLEN,stdin);
        puts("Enter Zodiac sign:");
        fgets((*str0).NIK,MAXLEN,stdin);
        puts("Enter year:");
        scanf("%d",&(*str0).DATE[0]);
        puts("Enter mounth:");
        scanf("%d",&(*str0).DATE[1]);
        puts("Enter day:");
        scanf("%d",&(*str0).DATE[2]);
        puts("Enter like chislo:");
        scanf("%d",&(*str0).chislopole1);
        puts("Enter good chislo:");
        scanf("%d",&(*str0).chislopole2);
        puts("Enter percentage of luck:");
        scanf("%f",&(*str0).chislopole3);
        puts("Enter confidence percentage:");
        scanf("%f",&(*str0).chislopole4);
        str0->NAME[strlen(str0->NAME)-1]='\0';
        str0->NIK[strlen(str0->NIK)-1]='\0';
    }
    return str0;
}
