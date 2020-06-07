#ifndef SPLIT_H_INCLUDED
#define SPLIT_H_INCLUDED
#include "option_With_List.h"
#include "struct.h"
#include <stdlib.h>


int str_len(char *s);//длина строки

int charToInt(char numeric);//преобразование типов

void split(char *mes, head *q);//распределение данных по труктуре

#endif // SPLIT_H_INCLUDED
