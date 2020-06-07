#include "HF/option_With_List.h"

void malloc_node(node *temp){
    temp -> data = malloc(sizeof(group));
    temp -> data -> currency = malloc(30 * sizeof(char));
    temp -> data -> type_of_money = malloc(30 * sizeof(char));
    temp -> data -> country = malloc(30 * sizeof(char));
    temp -> data -> name = malloc(30 * sizeof(char));
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


node *create_node_DLL(head *q){
    node *temp;

    temp = malloc(sizeof(node));
    malloc_node(temp);

    temp -> prev = NULL;
    temp -> next = NULL;
    temp -> id = q -> N + 1;

    q -> N += 1;
    q -> first = temp;
    q -> last = temp;

    return temp;
}


void add_last_DLL(head *q){
    node *temp = NULL;

    temp = (node*)malloc(sizeof(node));
    malloc_node(temp);

    temp -> next = NULL;
    temp -> id = ((q -> N) + 1);
    temp -> prev = q -> last;

    q -> last -> next = temp;
    q -> last = temp;
    q -> N += 1;
}


node *add_first_DLL(head *q){
    node *temp;

    temp = (node*)malloc(sizeof(node));
    malloc_node(temp);

    temp -> prev = NULL;
    temp -> next = (q -> first);
    temp -> id = 1;

    q -> first -> prev = temp;
    q -> N += 1;
    q -> first = temp;

    while(temp -> next != NULL){
        temp = temp -> next;
        temp -> id += 1;
    }
    //return temp;
}


void delete_first_DLL(head *q){
    node *temp = NULL;

    temp = q -> first;

    q -> first = (temp -> next);
    q -> first -> prev = NULL;
    q -> N -= 1;

    if((q -> N) == 0) q -> last = NULL;

    free_node(temp);
}


void delete_node_DLL(node *temp, head *q){
    q -> N -= 1;
    temp = temp -> next;

    if((temp -> next) != NULL){
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
    }
    else {
        q -> last = temp -> prev;
        q -> last -> next = NULL;
    }

    free_node(temp);
}

node edit_DLL(node *lst){
    node *temp, *p;
    temp = (node*)malloc(sizeof(node));
    malloc_node(temp);
    p = lst->next;
    lst->next = temp;
    temp->next = p;
    temp->prev = lst;
    temp -> id = ((lst -> id) + 1);
    if (p != NULL)
        p->prev = temp;


//return temp;
}

node *insert_after_DLL(node *lst){
    node *temp, *p;
    temp = (node*)malloc(sizeof(node));
    malloc_node(temp);
    p = lst->prev;
    p -> next = temp;
    temp -> prev = p;
    temp -> next = lst;
    lst -> prev = temp;

    temp -> id = (lst -> id);
    lst -> id += 1;
    while(lst -> next != NULL){
        lst = lst -> next;
        lst -> id += 1;
    }
    if (p != NULL)
        p->prev = temp;


return temp;
}

void sorting_id(head *q){
    node *temp = NULL;
    temp = q -> first;
    int i = 1;
    temp -> id = i;
    while(temp -> next != NULL){
        temp = temp -> next;
        temp -> id = ++i;
    }
}

node *swap(node *lst1, node *lst2, head *head){
  // ¬озвращает новый корень списка
  node *prev1, *prev2, *next1, *next2;
  prev1 = lst1->prev;  // узел предшествующий lst1
  prev2 = lst2->prev;  // узел предшествующий lst2
  next1 = lst1->next; // узел следующий за lst1
  next2 = lst2->next; // узел следующий за lst2
  if (lst2 == next1){  // обмениваютс€ соседние узлы
    lst2->next = lst1;
    lst2->prev = prev1;
    lst1->next = next2;
    lst1->prev = lst2;
    if(next2 != NULL)
      next2->prev = lst1;
    if (lst1 != head)
      prev1->next = lst2;
  }
  else if (lst1 == next2){ // обмениваютс€ соседние узлы
    lst1->next = lst2;
    lst1->prev = prev2;
    lst2->next = next1;
    lst2->prev = lst1;
    if(next1 != NULL)
      next1->prev = lst2;
    if (lst2 != head)
      prev2->next = lst1;
  }
  else{  // обмениваютс€ отсто€щие узлы
    if (lst1 != head)  // указатель prev можно установить только дл€ элемента,
      prev1->next = lst2; // не €вл€ющегос€ корневым
    lst2->next = next1;
    if (lst2 != head)
      prev2->next = lst1;
    lst1->next = next2;
    lst2->prev = prev1;
    if (next2 != NULL) // указатель next можно установить только дл€ элемента,
      next2->prev = lst1; // не €вл€ющегос€ последним
    lst1->prev = prev2;
    if (next1 != NULL)
      next1->prev = lst2;
  }
  if (lst1 == head)
    return(lst2);
  if (lst2 == head)
    return(lst1);
  return(head);
}

void sort_data(head *q){
    node *tmp;
    node *a;
    int t=0;
    int flag=1;
    while(flag==1)
    {
        tmp=q->first;
        a=tmp->next;
        flag=0;
        while(a)
        {
            if((tmp->data->DATE)>(a->data->DATE))
            {
                t=tmp->data;
                tmp->data=a->data;
                a->data=t;
                flag=1;
            }
            tmp=tmp->next;
            a=a->next;
        }
    }
}

void sort_value(head *q){
    node *tmp;
    node *a;
    int t=0;
    int flag=1;
    while(flag==1)
    {
        tmp=q->first;
        a=tmp->next;
        flag=0;
        while(a)
        {
            if((tmp->data->face_value)>(a->data->face_value))
            {
                t=tmp->data;
                tmp->data=a->data;
                a->data=t;
                flag=1;
            }
            tmp=tmp->next;
            a=a->next;
        }
    }
}

void sort_country(head *q){
    node *tmp;
    node *a;
    int t=0;
    int flag=1;
    while(flag==1)
    {
        tmp=q->first;
        a=tmp->next;
        flag=0;
        while(a)
        {
            if(strcmp(tmp->data->country, a->data->country)>0)
            {
                t=tmp->data;
                tmp->data=a->data;
                a->data=t;
                flag=1;
            }
            tmp=tmp->next;
            a=a->next;
        }
    }
}

void sort_type_of_money(head *q){
    node *tmp;
    node *a;
    int t=0;
    int flag=1;
    while(flag==1)
    {
        tmp=q->first;
        a=tmp->next;
        flag=0;
        while(a)
        {
            if(strcmp(tmp->data->type_of_money, a->data->type_of_money)>0)
            {
                t=tmp->data;
                tmp->data=a->data;
                a->data=t;
                flag=1;
            }
            tmp=tmp->next;
            a=a->next;
        }
    }
}

void sort_currency(head *q){
    node *tmp;
    node *a;
    int t=0;
    int flag=1;
    while(flag==1)
    {
        tmp=q->first;
        a=tmp->next;
        flag=0;
        while(a)
        {
            if(strcmp(tmp->data->currency, a->data->currency)>0)
            {
                t=tmp->data;
                tmp->data=a->data;
                a->data=t;
                flag=1;
            }
            tmp=tmp->next;
            a=a->next;
        }
    }
}

void sort_name(head *q){
    node *tmp;
    node *a;
    int t=0;
    int flag=1;
    while(flag==1)
    {
        tmp=q->first;
        a=tmp->next;
        flag=0;
        while(a)
        {
            if(strcmp(tmp->data->name, a->data->name)>0)
            {
                t=tmp->data;
                tmp->data=a->data;
                a->data=t;
                flag=1;
            }
            tmp=tmp->next;
            a=a->next;
        }
    }
}

void edit(head *q){
    int N;
    node *temp;
    temp = q->first;
    printf("Enter the structure number:");
    scanf("%d", &N);
    if(N>0&&N<q->N){
        while(temp -> id != N){
            temp = temp -> next;
        }
        printf("Enter face value: ");
        scanf("%d", &(temp -> data -> face_value));
        printf("Enter currency: ");
        scanf("%s", (temp -> data -> currency));
        printf("Enter type_of_money: ");
        scanf("%s", (temp -> data -> type_of_money));
        printf("Enter country: ");
        scanf("%s", (temp -> data -> country));
        printf("Enter name: ");
        scanf("%s", (temp -> data -> name));
        printf("Enter year: ");
        scanf("%d", &(temp -> data -> DATE));
        clear();
    }

}
