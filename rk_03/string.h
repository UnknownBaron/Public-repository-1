#ifndef STRING_H__
#define STRING_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 100

typedef struct name
{
    char *word;
    int reps;
} name_t;

void replace_n(char *string);

int name_comparator(const void *a, const void *b);

#endif