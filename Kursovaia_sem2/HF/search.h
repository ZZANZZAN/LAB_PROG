#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include "struct.h"
#include "option_With_List.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define max 256

void delete_one(head *q);//удаление одного узла

void delete_currency(head *q);//удаление

void delete_type_of_money(head *q);//удаление  по типу денег

void delete_country(head *q);//удаление по стране

void delete_name(head *q);//удаление по названию

void delete_menu(head *q);//меню удаления

#endif // SEARCH_H_INCLUDED
