#include "string.h"

void delete_n(char *string)
{
    char *ptr = string;
    while (*ptr != '\0' && *ptr != '\n')
        ptr++;
    *ptr = '\0';
}

int count_spaces(char *string)
{
    char *ptr = string;
    int counter = 0;
    while (*ptr != '\0')
    {
        if (isspace(*ptr))
            counter++;
        
        ptr++;
    }

    return counter;
}

int divide_sentence(node_t *node)
{
    node_t *next_sent = node->next_node;
    int words = count_spaces(node->sentence);

    node_t *adding_node = NULL;
    node_t *prev_node = node;
    char *buffer = malloc(strlen(node->sentence)); 
    strcpy(buffer, node->sentence);

    char *ptr1 = buffer;
    char *ptr2 = ptr1;
    for (int i = 0; i < words && *(ptr2 - 1) != '\0'; i++)
    {
        while (*ptr2 != '\0' && !(isspace(*ptr2)))
            ptr2++;
        *ptr2 = '\0';
        
        if (i != 0)
        {
            adding_node = malloc(sizeof(node_t));
            if (adding_node == NULL)
                return -2;
            adding_node->next_node = NULL;

            adding_node->sentence = malloc(strlen(ptr1) * sizeof(char));
            if (adding_node->sentence == NULL)
                return -2;
            strcpy(adding_node->sentence, ptr1);


            prev_node->next_node = adding_node;
            prev_node = adding_node;
        }
        else
            strcpy(node->sentence, ptr1);

        ptr1 = ptr2 + 1;
        ptr2++;
    }
    adding_node->next_node = next_sent;

    free(buffer);

    return 0;
}

int divide_word(node_t *node)
{
    node_t *next_sent = node->next_node;
    int letters = strlen(node->sentence);

    node_t *adding_node = NULL;
    node_t *prev_node = node;
    char *buffer = malloc(strlen(node->sentence)); 
    strcpy(buffer, node->sentence);

    char *ptr = buffer;
    char delta;

    for (int i = 0; i < letters - 1; i++)
    {
        if (i != 0)
        {
            adding_node = malloc(sizeof(node_t));
            if (adding_node == NULL)
                return -2;
            adding_node->next_node = NULL;

            adding_node->sentence = malloc(strlen(ptr) * sizeof(char));
            if (adding_node->sentence == NULL)
                return -2;

            delta = *(ptr + 1);
            *(ptr + 1) = '\0';
            strcpy(adding_node->sentence, ptr);
            *(ptr + 1) = delta;
            

            prev_node->next_node = adding_node;
            prev_node = adding_node;
        }
        else
        {
            delta = *(ptr + 1);
            *(ptr + 1) = '\0';
            strcpy(node->sentence, ptr);
            *(ptr + 1) = delta;
        }

        ptr++;
    }
    adding_node->next_node = next_sent;

    free(buffer);

    return 0;
}