#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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

    return i;
}

void readfs(char *str)
{
    char ch;
    char input[100] = {""};
    int i = 0;

    while (1)
    {
        ch = getch();
        if (ch == '\r')
        {
            break;
        }
        if (i < (sizeof(input) - 1))
        {
            input[i++] = ch;
            putchar(ch);
        }
    }

    input[i] = '\0';
    strcpy(str, input);
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

/**
 * Cette fonction permet de load l'histoire en remplaçant le nom generique par le nom dun joueur
 * @param {char[]}  txt Ceci est le texte dans lequel on doit effectuer le remplacement.
 * @param {char[]} username Ceci est le nom d'utilisateur à remplacer
 * @param {int} lenTxt Ceci est la taille de la chaine de caracteres passée en premier parametre...
 * @return {char[]}
 */
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


/**
 * Cette fonction permet de load un texte et remplace le lieu
 * @param {char[]}  txt Ceci est le texte dans lequel on doit effectuer le remplacement.
 * @param {char[]} location Ceci est le lieu à remplacer
 * @param {int} lenTxt Ceci est la taille de la chaine de caracteres passée en premier parametre...
 * @return {char[]}
 */
char *replaceLocation(char *txt, char *location, int lenTxt)
{
    static char texteCpy[920];
    char *locationDefault = "__WHEREAME__";
    int i = 0;
    int j = 0;
    for (i = 0; i < lenTxt; i++)
    {
        if (txt[i] == '_' && j == 0)
        {
            j = i + strlen(location);
            i += strlen(locationDefault);
            break;
        }
        texteCpy[i] = txt[i];
    }
    strcat(texteCpy, location);

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