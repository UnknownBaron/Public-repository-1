#ifndef STRING_H__
#define STRING_H__

#define BUF_LEN 1000

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    char *sentence;
    struct node *next_node;
} node_t;

void delete_n(char *string);

int count_spaces(char *string);


int divide_sentence(node_t *node);

int divide_word(node_t *node);

#endif