#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define BLOC_LENGTH 70

/**
 * Cette fonction renvoie zero (0) si la chaine est vide et change directement la chaine de caractères que vous le passiez en parametre
 * @param {char[]} str - c'est la chaine de caractères qu'on lira au clavier;
 * @returns {int}
 */
int readf(char *str)
{
    int i;

    static int length = 256;

    fgets(str, length, stdin);

    for (i = 0; i <= length - 1; i++)
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
    };

    // return i;
}

/**
 * Cette fonction permet de diviser un chaine de caractères selon un motif...ABC
 * @param {char*} scripts Ceci est la chaine de characteres a diviser selon le concept
 * @param {int} lenScript Ceci est la taille de la chaine a diviser.
 * @param {int*} taille Ceci est un pointeur vers la taille du tableau contenant tout les differents mots obtenu par le motif...
 * @return {char**}
 */
char **split(char *scripts, int lenScript, int *taille)
{
    char *str = calloc(lenScript + 1, sizeof(char));
    strcpy(str, scripts);
    int len = strlen(str);
    int capacity = 25;
    char d[] = " ";

    // printf("%d", len);
    char **tab = malloc(capacity * sizeof(char *));

    char *p = strtok(str, d);

    int i = 0;
    while (p != NULL)
    {
        if (i >= capacity)
        {
            capacity *= 2;
            tab = realloc(tab, capacity * sizeof(char *));
        }
        tab[i] = strdup(p);
        // printf("'%s' \n", tab[i]);
        i++;
        p = strtok(NULL, d);
    }
    free(str);
    *taille = i;
    return tab;
}


/**
 * Cette fonction renvoie un tableau de chaine caractères contenant les differents differents phrases à rediger
 * @param {char**} tabStr Ceci est le tableau des differents mots à ajouter dans les phrases
 * @param {int} len Ceci est la taille du premier tableau passé en parametre
 * @return {char**}
 */
char **phrasesToDraw(char **tabStr, int len, int *numberSentences)
{
    int lenWords = (int)BLOC_LENGTH;
    int capacity = 25;

    char *words = calloc(lenWords, sizeof(char));
    char **tab = calloc(capacity, sizeof(char *));

    int i = 0;
    int j = 0;
    int lenNow = 0;
    int numPhrases = 0;
    for (i = 0; i < len; i++)
    {
        char *str = strdup(tabStr[i]);
        if ((capacity - numPhrases) <= 5)
        {
            capacity += 10;
            tab = realloc(tab, capacity * sizeof(char *));
        }
        if (lenNow + strlen(str) >= lenWords)
        {
            tab[numPhrases] = strdup(words);
            // printf("\n %s \n", tab[numPhrases]);
            free(words);
            words = calloc(lenWords, sizeof(char));
            numPhrases++;
            lenNow = 0;
        }

        words = strcat(words, strcat(str, " "));
        lenNow = lenNow + strlen(str) + 1;

        if (i == (len - 1))
        {
            tab[numPhrases] = strdup(words);
            free(words);
            numPhrases++;
        }
    }

    // for (j = 0; j < numPhrases; j++)
    // {
    //     printf("%s \n", tab[j]);
    // }

    *numberSentences = numPhrases;
    free(tabStr);
    return tab;
}