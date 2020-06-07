#include "HF/command_selecting.h"

void command_selecting(head *q){
    char s[max];
    int f;
    printf("\n| | Menu:          |\n");
    printf("+-+----------------+\n");
    printf("|1| - Print struct |\n");
    printf("|2| - Add stuct    |\n");
    printf("|3| - Edit stuct   |\n");
    printf("|4| - Search struct|\n");
    printf("|5| - Sort struct  |\n");
    printf("|6| - Swap struct  |\n");
    printf("|7| - Delete struct|\n");
    printf("|8| - Save struct  |\n");
    printf("|0| - Exit         |\n");
    printf("Your choice:\n");
    fgets(s, max, stdin);
    f = charToInt(s[0]);
    if(str_len(s) == 1){
            clear();
            if(f == 1){
                int f1;
                //printf("\nSelect the printing method:\n1) At first\n2) From the end(do not work in this version)\n\nCommand:");
                printf("| | Select the printing method:                |\n");
                printf("+-+--------------------------------------------+\n");
                printf("|1| - At first                                 |\n");
                printf("|2| - From the end(do not work in this version)|\n");
                //printf("|0| - Exit        |\n");
                printf("Command:\n");
                scanf("%d", &f1);
                clear();
                if(f1 == 1) output_list(q);
                //else if(f1 == 2) output_list_reverse(q);
            }
            else if(f == 2){
                enterFromKeyboard(q);
            }
            else if(f == 3){
                edit(q);
            }
            else if(f == 4){
                search_list(q);
            }
            else if(f == 5){
                int f2;
                printf("| | Select the sort method: |\n");
                printf("+-+-------------------------+\n");
                printf("|1| - Value                 |\n");
                printf("|2| - Currency              |\n");
                printf("|3| - Type                  |\n");
                printf("|4| - Country               |\n");
                printf("|5| - Name                  |\n");
                printf("|6| - DATE                  |\n");
                printf("Command:\n");
                scanf("%d", &f2);
                clear();
                if(f2 == 1) sort_value(q);
                else if(f2 == 2) sort_currency(q);
                else if(f2 == 3) sort_type_of_money(q);
                else if(f2 == 4) sort_country(q);
                else if(f2 == 5) sort_name(q);
                else if(f2 == 6) sort_data(q);
            }
            else if(f == 6){
                int N_struct_for_swap_1, N_struct_for_swap_2, t;
                node *N_temp_1, *N_temp_2;
                printf("Enter the first structure number:");
                scanf("%d", &N_struct_for_swap_1);
                printf("Enter the second structure number:");
                scanf("%d", &N_struct_for_swap_2);
                if(N_struct_for_swap_1>1 && N_struct_for_swap_2>1 &&N_struct_for_swap_1<=q->N&&N_struct_for_swap_2<=q->N){
                    N_temp_1 = q -> first;
                    N_temp_2 = q -> first;
                    while(N_temp_1 -> id != N_struct_for_swap_1){
                        N_temp_1 = N_temp_1 -> next;
                    }
                    while(N_temp_2 -> id != N_struct_for_swap_2){
                        N_temp_2 = N_temp_2 -> next;
                    }
                    swap(N_temp_1,N_temp_2,q);
                    sorting_id(q);
                    clear();
                }
                else if(N_struct_for_swap_1==1||N_struct_for_swap_2==1){
                    if(N_struct_for_swap_1==1 && N_struct_for_swap_2!=1){
                        N_temp_1 = q -> first;
                        N_temp_2 = q -> first;
                        while(N_temp_2 -> id != N_struct_for_swap_2){
                            N_temp_2 = N_temp_2 -> next;
                        }
                    }
                    if(N_struct_for_swap_1!=1 && N_struct_for_swap_2==1){
                        N_temp_1 = q -> first;
                        N_temp_2 = q -> first;
                        while(N_temp_1 -> id != N_struct_for_swap_1){
                            N_temp_1 = N_temp_1 -> next;
                        }
                    }
                    t = N_temp_1 -> data;
                    N_temp_1 -> data = N_temp_2 -> data;
                    N_temp_2 -> data = t;
                }
            }
            else if(f == 7){
                delete_menu(q);
            }
            else if(f == 8){
                save_list(q);
            }
    }

    while(f != 0){
        if(str_len(s) == 0){
            clear();
            if(f == 1){
                int f1;
                //printf("\nSelect the printing method:\n1) At first\n2) From the end(do not work in this version)\n\nCommand:");
                printf("| | Select the printing method:                |\n");
                printf("+-+--------------------------------------------+\n");
                printf("|1| - At first                                 |\n");
                printf("|2| - From the end(do not work in this version)|\n");
                //printf("|0| - Exit        |\n");
                printf("Command:\n");
                scanf("%d", &f1);
                clear();
                if(f1 == 1) output_list(q);
                //else if(f1 == 2) output_list_reverse(q);
            }
            else if(f == 2){
                enterFromKeyboard(q);
            }
            else if(f == 3){
                edit(q);
            }
            else if(f == 4){
                search_list(q);
            }
            else if(f == 5){
                int f2;
                printf("| | Select the sort method: |\n");
                printf("+-+-------------------------+\n");
                printf("|1| - Value                 |\n");
                printf("|2| - Currency              |\n");
                printf("|3| - Type                  |\n");
                printf("|4| - Country               |\n");
                printf("|5| - Name                  |\n");
                printf("|6| - DATE                  |\n");
                printf("Command:\n");
                scanf("%d", &f2);
                clear();
                if(f2 == 1) sort_value(q);
                else if(f2 == 2) sort_currency(q);
                else if(f2 == 3) sort_type_of_money(q);
                else if(f2 == 4) sort_country(q);
                else if(f2 == 5) sort_name(q);
                else if(f2 == 6) sort_data(q);
            }
            else if(f == 6){
                int N_struct_for_swap_1, N_struct_for_swap_2;
                node *N_temp_1, *N_temp_2;
                printf("Enter the first structure number:");
                scanf("%d", &N_struct_for_swap_1);
                printf("Enter the second structure number:");
                scanf("%d", &N_struct_for_swap_2);
                if(N_struct_for_swap_1>1 && N_struct_for_swap_2>1 &&N_struct_for_swap_1<=q->N&&N_struct_for_swap_2<=q->N){
                    N_temp_1 = q -> first;
                    N_temp_2 = q -> first;
                    while(N_temp_1 -> id != N_struct_for_swap_1){
                        N_temp_1 = N_temp_1 -> next;
                    }
                    while(N_temp_2 -> id != N_struct_for_swap_2){
                        N_temp_2 = N_temp_2 -> next;
                    }
                    swap(N_temp_1,N_temp_2,q);
                    sorting_id(q);
                    clear();
                }
            }
            else if(f == 7){
                delete_menu(q);
            }
            else if(f == 8){
                save_list(q);
            }
        }

        printf("\n| | Menu:          |\n");
        printf("+-+----------------+\n");
        printf("|1| - Print struct |\n");
        printf("|2| - Add stuct    |\n");
        printf("|3| - Edit stuct   |\n");
        printf("|4| - Search struct|\n");
        printf("|5| - Sort struct  |\n");
        printf("|6| - Swap struct  |\n");
        printf("|7| - Delete struct|\n");
        printf("|8| - Save struct  |\n");
        printf("|0| - Exit         |\n");
        printf("Your choice:\n");
        scanf("%s", &s);
        f = charToInt(s[0]);
    }
}
