# get_next_line

`get_next_line` est un projet de l’école 42 qui consiste à écrire une fonction capable de lire une ligne depuis un descripteur de fichier, peu importe sa taille.  
L’objectif principal est de comprendre la gestion de la mémoire dynamique, les buffers, et la lecture de fichiers en C.

## Objectifs 🎯

- Lire une ligne depuis un fichier, même si elle est très longue
- Gérer correctement les retours à la ligne et les fins de fichier
- Maîtriser les lectures partielles avec `read()`
- Gérer plusieurs descripteurs de fichiers en parallèle (bonus)

## Fonctions 🧠

- `get_next_line(int fd)` : renvoie la ligne suivante d’un fichier, incluant le retour à la ligne (`\n`) si présent.

## Fichiers 📁

- `get_next_line.c` : logique principale
- `get_next_line_utils.c` : fonctions utilitaires
- `get_next_line.h` : fichier d'en-tête
