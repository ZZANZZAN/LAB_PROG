#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 256

typedef struct ZNAK {
    char NAME[MAXLEN];
    char NIK[MAXLEN];
    int DATE[3];
    int chislopole1;
    int chislopole2;
    float chislopole3;
    float chislopole4;
} group;

// Функция для заполения структуры
char **split(char *str, char sep, int len);

// Очищение двумерного динамического массива
void clear_str_array(char **str, int n);

struct ZNAK struct_fill(struct ZNAK tab, char **s2);

void print_header();

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

int main() {
    group *tab;
    char s1[MAXLEN];
    char **s2;
    int i, check, count;
    int number_of_lines;
    FILE *df;
    char sep = ';';
    if ((df = fopen("struct-data-03.csv", "r")) != NULL) {


        void (*VIVOD)(void);
        VIVOD = print_header;
        number_of_lines = 0;
        while ((fgets(s1, MAXLEN, df)) != NULL) number_of_lines++;
        rewind(df);


        //Выделение памяти под структуру
        if ((tab = malloc(number_of_lines * sizeof(group))) != NULL) {
            //Заполнение структуры
            for (i = 0; i < number_of_lines; i++) {
                fgets(s1, MAXLEN, df);
                s1[strlen(s1)] = '\0';
                s2 = split(s1, sep, strlen(s1));
                tab[i] = struct_fill(tab[i], s2);
            }

            check = 1;
            group tmp;
            while (check == 1) {
                check = 0;
                for (i = 0; i < number_of_lines - 1; i++) {
                    if (tab[i].chislopole4 > tab[i+1].chislopole4) {
                        tmp = tab[i];
                        tab[i] = tab[i + 1];
                        tab[i + 1] = tmp;
                        check = 1;
                    }
                }
            }
            VIVOD();
            for (i = 0; i < number_of_lines; i++) {
                printf("|%20s |%10s|%2d|%2d|%2d|%5d|%5d|%10f|%10f|\n",
                       tab[i].NAME,
                       tab[i].NIK,
                       tab[i].DATE[0],
                       tab[i].DATE[1],
                       tab[i].DATE[2],
                       tab[i].chislopole1,
                       tab[i].chislopole2,
                       tab[i].chislopole3,
                       tab[i].chislopole4);
            }

            char bukva[125];
            int stolbec;

            printf("\nDannie dla poiska: ");
            gets(bukva);

            count = 0;
            printf("Kakoi stolbec vibrat` (1- NAME, 2- NIC): ");
            scanf("%d", &stolbec);

            for (i = 0; i < number_of_lines; i++) {

                if ((stolbec == 1) && (strcasestr(tab[i].NAME, bukva)) != NULL) {
                    count++;
                    if (count == 1) VIVOD();
                    printf("|%20s |%10s|%2d|%2d|%2d|%5d|%5d|%10f|%10f|\n", tab[i].NAME, tab[i].NIK, tab[i].DATE[0], tab[i].DATE[1], tab[i].DATE[2], tab[i].chislopole1, tab[i].chislopole2, tab[i].chislopole3, tab[i].chislopole4);
                }
                if ((stolbec == 2) && (strcasestr(tab[i].NIK, bukva)) != NULL) {
                    count++;
                    if (count == 1) VIVOD();
                    printf("|%20s |%10s|%2d|%2d|%2d|%5d|%5d|%10f|%10f|\n", tab[i].NAME, tab[i].NIK, tab[i].DATE[0], tab[i].DATE[1], tab[i].DATE[2], tab[i].chislopole1, tab[i].chislopole2, tab[i].chislopole3, tab[i].chislopole4);
                }
            }
            clear_str_array(s2, 9);
            free(tab);
            tab = NULL;
        } else {
            free(tab);
            tab = NULL;
        }
    } else puts("Unable to open file!");
    return 0;
}

struct ZNAK struct_fill(struct ZNAK tab, char **s2) {
    strcpy(tab.NAME, s2[0]);
    strcpy(tab.NIK, s2[1]);
    tab.DATE[0] = atoi(s2[2]);
    tab.DATE[1] = atoi(s2[3]);
    tab.DATE[2] = atoi(s2[4]);
    tab.chislopole1 = atoi(s2[5]);
    tab.chislopole2 = atoi(s2[6]);
    tab.chislopole3 = atof(s2[7]);
    tab.chislopole4 = atof(s2[8]);
    return tab;
}

char **split(char *str, char sep, int len) {
    int i, m, n;
    int check, count, number_of_words;
    char **p;
    // Подсчет слов в строке
    number_of_words = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == sep) number_of_words++;
    }
    check = 0;
    // Выделение памяти для двумерного массива p
    if ((p = malloc((number_of_words + 1) * sizeof(char *))) != NULL) {
        for (i = 0, count = 0; i <= number_of_words; i++, count++) {
            if ((p[i] = malloc(len * sizeof(char))) != NULL) {
                check = 1;
            } else {
                check = 0;
                i = number_of_words;
            }
        }
        if (check) {
            n = 0;
            m = 0;
            for (i = 0; i < len; i++) {
                if (str[i] != sep) p[n][i - m] = str[i];
                else {
                    p[n][i - m] = '\0';
                    m = i + 1;
                    n++;
                }
            }
        } else
        {
            puts("ERROR at string allocation!\n");
            clear_str_array(p, count);;
        }
    }
    return p;
}

void clear_str_array(char **str, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(str[i]);
        str[i] = NULL;
    }
    free(str);
    str = NULL;
}

void print_header() {
    printf("| %20s|%10s|%10s|%5s|%5s|%10s|%10s|\n", "NAME", "Zod", "Date", "int1", "int2", "float1", "float2");
    printf("+---------------------+----------+----+--+--+-----+-----+----------+----------+\n");
}
