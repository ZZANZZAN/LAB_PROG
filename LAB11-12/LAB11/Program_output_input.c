#include "HF/Program_output_input.h"

void print_header() {
    printf("Initial array:\n");
    printf("|%2s| %20s|%10s|%10s|%5s|%5s|%10s|%10s|\n","N", "NAME", "Nik", "Date", "int1", "int2", "float1", "float2");
    printf("+--+---------------------+----------+----+--+--+-----+-----+----------+----------+\n");
}


void *output_node(node *temp){
    printf("|%2d|%20s |%10s|%4d|%2d|%2d|%5d|%5d|%10f|%10f|\n",
            temp -> id,
            temp -> data ->NAME,
            temp -> data ->NIK,
            temp -> data ->DATE[0],
            temp -> data ->DATE[1],
            temp -> data ->DATE[2],
            temp -> data ->chislopole1,
            temp -> data ->chislopole2,
            temp -> data ->chislopole3,
            temp -> data ->chislopole4);
}


void output_list(head *q){
    if((q -> N) > 0){
        node *temp = NULL;

        temp = q -> first;

        print_header();

        while((temp -> next) != NULL){
            output_node(temp);
            temp = temp -> next;
        }

        output_node(temp);
    }
    else printf("\ndatabase is empty!\n");
}


void output_list_reverse(head *q){
    if((q -> N) > 0){
        node *temp = NULL;

        temp = q -> last;

        print_header();

        while((temp -> prev) != NULL){
            output_node(temp);
            temp = temp -> prev;
        }

        output_node(temp);
    }
    else printf("\ndatabase is empty!\n");
}


void enterFromKeyboard(head *q)
{
    node *temp = NULL;
    node *p = q -> first;
    int k, index, i = 0;
    printf("\n| | Add:          |\n");
    printf("+-+---------------+\n");
    printf("|1| - Add first   |\n");
    printf("|2| - Add end     |\n");
    printf("|3| - Enter index |\n");
    printf("Your choice:\n");
    scanf("%d", &k);
    if((q -> N) == 0) temp = create_node_DLL(q);
    else{
        if(k == 2){
            add_last_DLL(q);
            temp = q -> last;
        }
        else if(k == 1){
            add_first_DLL(q);
            temp = q -> first;
        }
        else if(k == 3){
            printf("Enter index:");
            scanf("%d", &index);
            if(index > q -> N || index <= 1){
                add_first_DLL(q);
                temp = q -> first;
            }else{
                q -> N += 1;
                while (i < index - 1){//printf("bingo\n");
                    p = p->next;
                    i++;
                }
            temp = insert_after_DLL(p, q -> N);
            }
            //temp = q -> first;
        }
    }

    printf("Enter name: ");
    scanf("%s", (temp -> data -> NAME));

    printf("Enter Zodiac sign: ");
    scanf("%s", (temp -> data -> NIK));

    printf("Enter year: ");
    scanf("%d", &(temp -> data -> DATE[0]));

    printf("Enter mounth: ");
    scanf("%d", &(temp -> data -> DATE[1]));

    printf("Enter day: ");
    scanf("%d", &(temp -> data -> DATE[2]));

    puts("Enter like chislo:");
    scanf("%d", &(temp -> data -> chislopole1));

    puts("Enter good chislo:");
    scanf("%d", &(temp -> data -> chislopole2));

    puts("Enter percentage of luck:");
    scanf("%f", &(temp -> data -> chislopole3));

    puts("Enter confidence percentage:");
    scanf("%f", &(temp -> data -> chislopole4));
}


void fill_list(head *q){
    char message[max];

    FILE *fileread = fopen("struct-data-03.csv", "r");

    if (fileread == NULL) perror("data error");
    else{
        char mes[max];

        fgets(message, max, fileread);

        while (strcmp(message, mes) != 0){
            char *str;

            strcpy(mes, message);

            str = &message;

            split(str, q);

            fgets(message, max, fileread);
        }

        if (fclose(fileread) == EOF) printf("Closing error code: %d\n", errno);
        else printf("Closing OK\n");
    }

    output_list(q);
}
