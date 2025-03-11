#ifndef DRAW_H
#define DRAW_H

/**
 * Cette fonction permet de dessiner le haut du parchemin du jeu...
 */
void draw_header();

/**
 * Cette fonction permet de dessiner le bas du parchemin du jeu...
 */
void draw_footer();

/**
 * Cette fonction permet d'ecrire une ligne à l'ecran de l'utilisateur sur une marge de 70 charactères...
 * @param {char[]} str - Ceci est la chaine de 70 caracteres qui doit etre rediger en temps réel à l'ecran.
 * @param {int} taille - Ceci represente la taille de la chaine de caractères...
 */
void draw_row(char str[], int taille);

/**
 * Cette fonction permet de rediger l'histoire du jeu de depart...
*/
void draw_History();

#endif