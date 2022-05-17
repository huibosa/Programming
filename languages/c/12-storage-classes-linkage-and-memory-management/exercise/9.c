#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(void)
{
    char ** ptr;
    int nb_words;
    char temp_word[LEN];
    size_t char_array_len;

    printf("How many words you wish to enter? ");
    scanf("%d", &nb_words);
    ptr = malloc(nb_words * sizeof(char *));

    for (int i = 0; i < nb_words; i++)
    {
        scanf("%39s", temp_word);
        char_array_len = strlen(temp_word) + 1;
        ptr[i] = malloc(char_array_len * sizeof(char));
        strncpy(ptr[i], temp_word, char_array_len);
    }

    for (int i = 0; i < nb_words; i++)
    {
        puts(ptr[i]);
        free(ptr[i]);
    }
    free(ptr);
    return 0;
}
