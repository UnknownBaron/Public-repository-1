#include "string.h"

void replace_n(char *string)
{
    char *ptr = string;
    while ((*ptr) != '\n' && (*ptr) != '\0')
        ptr++;

    *ptr = '\0';
}

int name_comparator(const void *a, const void *b)
{
    const name_t *na = a;
    const name_t *nb = b;
    return strcmp(na->word, nb->word);
}