#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** 
 * @brief in-place converter to upper case
 * @param p char pointer to convert
 * @return void
 */
void toUpper(char *p)
{
    for (; *p; ++p)
        *p = toupper(*p);
}

/**
 * @brief in-place converter to lower case
 * @param p char pointer to convert
 * @return void
 */
void toLower(char *p)
{
    for (; *p; ++p)
        *p = tolower(*p);
}

/** 
 * @brief split string by delimiter
 * @param str string to split
 * @param delimiter character to split by
 * @return char**
 */
char **split(char *str, const char delimiter)
{
    char **result = 0;
    size_t count = 0;
    char *tmp = str;
    char *last_comma = 0;
    char delim[2];
    delim[0] = delimiter;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (delimiter == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (str + strlen(str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char *) * count);

    if (result)
    {
        size_t idx = 0;
        char *token = strtok(str, delim);

        while (token)
        {
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        *(result + idx) = 0;
    }

    return result;
}

/** 
 * @brief removes whitespace in a string
 * @param str string to remove whitespaces
 * @return char*
 */
char *trim(char *str)
{
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str))
        str++;

    if (*str == 0) // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    // Write new null terminator character
    end[1] = '\0';

    return str;
}

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
