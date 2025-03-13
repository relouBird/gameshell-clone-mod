#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "draw.h"
#include "functions.h"
#include "data.h"

#define BLOC_LENGTH 70
#define QUESTIONS_RESPONSES_NUMBER 3

/**
 * Cette fonction permet de gerer le fonctionnement d'une question
 * @param {int} questionNumber - Id de la question
 * @param {QUESTION_SECOND} quest - objet contenant les informations par rapport a la questiokn
 */
void PlayWithQuestion(int questionNumber, QUESTION_SECOND quest, int *totalKarmaPoint, char location[])
{

    char choiceLetters[3][3] = {"A", "B", "C"};

    // transforme d'abord le numero de la question en chaine de caractères
    char strQuestionNumber[10];
    snprintf(strQuestionNumber, sizeof(strQuestionNumber), "%d", questionNumber);
    // printf("%s \n", strQuestionNumber);
    char strQuestion[920] = "Question ";
    strcat(strQuestion, strQuestionNumber);
    strcat(strQuestion, " : ");
    if (questionNumber == 4)
    {
        // printf("%s\n\n", location);
        strcat(strQuestion, replaceLocation(quest.prompt, location, strlen(quest.prompt)));
    }
    else
    {
        strcat(strQuestion, quest.prompt);
    }

    // printf("%s \n", strQuestion);
    draw_Question_Or_Other(strQuestion, False);

    int i = 0;
    for (i = 0; i < QUESTIONS_RESPONSES_NUMBER; i++)
    {
        char chip[256] = "\t";
        strcat(chip, choiceLetters[i]);
        strcat(chip, ") ");
        // strcat(chip, choiceLetters[i]);
        strcat(chip, quest.responses[i]);
        draw_Question_Or_Other(chip, True);
    }

    Boolean GameIsWaitingResponse = True;

    while (GameIsWaitingResponse)
    {
        char answer = getch();
        switch (answer)
        {
        case 'A':
        case 'a':
            if (questionNumber == 3)
            {
                strcat(location, quest.responses[0]);
            }
            else
            {
                *totalKarmaPoint += quest.karmalist[0];
            }
            GameIsWaitingResponse = False;
            break;

        case 'B':
        case 'b':
            if (questionNumber == 3)
            {
                strcat(location, quest.responses[1]);
            }
            else
            {
                *totalKarmaPoint += quest.karmalist[1];
            }
            GameIsWaitingResponse = False;
            break;

        case 'C':
        case 'c':
            if (questionNumber == 3)
            {
                strcat(location, quest.responses[2]);
            }
            else
            {
                *totalKarmaPoint += quest.karmalist[2];
            }
            GameIsWaitingResponse = False;
            break;

        default:
            break;
        }
        Sleep(200);
    }
}

/**
 * Cette fonction permet de lancer le jeu dans son ensemble
 */
void Launch_Game()
{

    int TOTAL_KARMA_POINT = 0;
    char location[64] = "";
    char finStr[3][24] = {"FIN 1", "FIN 2", "FIN 3"};

    // cette partie dessine le haut du rouleau du jeu
    draw_header();

    draw_left_row_side();

    // Partie qui gère l'entrée du nom de ce dernier...
    char *prompt = "Veuillez Entrer votre Pseudo : ";
    int lenQuestions = 0;
    signed char name[64] = "";

    printf("%s", prompt);
    readfs(name);

    int numberLetterLeft = (int)BLOC_LENGTH - (int)strlen(prompt) - (int)strlen(name);
    draw_right_row_side(numberLetterLeft);

    draw_empty_row(1);
    draw_History(name, 2);

    QUESTION_SECOND *QuestionsList = getGamesQuestionsOther(&lenQuestions);

    int i = 0;
    for (i = 0; i < lenQuestions; i++)
    {
        PlayWithQuestion(i + 1, QuestionsList[i], &TOTAL_KARMA_POINT, location);
    }

    freeQuestionsOther(QuestionsList);

    char strPointKarma[10] = "";
    char MessageToView[64] = "Vous avez au total un karma de ";
    snprintf(strPointKarma, sizeof(strPointKarma), "%d", TOTAL_KARMA_POINT);
    strcat(MessageToView, strPointKarma);
    draw_Question_Or_Other(MessageToView, False);

    draw_footer();

    printf("\n\n");


}

/**
 * Cette fonction permet de relancer le jeu si possible...
 */
void Reload_New_Game()
{
    Launch_Game();
}

/**
 * Cette fonction permet de garder le jeu ouvert...
 */
void Keep_Open_Game()
{
    draw_highlight_test("Appuyer sur la touche Q pour (Quitter) ou sur la touche R pour (Relancer une partie)  \n");
    Boolean GameIsLaunched = True;

    while (GameIsLaunched)
    {
        char answer = getch();
        switch (answer)
        {
        case 'Q':
        case 'q':
            GameIsLaunched = False;
            break;

        case 'R':
        case 'r':
            GameIsLaunched = False;
            break;

        default:
            break;
        }
        Sleep(200);
    }
}
