#include "HF/search.h"

void search_name(head *q){
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
            if(strstr((temp -> data -> NAME), s) != NULL){
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

        if(strstr((temp -> data -> NAME), s) != NULL){
            if((q -> first) == temp)
                delete_first_DLL(q);
            else
                delete_node_DLL(p, q);
        }
    }

    if(num == 0) printf("\nThere is no match!!!\n");
}


void search_country(head *q){
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
            if(strstr((temp -> data -> NIK), s) != NULL){
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

        if(strstr((temp -> data -> NIK), s) != NULL){
            if((q -> first) == temp)
                delete_first_DLL(q);
            else
                delete_node_DLL(p, q);
        }
    }
    if(num == 0) printf("\nThere is no match!!!\n");
}



void search_wins(head *q){
    printf("Enter the number of wins: ");
    int k;
    scanf("%d", &k);

    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    size_t num = 0;

    if((q -> N) > 0){
        while((temp -> next) != NULL){
            if((temp -> data -> DATE[0]) == k){
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

        if((temp -> data -> DATE[0]) == k){
            if((q -> first) == temp)
                delete_first_DLL(q);
            else
                delete_node_DLL(p, q);
        }
    }

    if(num == 0) printf("\nThere is no match!!!\n");
}


void search_draws(head *q){
    printf("Enter the number of draws: ");
    int k;
    scanf("%d", &k);

    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    size_t num = 0;

    if((q -> N) > 0){
        while((temp -> next) != NULL){
            if((temp -> data -> DATE[1]) == k){
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

        if((temp -> data -> DATE[1]) == k){
            if((q -> first) == temp)
                delete_first_DLL(q);
            else
                delete_node_DLL(p, q);
        }
    }

    if(num == 0) printf("\nThere is no match!!!\n");
}


void search_matches(head *q)
{
    printf("\nSelect which field you want to find matches for:");
    printf("\n1) Name club\n2) Country of the club\n3) probability of the club's passage to the Champions League\n4) wins last 10 matches\n5) count draws last 10 matches\n\ncommand: ");

    int k;
    scanf("%d", &k);

    if(k == 1) search_name(q);
    else if(k == 2) search_country(q);
    else if(k == 4) search_wins(q);
    else if(k == 4) search_draws(q);
}
