#include <stdio.h>
#include <stdbool.h>
#include "../lib/utils.h"

typedef struct Number
{
    int number;
    char *word;
} Number;

/**
 * @brief check if words are similar
 * @param string1 string to compare with string2
 * @param string2 string to compare with string1
 * @param threshold int to say how many letters can be tolerated
 * @return bool
 */
bool wordsAreSimilar(char *string1, char *string2, int threshold)
{
    int missed = 0;
    for (int i = 0; *(string1 + i); i++)
    {
        char letter1 = string1[i];
        char letter2 = string2[i];
        if (letter1 != letter2)
        {
            missed++;
        }
    }
    return missed <= threshold;
}

const Number one = {.number = 1, .word = "one"};
const Number two = {.number = 2, .word = "two"};
const Number three = {.number = 3, .word = "three"};

int main()
{
    const Number numbers[] = {one, two, three};
    int wordsQnt;
    scanf("%d", &wordsQnt);
    int results[wordsQnt];
    for (int i = 0; i < wordsQnt; i++)
    {
        char entry[1000];
        scanf("%s", entry);
        toLower(entry);
        bool isSimilar = false;
        for (int j = 0; j < sizeof(numbers) / sizeof(*numbers); j++)
        {
            Number number = numbers[j];
            isSimilar = wordsAreSimilar(entry, number.word, 1);
            if (isSimilar)
            {
                results[i] = number.number;
                break;
            }
        }
    }
    for (int i = 0; i < wordsQnt; i++)
    {
        printf("%d\n", results[i]);
    }
    return 0;
}
