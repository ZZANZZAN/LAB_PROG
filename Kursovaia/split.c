#include "HF/split.h"


int str_len(char *s){
    int r = 0;
    while(s[r] != '\0') r++;
    r--;
    return r;
}


int charToInt(char numeric){
    return numeric - 48;
}

void split(char *mes, head *q){
    node *temp = NULL;

    if((q -> N) == 0) temp = create_node_DLL(q);
    else{
    add_last_DLL(q);
    temp = q -> last;
    }

    char *s;
    int n = 0;

    if ((s = (group*)malloc(sizeof(group))) == NULL)
        puts("Error memory allocation!");
    else{
        int k = 0;

        for (size_t j = 0; j < strlen(mes); j++){
            if ((mes[j] != ';')){
                s[k] = mes[j];
                k++;
            }
            else{
                s[k] = '\0';

                if (n == 0) temp -> data -> face_value = atoi(s);
                else if (n == 1) strcpy(temp -> data -> currency, s);
                else if (n == 2) strcpy(temp -> data -> type_of_money, s);
                else if (n == 3) strcpy(temp -> data -> country, s);
                else if (n == 4) strcpy(temp -> data -> name, s);


                n++;
                k = 0;
            }
        }
        temp -> data -> DATE = atoi(s);
        free(s);
    }
}
