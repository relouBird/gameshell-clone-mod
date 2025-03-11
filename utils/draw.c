#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../utils/functions.h"
#include "draw.h"

/*
    Ici il s'agit de toutes les notes qui doivent etre prises dans le processus de creation du Jeu...abort
    ** la MARGE à gauche de 10 espaces...
*/

#define SCRIPTS_SCENARIO "Sous-domaines illimites Compte FTP illimite Migrations de sites Web gratuites Comptes de messagerie illimites Profil d'entreprise Google gratuit Installation WordPress en 1 clic Garantie de remboursement de 10 jours Vous pouvez mettre a jour les informations de connexion de votre compte a partir de votre tableau de bord Merci pour votre achat, n'hesitez pas a nous contacter si vous avez besoin d'aide"
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
 * Cette fonction permet de dessiner le bas du parchemin du jeu...
 */
void draw_footer()
{
    printf("|       |                                                                                             |       |\n");
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
        for (j = i + 1; j <= 70; j++)
        {
            strToWrite[j] = ' ';
        }
        strToWrite[71] = '\0';
        printf("\r|       |          %s            |       |", strToWrite);
        Sleep(10);
    }
    printf("\n");
    free(strToWrite);

    // for (i = 0; i < taille; i++)
    // {
    //     strToWrite[i] = str[i];
    //     for (j = i + 1; j <= 70; j++)
    //     {
    //         strToWrite[j] = ' ';
    //     }
    //     strToWrite[71] = '\0';
    //     printf("\r|       |          %s            |       |\n");
    //     Sleep(200);
    // }
    // free(strToWrite);
}

/**
 * Cette fonction permet d'ecrire le paragraphe de début de l'histoire...
 * @param {char[]} str - Ceci est la chaine de 70 caracteres qui doit etre rediger en temps réel à l'ecran.
 */
void draw_History()
{
    int len = 0;
    int lenPhrases = 0;
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

    draw_empty_row(4);
}