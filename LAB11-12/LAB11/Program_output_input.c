#include "HF/Program_output_input.h"

void print_header() {
    printf("Initial array:\n");
    printf("| %20s|%10s|%10s|%5s|%5s|%10s|%10s|\n", "NAME", "Nik", "Date", "int1", "int2", "float1", "float2");
    printf("+---------------------+----------+----+--+--+-----+-----+----------+----------+\n");
}


void *output_node(node *temp){
    printf("|%20s |%10s|%4d|%2d|%2d|%5d|%5d|%10f|%10f|\n",
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
    int k;
    printf("\nChoose:\n1) add first\n2) add end\n\ncommand:");
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
    }

    printf("\nStructure of an extension to a table:\n");
    printf("Enter the information , otherwise press 'Enter'\n");

    printf("Enter name: ");
    scanf("%s", (temp -> data -> NAME));

    printf("Enter Zodiac sign: ");
    scanf("%s", (temp -> data -> NIK));

    printf("Enter year: ");
    scanf("%f", &(temp -> data -> DATE[0]));

    printf("Enter mounth: ");
    scanf("%f", &(temp -> data -> DATE[1]));

    printf("Enter day: ");
    scanf("%f", &(temp -> data -> DATE[2]));

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
