# get_next_line

`get_next_line` is a project from 42 School that consists of writing a function capable of reading a line from a file descriptor, regardless of its length.  
The main goal is to understand dynamic memory management, buffers, and file reading in C.

## Objectives 🎯

- Read a line from a file, even if it's very long
- Handle newlines and end-of-file correctly
- Master partial reads using `read()`
- Handle multiple file descriptors in parallel (bonus)

## Functions 🧠

- `get_next_line(int fd)` : returns the next line from a file descriptor, including the newline character (`\n`) if present.

## Files 📁

- `get_next_line.c` — main logic
- `get_next_line_utils.c` — utility functions
- `get_next_line.h` — header file

# get_next_line - (French version)

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
