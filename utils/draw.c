#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "functions.h"
#include "draw.h"
#include "data.h"

/*
    Ici il s'agit de toutes les notes qui doivent etre prises dans le processus de creation du Jeu...abort
    ** la MARGE à gauche de 10 espaces...
*/

#define BLOC_LENGTH 70

/**
 * Cette fonction permet de dessiner le haut du parchemin du jeu...
 */
void draw_header()
{
    printf("  .---------------------------------------------------------------------------------------------------------.  \n");
    printf(" /  .-.                                                                                                 .-.  \\ \n");
    printf("|  /   \\                                                                                               /   \\  |\n");
    printf("| |\\_.  |          Titre :     The Short Isekai Story...                                              |  ._/| |\n");
    printf("|\\|  | /|          =======                                                                            |\\ |  |/|\n");
    printf("| `---' |                                                                                             | `---' |\n");
    printf("|       |          Objectif :   Retrouver son Status D'antan                                          |       |\n");
    printf("|       |          ==========                                                                         |       |\n");
    printf("|       |                                                                                             |       |\n");
    printf("|       |          Histoire :                                                                         |       |\n");
    printf("|       |          ==========                                                                         |       |\n");
    printf("|       |                                                                                             |       |\n");
    // printf("|       |                                                                                             |       |\n");
    // printf("|       |          %s            |       |\n");
}

/**
 * Cette fonction permet d'ecrire les lignes de fins de l'histoire...
 * @param {char[]} str - Ceci est la chaine de caracteres à entrer dans la ligne
 * @param {int} taille - Ceci est la taille de la chaine de caractères passer en paramètres
 */
void draw_row_end(char str[], int taille)
{
    char *strToWrite = calloc(71, sizeof(int));
    int i, j;

    for (i = 0; i < taille - 1; i++)
    {
        strToWrite[i] = str[i];
        for (j = i + 1; j <= BLOC_LENGTH; j++)
        {
            strToWrite[j] = ' ';
        }
        strToWrite[BLOC_LENGTH + 1] = '\0';

        if(i%2 == 0){
            printf("\r    )    %s)", strToWrite);
        }else if (i%2 == 1){
            printf("\r    (    %s(", strToWrite);
        }
        // Sleep(20);
    }
    printf("\n");
    free(strToWrite);
}

/**
 * Cette fonction permet d'ecrire le nom du hero dans une ligne et la surligner....
 * @param {char[]} heroname - Ceci est le nom du Hero
 * @param {int} len - Ceci est la taille du nom
 */
void write_hero_name(char *heroname, int len)
{
    printf("    )    ");
    char str[64] = " ";
    strcat(str,heroname);
    strcat(str," ");
    draw_highlight_test(str);
    int j = 0;
    char *strToWrite = calloc(BLOC_LENGTH - 1 - len, sizeof(int));
    for (j = 0; j <= BLOC_LENGTH - 2 - len; j++)
    {
        strToWrite[j] = ' ';
    }
    strToWrite[j] = '\0';
    printf("%s)\n",strToWrite);
}

/**
 * Cette fonction permet d'ecrire en plusieurs lignes l'histoire de fin
 * @param {char[]} script - Ceci est la chaine de caractères de fin d'histoire
 */
void write_script_to_End(char *script){
    int len = 0;
    int lenPhrases = 0;
    char SCRIPTS_SCENARIO[920];
    snprintf(SCRIPTS_SCENARIO, sizeof(SCRIPTS_SCENARIO), script);
    char **tab = split(SCRIPTS_SCENARIO, strlen(SCRIPTS_SCENARIO), &len);
    char **tabSentences = phrasesToDraw(tab, len, &lenPhrases);

    int i = 0;
    for (i = 0; i < lenPhrases; i++)
    {
        char *str = tabSentences[i];
        draw_row_end(str, strlen(str));
        
    }
    free(tabSentences);
};

/**
 * Cette fonction permet de generer l'histoire de fin 
 * @param {char[]} heroName - Ceci est le nom du hero à utiliser
 * @param {char[]} endScript - Ceci est la fin la petite histoire de fin pour marquer le hero
 */
void draw_end_script(char *heroName, char *endScript)
{
    int len = strlen(heroName);

    printf("     ____________________________________________________________________________    \n");
    printf("    /\\                                                                           \\\n");
    printf("(0)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>)==(0)\n");
    printf("    \\/'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''/\n");
    printf("    )                                                                           )\n");
    printf("    (                                                                           (\n");
    write_hero_name(heroName, len);
    printf("    (                                                                           (\n");
    write_script_to_End(endScript);
    printf("    (                                                                           (\n");
    printf("    )                                                                           )\n");
    printf("    /\\'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\\\n");
    printf("(0)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>)==(0)\n");
    printf("    \\/___________________________________________________________________________/\n");
}

/**
 * Cette fonction permet de dessiner le bas du parchemin du jeu...
 */
void draw_footer()
{
    // printf("|       |                                                                                             |       |\n");
    printf("|       |                                                                                             |       |\n");
    printf("|       |                                                                                             |       |\n");
    printf("| `---' |                                                                                             | `---' |\n");
    printf("|  \\    /                                                                                             \\    /  |\n");
    printf(" \\ _.-./-----------------------------------------------------------------------------------------------\\.-._ / \n");
}

/**
 * Cette fonction permet de creer des lignes vides lors de l'utilisation
 */
void draw_empty_row(int len)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        printf("|       |                                                                                             |       |\n");
    }
}

/**
 * Cette fonction permet d'ecrire une ligne à l'ecran de l'utilisateur sur une marge de 70 charactères...
 * @param {char[]} str - Ceci est la chaine de 70 caracteres qui doit etre rediger en temps réel à l'ecran.
 * @param {int} taille - Ceci represente la taille de la chaine de caractères...
 */
void draw_row(char str[], int taille)
{
    char *strToWrite = calloc(71, sizeof(int));
    int i, j;

    for (i = 0; i < taille - 1; i++)
    {
        strToWrite[i] = str[i];
        for (j = i + 1; j <= BLOC_LENGTH; j++)
        {
            strToWrite[j] = ' ';
        }
        strToWrite[BLOC_LENGTH + 1] = '\0';
        printf("\r|       |          %s            |       |", strToWrite);
        // Sleep(20);
    }
    printf("\n");
    free(strToWrite);
}



/**
 * Cette fonction permet d'ecrire une ligne à l'ecran de l'utilisateur sur une marge de 70 charactères...
 * @param {char[]} str - Ceci est la chaine de 70 caracteres qui doit etre rediger en temps réel à l'ecran.
 * @param {int} taille - Ceci represente la taille de la chaine de caractères...
 */
void draw_row_question(char str[], int taille)
{
    char *strToWrite = calloc(71, sizeof(int));
    int i, j;

    for (i = 0; i < taille - 1; i++)
    {
        strToWrite[i] = str[i];
        for (j = i + 1; j <= (BLOC_LENGTH - 4); j++)
        {
            strToWrite[j] = ' ';
        }
        strToWrite[BLOC_LENGTH + 1] = '\0';
        printf("\r|       |          %s            |       |", strToWrite);
        // Sleep(20);
    }
    printf("\n");
    free(strToWrite);
};

/**
 * Cette fonction permet d'ecrire le coté gauche d'une ligne...
 */
void draw_left_row_side()
{
    printf("|       |          ");
}

/**
 * Cette fonction permet d'ecrire le coté droite d'une ligne en prenant juste en compte le nommbre d'espace a prendre...
 * @param {int} numberLetterLeft Ceci est le nombre d'espacement à mettre
 */
void draw_right_row_side(int numberLetterLeft)
{
    char *str = malloc((numberLetterLeft + 1) * sizeof(char));
    int i;
    for (i = 0; i < numberLetterLeft; i++)
    {
        str[i] = ' ';
    }
    str[i] = '\0';
    printf("%s             |       |\n", str);
    free(str);
}

/**
 * Cette fonction permet d'ecrire le paragraphe de début de l'histoire...
 * @param {char[]} str - Ceci est la chaine de 70 caracteres qui doit etre rediger en temps réel à l'ecran.
 * @param {int} emptyRowLen - Ceci est le nombre de ligne vide  à mettre apres les ecrits...
 */
void draw_History(char *str, int emptyRowLen)
{
    int len = 0;
    int lenPhrases = 0;
    char *SCRIPTS_SCENARIO = getScriptScenario(str);
    char **tab = split(SCRIPTS_SCENARIO, strlen(SCRIPTS_SCENARIO), &len);
    char **tabSentences = phrasesToDraw(tab, len, &lenPhrases);

    // printf("%d", lenPhrases);

    int i = 0;
    for (i = 0; i < lenPhrases; i++)
    {
        char *str = tabSentences[i];
        draw_row(str, strlen(str));
    }
    free(tabSentences);

    draw_empty_row(emptyRowLen);
}

/**
 * Cette fonction permet d'ecrire soit les questions soit le reste du scenario...
 * @param {char[]} str - Ceci est la chaine de caractères à passer
 * @param {Boolean} bool - Ceci permet de dire qu'il s'agit d'une reponse
 */
void draw_Question_Or_Other(char *str, Boolean bool)
{
    int len = 0;
    int lenPhrases = 0;
    char SCRIPTS_SCENARIO[920];
    snprintf(SCRIPTS_SCENARIO, sizeof(SCRIPTS_SCENARIO), str);
    char **tab = split(SCRIPTS_SCENARIO, strlen(SCRIPTS_SCENARIO), &len);
    char **tabSentences = phrasesToDraw(tab, len, &lenPhrases);

    // printf("%d", lenPhrases);

    int i = 0;
    for (i = 0; i < lenPhrases; i++)
    {
        char *str = tabSentences[i];

        if (bool == True)
        {
            if (i >= 1)
            {
                draw_row(str, strlen(str));
            }
            else
            {
                draw_row_question(str, strlen(str));
            }
        }
        else
        {
            draw_row(str, strlen(str));
        }
    }
    free(tabSentences);

    draw_empty_row(1);
}

/**
 * Cette fonction permet de mettre l'effet de surlignement....
 */
void setHighlight()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
}

/**
 * Cette fonction permet d'enlever l'effet de surlignement....
 */
void resetHighlight()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute(hConsole, 0 | 0 | 0);
}

/**
 * Cette fonction permet de mettre du teste en surligné
 */
void draw_highlight_test(char *str)
{
    setHighlight();
    printf("%s", str);
    resetHighlight();
}
