#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include "option_With_List.h"
#include "split.h"
#include <string.h>
#define max 256
#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

void print_header();

void *output_node(node *temp);

void output_list(head *q);

void output_list_reverse(head *q);

void enterFromKeyboard(head *q);

void fill_list(head *q);

group *struct_fill(char **str);

void save_list(head *q);
#endif // IO_H_INCLUDED
