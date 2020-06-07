#include "struct.h"
#include <stdlib.h>
#ifndef FREE_LIST_H_INCLUDED
#define FREE_LIST_H_INCLUDED

void free_head(head *q);//освобождение головы

void free_node(node *temp);//освобождение узла

void free_list(head *q);//освобождение списка

#endif // FREE_LIST_H_INCLUDED
