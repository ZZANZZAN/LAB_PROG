#ifndef OPTION_WITH_LIST_H_INCLUDED
#define OPTION_WITH_LIST_H_INCLUDED
#include "free_List.h"
#include "struct.h"
#include <malloc.h>
#include <stdlib.h>

void malloc_node(node *temp);//выделение памяти под структуру

head *create_head_DLL();//создание головы

node *create_node_DLL(head *q);//создание узла

void add_last_DLL(head *q);//добавление узла последним

node *add_first_DLL(head *q);//добавление узла первым

void delete_first_DLL(head *q);//удалить первый узел

void delete_node_DLL(node *temp, head *q);//удаление узла по номеру

void sorting_id(head *q);//сортировка номеров

node *swap(node *lst1, node *lst2, head *head);//перестановка узлов

void sort_data(head *q);

void sort_value(head *q);

void sort_country(head *q);

void sort_type_of_money(head *q);

void sort_currency(head *q);

void sort_name(head *q);

void edit(head *q);//изменение данных в узле
//node insert_after_DLL(node *lst);
#endif // OPTION_WITH_LIST_H_INCLUDED
