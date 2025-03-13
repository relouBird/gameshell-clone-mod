#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "draw.h"
#include "functions.h"

typedef enum Boolean
{
    True = 1,
    False = 0
} Boolean;

#define BLOC_LENGTH 70

/**
 * Cette fonction permet de lancer le jeu dans son ensemble
*/
void Launch_Game(){
    // cette partie dessine le haut du rouleau du jeu
    draw_header();

    draw_left_row_side();

    // Partie qui gère l'entrée du nom de ce dernier...
    char *prompt = "Veuillez Entrer votre Pseudo : ";
    signed char name[64] = "";
    printf("%s", prompt);
    readfs(name);
    int numberLetterLeft = (int)BLOC_LENGTH - (int)strlen(prompt) - (int)strlen(name);
    draw_right_row_side(numberLetterLeft);

    draw_empty_row(1);
    draw_History();

    // // cette partie dessine le haut du rouleau du jeu
    // draw_footer();
}

/**
 * Cette fonction permet de relancer le jeu si possible...
*/
void Reload_New_Game (){

}

void Keep_Open_Game()
{
    draw_highlight_test("Appuyer sur la touche Q pour (Quitter) ou sur la touche R pour (Relancer une partie)");
    Boolean GameIsLaunched = True;
    while (GameIsLaunched)
    {
        if(GetAsyncKeyState('Q')){
            GameIsLaunched = False;
        };
        if(GetAsyncKeyState('R')){
            Reload_New_Game();
        };
        Sleep(200);
    }
}