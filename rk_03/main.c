#include "string.h"

int main(void)
{
    FILE *infile = fopen("in.txt", "r");

    name_t *names = malloc(sizeof(name_t));
    int counter = 0;
    char delta[BUF_LEN];
    if (names == NULL)
        return -1;

    name_t *tmp;
    int flag;

    while (fgets(delta, BUF_LEN, infile))
    {
        replace_n(delta);
        flag = 0;
        for (int i = 0; i < counter && flag == 0; i++)
        {
            if (strcmp(delta, names[i].word) == 0)
            {
                flag = 1;
                names[i].reps++;
            }
        }

        if (flag == 0)
        {
            counter++;
            tmp = realloc(names, (sizeof(name_t) * counter));
            if (tmp == NULL)
                return -1;

            names = tmp;

            names[counter - 1].word = malloc(sizeof(char) * strlen(delta));
            strcpy(names[counter - 1].word, delta);
            names[counter - 1].reps = 1;
        }
    }

    qsort(names, counter, sizeof(name_t), name_comparator);

    fclose(infile);

    FILE *outfile = fopen("out.txt", "w");

    for (int i = 0; i < counter; i++)
    {
        for (int j = 0; j < strlen(names[i].word) - 1; j++)
            fprintf(outfile, "%c", names[i].word[j]);

        fprintf(outfile, ": %d\n", names[i].reps);   
        free(names[i].word);
    }
    free(names);
    fclose(outfile);
}