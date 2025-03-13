#include <stdio.h>

typedef enum KARMA_POINT
{
    PLUS = 1,
    NEUTRAL = 0,
    MINUS = -1,

} KARMA_POINT;

#define SCRIPTS_SCENARIO "Sous-domaines illimites Compte FTP illimite Migrations de sites Web gratuites Comptes de messagerie illimites Profil d'entreprise Google gratuit Installation WordPress en 1 clic Garantie de remboursement de 10 jours Vous pouvez mettre a jour les informations de connexion de votre compte a partir de votre tableau de bord Merci pour votre achat, n'hesitez pas a nous contacter si vous avez besoin d'aide"

#define KARMALIST {PLUS, NEUTRAL, MINUS}

typedef struct QUESTION
{
    signed char *prompt;
    signed char **responses;
    KARMA_POINT karmaTab[];
} QUESTION;

char *getScriptScenario()
{
    return SCRIPTS_SCENARIO;
}

