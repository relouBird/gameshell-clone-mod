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

int main(int argc, char const *argv[])
{
    // load_charge();
    char tab[] = "Je suis quelq'un d'assez fou je reconnais que je suis super-héros....";
    printf("%d", strlen(tab));
    return 0;
}
