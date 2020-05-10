#include "struct.h"
#include <stdlib.h>
#ifndef FREE_LIST_H_INCLUDED
#define FREE_LIST_H_INCLUDED

void free_head(head *q);

void free_node(node *temp);

void free_list(head *q);

#endif // FREE_LIST_H_INCLUDED
