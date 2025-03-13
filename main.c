#include <stdio.h>
#include "./utils/game.h"

int main(int argc, char const *argv[])
{
    // fonction de lancement du jeu. Le jeu commence par ici
    Launch_Game();

    // Cette partie permet de gerer l'arret et le relancement du jeu si possible...
    Keep_Open_Game();
    return 0;
}
