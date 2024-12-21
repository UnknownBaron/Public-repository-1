#include "string.h"

int main(void)
{
    FILE *infile = fopen("in.txt", "r");
    if (infile == NULL)
        return -2;

    node_t *list = NULL;
    char delta[BUF_LEN];

    node_t *adding_node;
    node_t *list_ptr;

    //int flag;

    while (fgets(delta, BUF_LEN, infile))
    {
        delete_n(delta);

        adding_node = malloc(sizeof(node_t));
        if (adding_node == NULL)
            return -1;

        adding_node->sentence = malloc(strlen(delta));
        if (adding_node->sentence == NULL)
            return -1;
        strcpy(adding_node->sentence, delta);

        adding_node->next_node = NULL;

        if (list != NULL)
            list_ptr->next_node = adding_node;
        else
            list = adding_node;

        list_ptr = adding_node;
    }

    fclose(infile);



    list_ptr = list;
    while (list_ptr != NULL)
    {
        if (count_spaces(list_ptr->sentence) > 1)
        {
            if (divide_sentence(list_ptr) != 0)
               return -1;
        }
        else
        {
            if (divide_word(list_ptr) != 0)
                return -1;;
        }

        list_ptr = list_ptr->next_node;
    }




    FILE *outfile = fopen("out.txt", "w");
    if (outfile == NULL)
        return -2;

    list_ptr = list;

    while (list_ptr != NULL)
    {
        //printf("%s\n", list_ptr->sentence);
        fputs(list_ptr->sentence, outfile);
        free(list_ptr->sentence);
        list_ptr = list_ptr->next_node;
    }

    fclose(outfile);
}