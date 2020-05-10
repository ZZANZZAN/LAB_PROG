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

                if (n == 0) strcpy(temp -> data -> NAME, s);
                else if (n == 1) strcpy(temp -> data -> NIK, s);
                else if (n == 2) temp -> data -> DATE[0] = atoi(s);
                else if (n == 3) temp -> data -> DATE[1] = atoi(s);
                else if (n == 4) temp -> data -> DATE[2] = atoi(s);
                else if (n == 5) temp -> data -> chislopole1 = atoi(s);
                else if (n == 6) temp -> data -> chislopole2 = atoi(s);
                else if (n == 7) temp -> data -> chislopole3 = atof(s);

                n++;
                k = 0;
            }
        }
        temp -> data -> chislopole4 = atof(s);
        free(s);
    }
}
