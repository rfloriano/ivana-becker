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

bool strIncludes(char *str, char c)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (c == str[i])
        {
            return true;
        }
    }
    return false;
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
    char *msg = "Caso %d:  %s\n";
    int counter = 0;
    char result[1000];
    int size = 0;
    while (true)
    {
        char text[1000];
        scanf("%s", text);
        if (strIncludes(text, '#'))
        {
            break;
        }
        bool found = false;
        for (int i = 0; i < sizeof(languages) / sizeof(*languages); i++)
        {
            Language language = languages[i];
            if (strcmp(language.message, text) != 0)
            {
                continue;
            }
            found = true;
            size += sprintf(result + size, msg, counter + 1, language.name);
        }
        if (!found)
        {
            size += sprintf(result + size, msg, counter + 1, "DESCONHECIDO");
        }
        counter++;
    }
    printf("%s", result);
    return 0;
}
