#include <stdio.h>
#include <string.h>
#include "functions.h"

typedef enum KARMA_POINT
{
    PLUS = 1,
    NEUTRAL = 0,
    MINUS = -1,

} KARMA_POINT;

#define SCRIPTS_SCENARIO "L'histoire nous entraine dans le quotidien de Melaiid,fils du roi Thophild qui a ete assassine par un membre du conseil d'administration de son pere lors d'une reception et par la suite s'est reincarne dans le corps d'un enfant originaire d'un bidonville appele __USERNAME__(Vous) et s'est des lors fixe pour objectif de retrouver son statut social."

typedef struct QUESTION
{
    char *prompt;
    char *responses[3];
    KARMA_POINT karmalist[3];
} QUESTION;

/**
 * Cette fonction prend en parametre le nom du joueur et renvoie l'histoire de departs
 */
char *getScriptScenario(char *username)
{
    char *scriptToSend = replaceHerosName(SCRIPTS_SCENARIO, username, strlen(SCRIPTS_SCENARIO));
    return scriptToSend;
}

/**
 * Cette fonction retourne toutes les questions du jeu
 * @param {int *} questionNumber - Ceci permet de recuperer le nombre de question
 * @return {QUESTION}
 */
QUESTION *getGamesQuestions(int *questionNumber)
{
    KARMA_POINT karmalist[] = {PLUS, NEUTRAL, MINUS};
    QUESTION question1 = {
        "Lors de votre balade matinale,il rencontre un jeune homme entrain de se faire arnaquer. Que faites-vous ?",
        {"Faire des signes pour qu'il comprenne que c'est une arnaque",
         "Juste observer la scène",
         "Se moquer de lui"},
        karmalist};

    QUESTION question2 = {
        "Juste après cela,vous décidez de l'approcher et vous constatez qu'il pourrait appartenir à la noblesse. Que faites-vous ?",
        {"Le faire comprendre qu'il a été arnaqué",
         "Discuter avec lui sur le produit qu'il a acheté",
         "Lui dire qu'il a fait une bonne affaire"},
        karmalist};

    QUESTION question3 = {
        "Lors de votre balade matinale,il rencontre un jeune homme entrain de se faire arnaquer. Que faites-vous ?",
        {"Faire des signes pour qu'il comprenne que c'est une arnaque",
         "Juste observer la scène",
         "Se moquer de lui"},
        karmalist};

    QUESTION question4 = {
        "Lors de votre balade matinale,il rencontre un jeune homme entrain de se faire arnaquer. Que faites-vous ?",
        {"Faire des signes pour qu'il comprenne que c'est une arnaque",
         "Juste observer la scène",
         "Se moquer de lui"},
        karmalist};

    QUESTION question4 = {
        "Lors de votre balade matinale,il rencontre un jeune homme entrain de se faire arnaquer. Que faites-vous ?",
        {"Faire des signes pour qu'il comprenne que c'est une arnaque",
         "Juste observer la scène",
         "Se moquer de lui"},
        karmalist};

    QUESTION questionsList[] = {question1, question2, question3, question4};

    *questionNumber = 5;

    return questionsList;
}