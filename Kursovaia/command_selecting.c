#include "HF/command_selecting.h"

void command_selecting(head *q){
    char s[max];
    int f;
    printf("\n| | Menu:          |\n");
    printf("+-+----------------+\n");
    printf("|1| - Add stuct    |\n");
    printf("|2| - Print struct |\n");
    printf("|3| - Search struct|\n");
    printf("|4| - Delete struct|\n");
    printf("|5| - Save struct  |\n");
    printf("|0| - Exit         |\n");
    printf("Your choice:\n");
    fgets(s, max, stdin);
    f = charToInt(s[0]);
    if(str_len(s) == 1){
            if(f == 1)
                enterFromKeyboard(q);
            else if(f == 2){
                int f1;
                //printf("\nSelect the printing method:\n1) At first\n2) From the end(do not work in this version)\n\nCommand:");
                printf("| | Select the printing method:                |\n");
                printf("+-+--------------------------------------------+\n");
                printf("|1| - At first                                 |\n");
                printf("|2| - From the end(do not work in this version)|\n");
                //printf("|0| - Exit        |\n");
                printf("Command:\n");
                scanf("%d", &f1);
                if(f1 == 1) output_list(q);
                //else if(f1 == 2) output_list_reverse(q);
            }
            else if(f == 3){
                search(q);
            }
            else if(f == 4){
                delete_menu(q);
            }
            else if(f == 5){
                save_list(q);
            }
    }

    while(f != 0){
        if(str_len(s) == 0){
            if(f == 1)
                enterFromKeyboard(q);
            else if(f == 2){
                int f1;
                printf("| | Select the printing method:                |\n");
                printf("+-+--------------------------------------------+\n");
                printf("|1| - At first                                 |\n");
                printf("|2| - From the end(do not work in this version)|\n");
                //printf("|0| - Exit        |\n");
                printf("Command:\n");
                scanf("%d", &f1);
                if(f1 == 1) output_list(q);
                //else if(f1 == 2) output_list_reverse(q);
            }
            else if(f == 3){
                search(q);
            }
            else if(f == 4){
                delete_menu(q);
            }
            else if(f == 5){
                save_list(q);
            }
        }

        printf("\n| | Menu:          |\n");
        printf("+-+----------------+\n");
        printf("|1| - Add stuct    |\n");
        printf("|2| - Print struct |\n");
        printf("|3| - Search struct|\n");
        printf("|4| - Delete struct|\n");
        printf("|5| - Save struct  |\n");
        printf("|0| - Exit         |\n");
        printf("Your choice:\n");
        scanf("%s", &s);
        f = charToInt(s[0]);
    }
}
