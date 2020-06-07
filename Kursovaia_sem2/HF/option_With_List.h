#ifndef OPTION_WITH_LIST_H_INCLUDED
#define OPTION_WITH_LIST_H_INCLUDED
#include "free_List.h"
#include "struct.h"
#include <malloc.h>
#include <stdlib.h>

void malloc_node(node *temp);//��������� ������ ��� ���������

head *create_head_DLL();//�������� ������

node *create_node_DLL(head *q);//�������� ����

void add_last_DLL(head *q);//���������� ���� ���������

node *add_first_DLL(head *q);//���������� ���� ������

void delete_first_DLL(head *q);//������� ������ ����

void delete_node_DLL(node *temp, head *q);//�������� ���� �� ������

void sorting_id(head *q);//���������� �������

node *swap(node *lst1, node *lst2, head *head);//������������ �����

void sort_data(head *q);

void sort_value(head *q);

void sort_country(head *q);

void sort_type_of_money(head *q);

void sort_currency(head *q);

void sort_name(head *q);

void edit(head *q);//��������� ������ � ����
//node insert_after_DLL(node *lst);
#endif // OPTION_WITH_LIST_H_INCLUDED
