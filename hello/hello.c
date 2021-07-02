#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Language
{
    char *name;
    char *message;
} Language;

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

int main()
{
    Language english = {.name = "INGLES", .message = "HELLO"};
    Language spanish = {.name = "ESPANHOL", .message = "HOLA"};
    Language german = {.name = "ALEMAO", .message = "HALLO"};
    Language french = {.name = "FRANCES", .message = "BONJOUR"};
    Language italian = {.name = "ITALIANO", .message = "CIAO"};
    Language russian = {.name = "RUSSO", .message = "ZDRAVSTVUJTE"};
    Language languages[] = {english, spanish, german, french, italian, russian};

    char text[1000];
    scanf("%[^#]", text);
    char **lines = split(text, '\n');
    for (int i = 0; *(lines + i); i++)
    {
        bool found = false;
        char *msg = "Caso %d:  %s\n";
        for (int j = 0; j < sizeof(languages) / sizeof(*languages); j++)
        {
            Language language = languages[j];
            if (strcmp(language.message, lines[i]) != 0)
            {
                continue;
            }
            found = true;
            printf(msg, i + 1, language.name);
        }
        if (!found)
        {
            printf(msg, i + 1, "DESCONHECIDO");
        }
    }
    return 0;
}
