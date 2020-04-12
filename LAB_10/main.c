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

char **simple_split(char *str, int length, char sep);

void ClearStringArray(char **str, int n);

group *new_struct();

group *struct_fill(char **str);

node *create_node(group *data);

void print_list(node **head);

void add(node **head, group *data);

void add_last(node **tail, group *data);

void insert_after(node *head, int index, group *value);

int main(){
    group **ch=NULL;
    int slen,i,n,count,y;
    char **s2=NULL;
    char s1[MAXLEN];
    char sep,choose;
    FILE *df;
    node *head = NULL;
    node *tail = NULL;
    node *temp, *p;

    sep=';';

    df=fopen("struct-data-03.csv","r");
    if(df!=NULL){
        n=0;
        while((fgets(s1,MAXLEN,df))!=NULL) n++;
        rewind(df);
        ch=(group**)malloc(n*sizeof(group*));
        puts("Initial array:");
        if(ch!=NULL){
            for(i=0,count=0;i<n;i++,count++){
                fgets(s1,MAXLEN,df);
                slen=strlen(s1);
                s1[slen-1]='\0';
                slen=strlen(s1);

                s2=simple_split(s1,slen,sep);
                if(s2!=NULL){
                    ch[i]=struct_fill(s2);
                }
                else puts("Error at data reading!");
            }
            temp=create_node(ch[0]);
            head = temp;
            tail = temp;
            for(i = 1; i < 12; i++){
              p = create_node(ch[i]);
              tail = p;
              temp -> next = p;
              temp = p;
            }
            print_list(&head);
            }
        i=9;
        while(i!=0){
            printf("Menu:\n");
            printf("1 - Add stuct\n");
            printf("2 - Print struct\n");
            printf("0 - Exit\n");
            scanf("%d", &i);
            getchar();
            if(i == 1){
                int a = 0;
                printf("\n");
                printf("Index struct:\n");
                scanf("%d", &a);

                printf("bingo%d\n", a);
                group *str0=NULL;
                str0=(group*)malloc(sizeof(group));
                str0 = new_struct();
                insert_after(head, a, str0);
            }
            if(i == 2){
                print_list(&head);
            }
        }
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

void print_list(node **head){
      node *p;
      p = *head;
      while(p != NULL){
          printf("|%20s |%10s|%2d|%2d|%2d|%5d|%5d|%10f|%10f|\n",
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
    i = 0;
    printf("bingo%d\n", index);
    while (i < index - 1){printf("bingo\n");
        p = p->next;
        i++;
    }
    temp = create_node(value);
    temp->next = p->next;
    p->next = temp;
}

char **simple_split(char *str, int length, char sep){
    char **str_array=NULL;
    int i,j,k,m;
    int key,count;
    for(j=0,m=0;j<length;j++){
        if(str[j]==sep) m++;
    }

    key=0;
    str_array=(char**)malloc((m+1)*sizeof(char*));
    if(str_array!=NULL){
        for(i=0,count=0;i<=m;i++,count++){
            str_array[i]=(char*)malloc(length*sizeof(char));
            if(str_array[i]!=NULL) key=1;
            else{
                key=0;
                i=m;
            }
        }
        if(key){
            k=0;
            m=0;
            for(j=0;j<length;j++){
                if(str[j]!=sep) str_array[m][j-k]=str[j];
                else{
                    str_array[m][j-k]='\0';
                    k=j+1;
                    m++;
                }
            }
        }
        else{
            ClearStringArray(str_array,count);
        }
     }
     return str_array;
}

void ClearStringArray(char **str, int n){
    int i;

    for(i=0;i<n;i++){
        free(str[i]);
        str[i]=NULL;
    }
    free(str);
    str=NULL;

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
        puts("Enter nik:");
        fgets((*str0).NIK,MAXLEN,stdin);
        puts("Enter day:");
        scanf("%d",&(*str0).DATE[0]);
        puts("Enter mounth:");
        scanf("%d",&(*str0).DATE[1]);
        puts("Enter year:");
        scanf("%d",&(*str0).DATE[2]);
        puts("Enter like chislo:");
        scanf("%d",&(*str0).chislopole1);
        puts("Enter like chislo:");
        scanf("%d",&(*str0).chislopole2);
        puts("Enter like chislo:");
        scanf("%f",&(*str0).chislopole3);
        puts("Enter like chislo:");
        scanf("%f",&(*str0).chislopole4);
        str0->NAME[strlen(str0->NAME)-1]='\0';
        str0->NIK[strlen(str0->NIK)-1]='\0';
    }
    return str0;
}

