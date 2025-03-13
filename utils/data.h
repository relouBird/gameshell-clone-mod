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

typedef struct QUESTION_SECOND
{
    char prompt[920];
    char responses[3][256];
    int karmalist[3];
} QUESTION_SECOND;

/**
 * Cette fonction retourne le script du scenario
 */
char *getScriptScenario(char *username);


/**
 * Cette fonction permet d'initialiser les questions qu'on devra utiliser plus tard
 * @param {QUESTION[]} quest - Ceci est le pointeur vers la tableau des questions
 * @param {char[]} name - Ceci est le pointeur vers la chaine de caractères representant la question
 * @param {char[][]} responseList - Ceci est le pointeur des pointeurs, c'est le tableau des chaines de caractères representant les reponses
 * @param {int[]} responsesLenghtList - Ceci est le tableau contenant les tailles de toutes les reponses aux questions
 */
void initQuestion(QUESTION *quest, char *name, char *responseList[3], int *responsesLenghtList);

/**
 * Cette fonction permet d'initialiser les questions qu'on devra utiliser plus tard
 * @param {QUESTION[]} quest - Ceci est le pointeur vers la tableau des questions
 * @param {char[]} name - Ceci est le pointeur vers la chaine de caractères representant la question
 * @param {char[][]} responseList - Ceci est le pointeur des pointeurs, c'est le tableau des chaines de caractères representant les reponses
 * @param {int[]} responsesLenghtList - Ceci est le tableau contenant les tailles de toutes les reponses aux questions
 */
void initQuestionOther(QUESTION_SECOND *quest, char *name, char *responseList[3], int *responsesLenghtList);


/**
 * Cette fonction permet de liberer les questions qu'on a dejà utilisé
 * @param {QUESTION[]} quest - Ceci est le pointeur vers la tableau des questions
 */
void freeQuestions(QUESTION quest[]);

/**
 * Cette fonction permet de liberer les questions qu'on a dejà utilisé
 * @param {QUESTION_SECOND[]} quest - Ceci est le pointeur vers la tableau des questions
 */
void freeQuestionsOther(QUESTION_SECOND quests[]);

/**
 * Fonction de test pour verifier toutes les valeurs internes sur un objet QUESTIONS
 * @param {QUESTION} question - Juste la question en parametre...
 */
void questionTest(QUESTION question);

/**
 * Fonction de test pour verifier toutes les valeurs internes sur un objet QUESTIONS
 * @param {QUESTION_SECOND} question - Juste la question en parametre...
 */
void questionTestOther(QUESTION_SECOND question);

/**
 * Cette fonction retourne toutes les questions du jeu
 * @param {int *} questionNumber - Ceci permet de recuperer le nombre de question
 * @return {QUESTION[]}
 */
QUESTION *getGamesQuestions(int *questionNumber);

/**
 * Cette fonction retourne toutes les questions du jeu
 * @param {int *} questionNumber - Ceci permet de recuperer le nombre de question
 * @return {QUESTION_SECOND[]}
 */
QUESTION_SECOND *getGamesQuestionsOther(int *questionNumber);

/**
 * Cette fonction permet de recuperer toutes les fins alternatives
 */
char **getEnding();

#endif