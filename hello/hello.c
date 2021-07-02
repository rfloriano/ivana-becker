#include <stdbool.h>
#include <string.h>
#include "../lib/utils.h"

typedef struct Language
{
    char *name;
    char *message;
} Language;

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
    toUpper(text);
    char **lines = split(text, '\n');
    for (int i = 0; *(lines + i); i++)
    {
        bool found = false;
        char *msg = "Caso %d:  %s\n";
        char *line = trim(lines[i]);
        for (int j = 0; j < sizeof(languages) / sizeof(*languages); j++)
        {
            Language language = languages[j];
            if (strcmp(language.message, line) != 0)
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
