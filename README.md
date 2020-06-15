# Affichage dans un canvas de l'évolution d'une fourmi de Langton.

Cet exemple montre comment calculer une image depuis le code WASM, et l'afficher dans la page HTML en utilisant la balise `canvas`.
L'environnement de la fourmi sera représenté par une image, dont chaque pixel représente une "case" blanche ou noire (la fourmi elle même ne sera pas représentée dans l'image).

## Instructions
 - Pour changer le nombre de mouvements : voir variable `nbMoves` dans `main.js`. (par défaut 10 000)
 - Pour changer la direction de base de la fourmi : voir variable `direction` dans `main.c`. (par défaut 'West')

## Auteurs
 - Eliot LAMBOROT p1507702 