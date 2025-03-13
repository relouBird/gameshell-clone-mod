#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

typedef enum KARMA_POINT
{
    PLUS = 1,
    NEUTRAL = 0,
    MINUS = -1,

} KARMA_POINT;

#define SCRIPTS_SCENARIO "L'histoire nous entraine dans le quotidien de Melaiid,fils du roi Thophild qui a ete assassine par un membre du conseil d'administration de son pere lors d'une reception et par la suite s'est reincarne dans le corps d'un enfant originaire d'un bidonville appele __USERNAME__(Vous) et s'est des lors fixe pour objectif de retrouver son statut social."

#define PP "Malheureusement pour vous,il s'avère être qu'il a une soirée masquée demain avec les aristocrates de la région à l'occasion de l'anniversaire de la fille aînée du compte Gherhad de la Oya. Il s'excuse ainsi auprès de vous,vous remets une bourse pleine à ras bord de pierre précieuse et vous supplie d'accepter que la calèche vous ramène. Vous acceptez que la calèche vous ramène, en cours de route vous voyez une boutique de vêtements luxueux et là une idée vous traverse l'esprit:Et si je me rendais à cette soirée ? Vous demandez alors à la calèche de s'arrêter devant la boutique en prétextant que votre domicile est dans les alentours. Après le départ de la calèche,vous entrez dans la boutique"

#define QUESTIONS_NUMBER 5
#define QUESTIONS_RESPONSES_NUMBER 3

typedef struct QUESTION
{
    char *prompt;
    char **responses;
    int karmalist[3];
} QUESTION;

typedef struct QUESTION_SECOND
{
    char prompt[512];
    char responses[3][128];
    int karmalist[3];
} QUESTION_SECOND;

/**
 * Cette fonction prend en parametre le nom du joueur et renvoie l'histoire de departs
 */
char *getScriptScenario(char *username)
{
    char *scriptToSend = replaceHerosName(SCRIPTS_SCENARIO, username, strlen(SCRIPTS_SCENARIO));
    return scriptToSend;
}

/**
 * Cette fonction permet d'initialiser les questions qu'on devra utiliser plus tard
 * @param {QUESTION[]} quest - Ceci est le pointeur vers la tableau des questions
 * @param {char[]} name - Ceci est le pointeur vers la chaine de caractères representant la question
 * @param {char[][]} responseList - Ceci est le pointeur des pointeurs, c'est le tableau des chaines de caractères representant les reponses
 * @param {int[]} responsesLenghtList - Ceci est le tableau contenant les tailles de toutes les reponses aux questions
 */
void initQuestionOther(QUESTION_SECOND *quest, char *name, char *responseList[3], int *responsesLenghtList)
{
    // partie qui gère le prompt
    int len = strlen(name);
    snprintf(quest->prompt, sizeof(quest->prompt), name);

    // partie qui gere les reponses aux  questions
    int i = 0;
    for (i = 0; i < QUESTIONS_RESPONSES_NUMBER; i++)
    {
        snprintf(quest->responses[i], sizeof(quest->responses[i]), responseList[i]);
    }

    // partie qui gere les points de karma
    quest->karmalist[0] = (int)1;
    quest->karmalist[1] = (int)0;
    quest->karmalist[2] = (int)-1;
}

/**
 * Cette fonction permet d'initialiser les questions qu'on devra utiliser plus tard
 * @param {QUESTION[]} quest - Ceci est le pointeur vers la tableau des questions
 * @param {char[]} name - Ceci est le pointeur vers la chaine de caractères representant la question
 * @param {char[][]} responseList - Ceci est le pointeur des pointeurs, c'est le tableau des chaines de caractères representant les reponses
 * @param {int[]} responsesLenghtList - Ceci est le tableau contenant les tailles de toutes les reponses aux questions
 */
void initQuestion(QUESTION *quest, char *name, char *responseList[3], int *responsesLenghtList)
{
    // partie qui gère le prompt
    int len = strlen(name);
    quest->prompt = malloc((len + 1) * sizeof(char));
    int i = 0;
    for (i = 0; i < len; i++)
    {
        quest->prompt[i] = name[i];
    }
    quest->prompt[i] = '\0';

    // partie qui gere les reponses aux questions
    quest->responses = malloc(3 * sizeof(char *));

    // printf("Ici ça marche encore \n");
    i = 0;
    for (i = 0; i < 3; i++)
    {
        char *strReceive = responseList[i];
        int resLength = responsesLenghtList[i];
        // printf("Taille %d ,",resLength);
        quest->responses[i] = malloc((resLength + 1) * sizeof(char));
        int k = 0;
        for (k = 0; k < resLength; k++)
        {
            quest->responses[i][k] = strReceive[k];
        }
        quest->responses[i][k] = '\0';
        // printf("%s\n",quest->responses[i]);
    }
    printf("Affiche au moins la premiere valeur: %s de taille %d\n", quest->responses[0], strlen(quest->responses[0]));

    // partie qui gere les points de karma
    quest->karmalist[0] = (int)1;
    quest->karmalist[1] = (int)0;
    quest->karmalist[2] = (int)-1;
}

/**
 * Cette fonction permet de liberer les questions qu'on a dejà utilisé
 * @param {QUESTION[]} quest - Ceci est le pointeur vers la tableau des questions
 */
void freeQuestions(QUESTION quests[])
{
    free(quests);
}

/**
 * Cette fonction permet de liberer les questions qu'on a dejà utilisé
 * @param {QUESTION[]} quest - Ceci est le pointeur vers la tableau des questions
 */
void freeQuestionsOther(QUESTION_SECOND quests[])
{
    free(quests);
}
/**
 * Fonction de test pour verifier toutes les valeurs internes sur un objet QUESTIONS
 * @param {QUESTION_SECOND} question - Juste la question en parametre...
 */
void questionTestOther(QUESTION_SECOND question)
{
    printf("\n");
    printf("\n");
    printf("Voici toutes les informations par rapport a une question et son objet\nNous avons la question en question '%s'\nSes differentes reponses:\n%s\n%s\n%s\nEt enfin ses valeurs en Karma(%d,%d,%d).", question.prompt, question.responses[0], question.responses[1], question.responses[2], question.karmalist[0], question.karmalist[1], question.karmalist[2]);
}

/**
 * Fonction de test pour verifier toutes les valeurs internes sur un objet QUESTIONS
 * @param {QUESTION} question - Juste la question en parametre...
 */
void questionTest(QUESTION question)
{
    printf("\n");
    printf("\n");
    printf("Voici toutes les informations par rapport a une question et son objet\nNous avons la question en question '%s'\nSes differentes reponses:\n%s\n%s\n%s\nEt enfin ses valeurs en Karma(%d,%d,%d).", question.prompt, question.responses[0], question.responses[1], question.responses[2], question.karmalist[0], question.karmalist[1], question.karmalist[2]);
}

/**
 * Cette fonction retourne toutes les questions du jeu
 * @param {int *} questionNumber - Ceci permet de recuperer le nombre de question
 * @return {QUESTION[]}
 */
QUESTION *getGamesQuestions(int *questionNumber)
{
    QUESTION *QuestionObjectList = malloc((QUESTIONS_NUMBER + 1) * sizeof(QUESTION));

    char *questionList[QUESTIONS_NUMBER] = {
        "Lors de votre balade matinale,il rencontre un jeune homme entrain de se faire arnaquer. Que faites-vous ?",
        "Juste après cela,vous décidez de l'approcher et vous constatez qu'il pourrait appartenir à la noblesse. Que faites-vous ?",
        "Après ce court échange avec le jeune garçon,il décide de faire le tour de la ville avec vous histoire de mieux la connaître. Où décidez-vous d'aller ?",
        "Après avoir apprécié la visite à __WHEREAME__,il vous invite à dîner dans sa modeste demeure. Une fois arrivés,vous êtes reçus par la gouvernante du jeune garçon qui vous amène à la salle à manger pendant que le jeune noble s'en va se changer. Étant seul avec la gouvernante vous décidez de:",
        "Après s'être changé le noble vint se mettre à table avec vous. Ainsi donc la servante après installation mit les couverts. Le noble s'adressant à vous vous demande :Quelles sont vos ambitions dans la vie? Que répondez-vous ?"};

    char *responseList[QUESTIONS_NUMBER][QUESTIONS_RESPONSES_NUMBER] = {
        {"Reponse A1: Bref...", "Reponse B1: Et puis.", "Reponse C1: Je suis fou"},
        {"Reponse A2", "Reponse B2", "Reponse C2"},
        {"Reponse A3", "Reponse B3", "Reponse C3"},
        {"Reponse A4", "Reponse B4", "Reponse C4"},
        {"Reponse A5", "Reponse B5", "Reponse C5"},
    };

    int i = 0;
    int j = 0;
    int tabResponsesLenght[QUESTIONS_RESPONSES_NUMBER] = {0};
    for (i = 0; i < QUESTIONS_NUMBER; i++)
    {
        j = 0;
        for (j = 0; j < QUESTIONS_RESPONSES_NUMBER; j++)
        {
            tabResponsesLenght[j] = strlen(responseList[i][j]);
            // printf("%s de taille %d ,", responseList[i][j], tabResponsesLenght[j]);
        }
        // printf("\n");
        initQuestion(&QuestionObjectList[i], questionList[i], responseList[i], tabResponsesLenght);
    }

    // i = 0;
    // for(i = 0; i < QUESTIONS_NUMBER; i ++){
    //     questionTest(QuestionObjectList[i]);
    // }
    // i = 0;
    // for (i = 0; i < QUESTIONS_NUMBER; i++)
    // {
    //     printf("Question %d : %s\n", i + 1, QuestionObjectList[i].prompt);
    // }

    *questionNumber = QUESTIONS_NUMBER;

    return QuestionObjectList;
}

/**
 * Cette fonction retourne toutes les questions du jeu
 * @param {int *} questionNumber - Ceci permet de recuperer le nombre de question
 * @return {QUESTION_SECOND[]}
 */
QUESTION_SECOND *getGamesQuestionsOther(int *questionNumber)
{
    QUESTION_SECOND *QuestionObjectList = malloc((QUESTIONS_NUMBER) * sizeof(QUESTION_SECOND));

    char *questionList[QUESTIONS_NUMBER] = {
        "Lors de votre balade matinale,il rencontre un jeune homme entrain de se faire arnaquer. Que faites-vous ?",
        "Juste apres cela,vous decidez de l'approcher et vous constatez qu'il pourrait appartenir a la noblesse. Que faites-vous ?",
        "Apres ce court echange avec le jeune garçon,il decide de faire le tour de la ville avec vous histoire de mieux la connaetre. Ou decidez-vous d'aller ?",
        "Apres avoir apprecie la visite au __WHEREAME__,il vous invite a diner dans sa modeste demeure. Une fois arrives,vous etes recus par la gouvernante du jeune garcon qui vous amene a la salle a manger pendant que le jeune noble s'en va se changer. Etant seul avec la gouvernante vous decidez de:",
        "Apres s'etre changa le noble vint se mettre a table avec vous. Ainsi donc la servante apras installation mit les couverts. Le noble s'adressant a vous vous demande : Quelles sont vos ambitions dans la vie ? Que rapondez-vous ?"};

    char *responseList[QUESTIONS_NUMBER][QUESTIONS_RESPONSES_NUMBER] = {
        {"Faire des signes pour qu'il comprenne que c'est une arnaque.", "Juste observer la scene.", "Se moquer de lui."},
        {"Le faire comprendre qu'il a ete arnaque.", "Discuter avec lui sur le produit qu'il a achete.", "Lui dire qu'il a fait une bonne affaire."},
        {"Centre ville", "La foire", "Sainte Eglise"},
        {"Entamer la conversation en la complimentant.", "Parler de la visite en ville", "Expliquer le comportement de son jeune maitre lors de la visite."},
        {"Parcourir le monde et decouvrir de nouveaux horizons.", "Profitez de l'instant present.", "Devenir un noble."},
    };

    int i = 0;
    int j = 0;
    int tabResponsesLenght[QUESTIONS_RESPONSES_NUMBER] = {0};
    for (i = 0; i < QUESTIONS_NUMBER; i++)
    {
        j = 0;
        for (j = 0; j < QUESTIONS_RESPONSES_NUMBER; j++)
        {
            tabResponsesLenght[j] = strlen(responseList[i][j]);
            // printf("%s de taille %d ,", responseList[i][j], tabResponsesLenght[j]);
        }
        // printf("\n");
        initQuestionOther(&QuestionObjectList[i], questionList[i], responseList[i], tabResponsesLenght);
    }

    // i = 0;
    // for(i = 0; i < QUESTIONS_NUMBER; i ++){
    //     questionTest(QuestionObjectList[i]);
    // }
    // i = 0;
    // for (i = 0; i < QUESTIONS_NUMBER; i++)
    // {
    //     printf("Question %d : %s\n", i + 1, QuestionObjectList[i].prompt);
    // }

    *questionNumber = QUESTIONS_NUMBER;

    return QuestionObjectList;
}