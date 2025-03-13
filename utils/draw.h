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
 * Cette fonction permet de mettre des lignes vides
 * @param {int} len Ceci represente le nombre de lignes vides a mettre...
*/
void draw_empty_row(int len);

/**
 * Cette fonction permet d'ecrire le coté gauche d'une ligne...
 */
void draw_left_row_side();

/**
 * Cette fonction permet d'ecrire le coté droite d'une ligne en prenant juste en compte le nommbre d'espace a prendre...
 * @param {int} numberLetterLeft Ceci est le nombre d'espacement à mettre
 */
void draw_right_row_side(int numberLetterLeft);

/**
 * Cette fonction permet de rediger l'histoire du jeu de depart...
*/
void draw_History(char *str);

/**
 * Cette fonction permet de mettre du teste en surligné
*/
void draw_highlight_test(char *str);

#endif