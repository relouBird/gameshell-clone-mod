#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * Cette fonction renvoie zero (0) si la chaine est vide et change directement la chaine de caractères que vous le passiez en parametre
 * @param {char[]} str - c'est la chaine de caractères qu'on lira au clavier;
 * @returns {int}
 */
int readf(char *str);

/**
 * Cette fonction permet de diviser un chaine de caractères selon un motif...ABC
 * @param {char*} scripts Ceci est la chaine de characteres a diviser selon le concept
 * @param {int} lenScript Ceci est la taille de la chaine a diviser.
 * @param {int*} taille Ceci est un pointeur vers la taille du tableau contenant tout les differents mots obtenu par le motif...
 * @return {char**}
 */
char **split(char *scripts, int lenScript, int *taille);

/**
 * Cette fonction renvoie un tableau de chaine caractères contenant les differents differents phrases à rediger
 * @param {char**} tabStr Ceci est le tableau des differents mots à ajouter dans les phrases
 * @param {int} len Ceci est la taille du premier tableau passé en parametre
 * @return {char**}
 */
char **phrasesToDraw(char **tabStr, int len, int *numberSentences);

#endif