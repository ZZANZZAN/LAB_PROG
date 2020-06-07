#include "HF/search.h"

void delete_one(head *q){
    printf("Enter number strings (int): ");
    int s;
    scanf("%d", &s);

    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    size_t num = 0;

    if((q -> N) > 0){
        while((temp -> next) != NULL){
            if(s == temp -> id){
                if((q -> first) == temp){
                    temp = temp -> next;
                    delete_first_DLL(q);
                }
                else{
                    temp = temp -> next;
                    delete_node_DLL(p, q);
                }
                num++;
            }
            else{
                p = temp;
                temp = p -> next;
            }
        }

        if(s == temp -> id){
            if((q -> first) == temp)
                delete_first_DLL(q);
            else
                delete_node_DLL(p, q);
        }
    }
    if(num == 0) printf("\nThere is no match!!!\n");
    sorting_id(q);
}

void delete_currency(head *q){
    printf("Enter a name or part of a name: ");
    char s[100];

    scanf("%s", &s);
    s[strlen(s)] = '\0';

    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    size_t num = 0;

    if((q -> N) > 0){
        while((temp -> next) != NULL){
            if(strstr((temp -> data -> currency), s) != NULL){
                if((q -> first) == temp){
                    temp = temp -> next;
                    delete_first_DLL(q);
                }
                else{
                    temp = temp -> next;
                    delete_node_DLL(p, q);
                }
                num++;
            }
            else{
                p = temp;
                temp = p -> next;
            }
        }

        if(strstr((temp -> data -> currency), s) != NULL){
            if((q -> first) == temp)
                delete_first_DLL(q);
            else
                delete_node_DLL(p, q);
        }
    }

    if(num == 0) printf("\nThere is no match!!!\n");
}


void delete_type_of_money(head *q){
    printf("Enter a name or part of a name: ");
    char s[100];

    scanf("%s", &s);
    s[strlen(s)] = '\0';

    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    size_t num = 0;

    if((q -> N) > 0){
        while((temp -> next) != NULL){
            if(strstr((temp -> data -> type_of_money), s) != NULL){
                if((q -> first) == temp){
                    delete_first_DLL(q);
                    temp = q -> first;
                }
                else{
                    temp = temp -> next;
                    delete_node_DLL(p, q);
                }
                num++;
            }
            else{
                p = temp;
                temp = p -> next;
            }
        }

        if(strstr((temp -> data -> type_of_money), s) != NULL){
            if((q -> first) == temp)
                delete_first_DLL(q);
            else
                delete_node_DLL(p, q);
        }
    }
    if(num == 0) printf("\nThere is no match!!!\n");
}



void delete_country(head *q){
    printf("Enter the number of wins: ");
    int k;
    scanf("%d", &k);

    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    size_t num = 0;

    if((q -> N) > 0){
        while((temp -> next) != NULL){
            if((temp -> data -> country) == k){
                if((q -> first) == temp){
                    delete_first_DLL(q);
                    temp = q -> first;
                }
                else{
                    temp = temp -> next;
                    delete_node_DLL(p, q);
                }
                num++;
            }
            else{
                p = temp;
                temp = p -> next;
            }
        }

        if((temp -> data -> country) == k){
            if((q -> first) == temp)
                delete_first_DLL(q);
            else
                delete_node_DLL(p, q);
        }
    }

    if(num == 0) printf("\nThere is no match!!!\n");
}


void delete_name(head *q){
    printf("Enter the number of draws: ");
    int k;
    scanf("%d", &k);

    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    size_t num = 0;

    if((q -> N) > 0){
        while((temp -> next) != NULL){
            if((temp -> data -> name) == k){
                if((q -> first) == temp){
                    delete_first_DLL(q);
                    temp = q -> first;
                }
                else{
                    temp = temp -> next;
                    delete_node_DLL(p, q);
                }
                num++;
            }
            else{
                p = temp;
                temp = p -> next;
            }
        }

        if((temp -> data -> name) == k){
            if((q -> first) == temp)
                delete_first_DLL(q);
            else
                delete_node_DLL(p, q);
        }
    }

    if(num == 0) printf("\nThere is no match!!!\n");
}


void delete_menu(head *q)
{
    int k;
    printf("| | Select the delete method:|\n");
    printf("+-+--------------------------+\n");
    printf("|1| - Delete one             |\n");
    printf("|2| - Delete currency        |\n");
    printf("|3| - Delete type of money   |\n");
    printf("|4| - Delete country         |\n");
    printf("|5| - Delete name            |\n");
    printf("Command:\n");
    scanf("%d", &k);
    if(k == 1) delete_one(q);
    else if(k == 2) delete_currency(q);
    else if(k == 3) delete_type_of_money(q);
    else if(k == 4) delete_country(q);
    else if(k == 5) delete_name(q);
}
