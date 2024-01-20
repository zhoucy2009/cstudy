#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char sentence[64] = "  My  name is Bill.   ";
char *reverse_sentence(char *sentence)
{
    int slen = strlen(sentence);
    char *rev = malloc(slen + 1);
    for (int i = 0; i < slen; i++)
    {
        rev[i] = sentence[slen - i - 1];
    }
    rev[slen] = 0;
    return rev;
}
char *reverse_words(char *sentence)
{
    int max_word = 0;
    int words_size = 0;
    int words_count = 0;
    int words_start = 0;
    int slen = strlen(sentence);
    char *rev = malloc(slen + 1);
    // char words[slen][MAX_WORD];
    for (int i = 0; i < slen + 1; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == 0)
        {
            words_size = i - words_start;
            if (words_size > max_word)
            {
                max_word = words_size;
            }
            while (1)
            {
                if (sentence[i + 1] == ' ')
                {
                    i++;
                }
                else
                {
                    break;
                }
            }
            words_count++;
            words_start = i + 1;
            printf("word end...i=%d words_size=%d words_start=%d words_count=%d\n", i, words_size, words_start, words_count);
        }
    }
    printf("max_word=%d, words_count=%d\n", max_word, words_count);
    return rev;
}
int main()
{
    printf("%s\n", reverse_sentence(sentence));
    printf("%s\n", reverse_words(sentence));
}