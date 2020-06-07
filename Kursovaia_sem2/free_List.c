#include "HF/free_List.h"

void free_head(head *q){
    free_node(q -> first);
    q -> first = NULL;
    q -> last = NULL;
    free(q);
}


void free_node(node *temp){
    if((temp -> next) != NULL) temp -> next = NULL;
    if((temp -> prev) != NULL) temp -> prev = NULL;

    free(temp -> data -> currency);
    free(temp -> data -> type_of_money);
    free(temp -> data -> country);
    free(temp -> data -> name);
    free(temp -> data);
    free(temp);
}


void free_list(head *q){
    node *temp = NULL;

    temp = q -> first -> next;

    free_head(q);

    while((temp -> next) != NULL){
        node *p = NULL;
        p = temp;
        temp = temp -> next;
        free_node(p);
    }

    free_node(temp);
}
