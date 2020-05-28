#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include "struct.h"
#include "option_With_List.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define max 256

void delete_name(head *q);

void delete_country(head *q);

void delete_probability(head *q);

void delete_wins(head *q);

void delete_draws(head *q);

void delete_menu(head *q);

#endif // SEARCH_H_INCLUDED
