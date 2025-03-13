#include <stdio.h>
#include "./utils/game.h"
#include "./utils/draw.h"

int main(int argc, char const *argv[])
{
    // fonction de lancement du jeu. Le jeu commence par ici
    Launch_Game();

    // Cette partie permet de gerer l'arret et le relancement du jeu si possible...
    Keep_Open_Game();
    // draw_end_script("Murel Ulrich", "L'histoire nous entraine dans le quotidien de Melaiid,fils du roi Thophild qui a ete assassine par un membre du conseil d'administration de son pere lors d'une reception et par la suite s'est reincarne dans le corps d'un enfant originaire d'un bidonville appele __USERNAME__(Vous) et s'est des lors fixe pour objectif de retrouver son statut social.");
    return 0;
}
