#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#define PROGRESS_BAR_SIZE 42
#define MAX_POINT 3

void loader()
{
    int i = 0;
    int j = 0;
    char str[PROGRESS_BAR_SIZE] = "";
    for (i = 0; i <= PROGRESS_BAR_SIZE; i++)
    {
        printf("\r[%s]", str);
        str[i] = '|';
        for (j = i + 1; j <= PROGRESS_BAR_SIZE - 1; j++)
        {
            str[j] = ' ';
        }
        Sleep(100);
    }
}

char *reversePoint(int numberPointToReverse)
{
    char *toReverse = malloc(MAX_POINT + 1);
    int i;
    if (toReverse == NULL)
    {
        return NULL;
    }
    for (i = 0; i < MAX_POINT; i++)
    {
        if (i < numberPointToReverse)
        {
            toReverse[i] = '.';
        }
        else
        {
            toReverse[i] = ' ';
        }
    }
    toReverse[MAX_POINT] = '\0';
    return toReverse;
}

void load_charge()
{
    time_t now = time(NULL);
    int i = 0;
    while ((time(NULL) - now) < (time_t)10)
    {
        char *str = reversePoint(i);
        printf("\rChargement%s", str);
        free(str);
        if (i == 3)
        {
            i = 0;
        }
        else
        {
            i++;
        }

        Sleep(300);
    }
}

char *replaceHerosName(char *txt, char *username, int lenTxt)
{
    static char texteCpy[512];
    char *usernameDefault = "__USERNAME__";

    int i = 0;
    int j = 0;
    for (i = 0; i < lenTxt; i++)
    {
        if (txt[i] == '_' && j == 0)
        {
            j = i + strlen(username);
            i += strlen(usernameDefault);
            break;
        }
        texteCpy[i] = txt[i];
    }

    strcpy(texteCpy, strcat(texteCpy, username));

    int k = 0;
    for (k = i; k < lenTxt; k++)
    {
        // printf("%d => '%c' ,", k, txt[k]);
        texteCpy[j] = txt[k];
        j++;
    }
    texteCpy[j] = '\0';

    return texteCpy;
}

int main(int argc, char const *argv[])
{
    // load_charge();
    // char tab[] = "Je suis quelq'un d'assez fou je reconnais que je suis super-heros.... Bien sur que je suis __USERNAME__(Vous j'en suis fier.)";
    // char s[] = "MUREL ULRICH";

    // char *newTab = replaceHerosName(tab, s, strlen(tab));

    // printf("%s", newTab);

    printf("Nombre negatif %d \n", -1);

    // printf("%s", strstr(tab,s));
}
