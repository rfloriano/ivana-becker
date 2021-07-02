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