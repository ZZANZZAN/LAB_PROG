#ifndef OPTION_WITH_LIST_H_INCLUDED
#define OPTION_WITH_LIST_H_INCLUDED
#include "free_List.h"
#include "struct.h"
#include <malloc.h>
#include <stdlib.h>

void malloc_node(node *temp);

head *create_head_DLL();

node *create_node_DLL(head *q);

void add_last_DLL(head *q);

node *add_first_DLL(head *q);

void delete_first_DLL(head *q);

void delete_node_DLL(node *temp, head *q);

#endif // OPTION_WITH_LIST_H_INCLUDED
