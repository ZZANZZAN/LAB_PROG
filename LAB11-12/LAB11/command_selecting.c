#include "HF/command_selecting.h"

void command_selecting(head *q){
    char s[50];
    int f;
    printf("\n| | Menu:         |\n");
    printf("+-+---------------+\n");
    printf("|1| - Add stuct   |\n");
    printf("|2| - Print struct|\n");
    printf("|0| - Exit        |\n");
    printf("Your choice:\n");
    fgets(s, 200, stdin);
    f = charToInt(s[0]);
    if(str_len(s) == 1){
            if(f == 1)
                enterFromKeyboard(q);
            else if(f == 2){
                int f1;
                printf("\nSelect the printing method:\n1) At first\n2) From the end\n\nCommand:");
                scanf("%d", &f1);
                if(f1 == 1) output_list(q);
                else if(f1 == 2) output_list_reverse(q);
            }
    }

    while(f != 4){
        if(str_len(s) == 0){
            if(f == 1)
                enterFromKeyboard(q);
            else if(f == 2){
                int f1;
                printf("\nSelect the printing method:\n1) At first\n2) From the end\n\nCommand:");
                scanf("%d", &f1);
                if(f1 == 1) output_list(q);
                else if(f1 == 2) output_list_reverse(q);
            }
        }

            printf("\nSelect a command:\n1) Add\n2) Delete by search\n3) database\n4) Exit\n\nCommand:");
            scanf("%s", &s);
            f = charToInt(s[0]);
    }
}
