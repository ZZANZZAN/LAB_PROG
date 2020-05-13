#include "HF/option_With_List.h"

void malloc_node(node *temp){
    temp -> data = malloc(sizeof(group));
    temp -> data -> NAME = malloc(30 * sizeof(char));
    temp -> data -> NIK = malloc(30 * sizeof(char));
}


head *create_head_DLL(){
    head *p = NULL;

    p = malloc(sizeof(head));
    if(p){
        p -> N = 0;
        p -> first = NULL;
        p -> last = NULL;
    }

    return p;
}


node *create_node_RLL(head *q){
    node *temp;

    temp = malloc(sizeof(node));
    malloc_node(temp);


    temp -> next = NULL;
    temp -> id = q -> N + 1;

    q -> N += 1;
    q -> first = temp;
    q -> last = temp;

    return temp;
}


void add_last_RLL(head *q){
    node *temp = NULL;

    temp = (node*)malloc(sizeof(node));
    malloc_node(temp);

    temp -> next = q -> first;
    temp -> id = ((q -> N) + 1);


    q -> last -> next = temp;
    q -> last = temp;
    q -> N += 1;
}


node *add_first_RLL(head *q){
    node *temp;

    temp = (node*)malloc(sizeof(node));
    malloc_node(temp);


    temp -> next = (q -> first);
    temp -> id = 1;


    q -> N += 1;
    q -> first = temp;

    while(temp -> next != q -> last){
        temp = temp -> next;
        temp -> id += 1;
    }
    //return temp;
}


void delete_first_RLL(head *q){
    node *temp = NULL;

    temp = q -> first;

    q -> first = (temp -> next);

    q -> N -= 1;

    if((q -> N) == 0) q -> last = NULL;

    free_node(temp);
}


void delete_node_RLL(node *temp, head *q){
    q -> N -= 1;
    temp = temp -> next;

    if((temp -> next) != NULL){
        //temp -> next -> prev = temp -> prev;
        //temp -> prev -> next = temp -> next;
    }
    else {
        //q -> last = temp -> prev;
        //q -> last -> next = NULL;
    }

    free_node(temp);
}

node edit_RLL(node *lst){
    node *temp, *p;
    temp = (node*)malloc(sizeof(node));
    malloc_node(temp);
    p = lst->next;
    lst->next = temp;
    temp->next = p;

    temp -> id = ((lst -> id) + 1);
    //if (p != NULL)
        //p->prev = temp;


//return temp;
}

node *insert_after_RLL(node *lst, int N){
    node *temp, *p;
    temp = (node*)malloc(sizeof(node));
    malloc_node(temp);

    p -> next = temp;

    temp -> next = lst;


    temp -> id = (lst -> id);
    lst -> id += 1;
    while(lst -> next -> id != N){
        lst = lst -> next;
        lst -> id += 1;
    }


return temp;
}

node *deletelem(node *lst)
{
  struct node *temp;
  temp = lst;
  while (temp->next != lst) // просматриваем список начиная с корня
  { // пока не найдем узел, предшествующий lst
    temp = temp->next;
  }
  temp->next = lst->next; // переставляем указатель
  free(lst); // освобождаем память удаляемого узла
  return(temp);
}
