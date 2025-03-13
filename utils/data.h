#ifndef DATA_H
#define DATA_H

typedef enum KARMA_POINT
{
    PLUS = 1,
    NEUTRAL = 0,
    MINUS = -1,

} KARMA_POINT;

typedef struct QUESTION
{
    char *prompt;
    char *responses[3];
    KARMA_POINT karmalist[3];
} QUESTION;

/**
 * Cette fonction retourne le script du scenario
 */
char *getScriptScenario(char *username);

/**
 * Cette fonction retourne toutes les questions du jeu
 * @return {QUESTION}
 */
QUESTION *getGamesQuestions();

#endif