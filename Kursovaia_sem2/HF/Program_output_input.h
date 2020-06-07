#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include "option_With_List.h"
#include "split.h"
#include <string.h>
#define max 256
#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

void print_header();//печать шапки

void *output_node(node *temp);//вывод структуры

void search_list(head *q);

void output_list(head *q);//вывод списка

void output_list_reverse(head *q);//вывод списка наоборот

void enterFromKeyboard(head *q);//запрос данных у пользователя с клавиатуры

void fill_list(head *q);//запись из файла в список

group *struct_fill(char **str);

void save_list(head *q);//сохранение списка
#endif // IO_H_INCLUDED
