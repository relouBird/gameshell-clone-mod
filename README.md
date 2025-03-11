# gameshell-clone-mod
Ceci est un sumple pour savoir etape par etape comment utiliser mon code jeu.
Il y a quelques fichiers pas beaucoup le fichiers de lancement est main.c c'est la fonction principale elle permet de jouer aux jeux videos
il y a les differentes bibliotheques au meme nom que leur fichiers contenant toutes les fonctions utiles au lancement du jeu...
Il y a le fonction secondaire selon moi ou on dirait la fonction de test où generalement j'effectue tout les tests exhaustifs possibles pour le jeu et les fonctions à utiliser de manières separer.

# Voici les differentes commandes
# Commande pour compiler le code source
gcc main.c utils/*.c -o game.exe

# Commande pour compiler le code source du test
gcc test.c -o test.exe

# Commande pour après lancer le programme principal...
.\game.exe

# Commande pour après lancer le test...
.\test.exe