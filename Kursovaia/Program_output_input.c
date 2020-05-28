#include "HF/Program_output_input.h"

void print_header() {
    printf("Initial array:\n");
    printf("|%2s|%5s|%10s|%10s|%10s|%10s|%4s|\n","N", "Value", "Currency", "Type", "Country", "Name", "DATE");
    printf("+--+-----+----------+----------+----------+----------+----+\n");
}


void *output_node(node *temp){
    printf("|%2d|%5d|%10s|%10s|%10s|%10s|%4d|\n",
            temp -> id,
            temp -> data ->face_value,
            temp -> data ->currency,
            temp -> data ->type_of_money,
            temp -> data ->country,
            temp -> data ->name,
            temp -> data ->DATE);
}

char *strcasestr(const char *str, const char *pattern) {
    size_t i;

    if (!*pattern)
        return (char*)str;

    for (; *str; str++) {
        if (toupper(*str) == toupper(*pattern)) {
            for (i = 1;; i++) {
                if (!pattern[i])
                    return (char*)str;
                if (toupper(str[i]) != toupper(pattern[i]))
                    break;
            }
        }
    }
    return NULL;
}

void search(head *q){
    node *temp = NULL;
    temp = q -> first;
    char s[max];
    int f;
    printf("| | Select the search method:|\n");
    printf("+-+--------------------------+\n");
    printf("|1| - currency        |\n");
    printf("|2| - type of money   |\n");
    printf("|3| - country         |\n");
    printf("|4| - name            |\n");
    printf("Command:\n");
    scanf("%d", &f);
    if (f != 0){
        printf("Search Data:");
        scanf("%s", &s);
        if (f == 1){
            while(temp -> next != NULL){
                if ((strcasestr(temp -> data -> currency, s)) != NULL) output_node(temp);
               temp = temp -> next;
            }
        }
        else if(f == 2){
            while(temp -> next != NULL){
                if ((strcasestr(temp -> data -> type_of_money, s)) != NULL) output_node(temp);
               temp = temp -> next;
            }
        }
        else if(f == 3){
            while(temp -> next != NULL){
                if ((strcasestr(temp -> data -> country, s)) != NULL) output_node(temp);
               temp = temp -> next;
            }
        }
        else if(f == 4){
            while(temp -> next != NULL){
                if ((strcasestr(temp -> data -> name, s)) != NULL) output_node(temp);
               temp = temp -> next;
            }
        }
    }
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
    printf("|0| - Exit        |\n");
    printf("Your choice:\n");
    scanf("%d", &k);
    if(k != 0 && (k == 1 || k == 2 || k == 3)){
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

    printf("Enter face value: ");
    scanf("%d", &(temp -> data -> face_value));
    printf("Enter currency: ");
    scanf("%s", (temp -> data -> currency));
    printf("Enter type_of_money: ");
    scanf("%s", (temp -> data -> type_of_money));
    printf("Enter country: ");
    scanf("%s", (temp -> data -> country));
    printf("Enter name: ");
    scanf("%s", (temp -> data -> name));
    printf("Enter year: ");
    scanf("%d", &(temp -> data -> DATE));
    }

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

        if (fclose(fileread) == EOF) printf("Open error code: %d\n", errno);
        else printf("Open OK\n");
    }

    output_list(q);
}

void save_list(head *q){
    FILE *file = fopen("struct-data-03.csv", "w");
    if (file == NULL)
        perror("data error");
    else{
        if(q -> N > 0){
            node *temp = NULL;
            temp = q -> first;
            int t = q -> N;
            for(int i = 1; i <= t; i++){
                fprintf(file, "%d;", temp -> data ->face_value);
                fprintf(file, "%s;", temp -> data -> currency);
                fprintf(file, "%s;", temp -> data -> type_of_money);
                fprintf(file, "%s;", temp -> data -> country);
                fprintf(file, "%s;", temp -> data -> name);
                fprintf(file, "%8d;\n", temp -> data -> DATE);
                temp = temp -> next;
            }
        }
        else fprintf(file, " ");
        if (fclose(file) == EOF) printf("Closing error code: %d\n", errno);
        else printf("Save OK\n");
    }
}
