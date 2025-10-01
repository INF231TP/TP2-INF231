Liste Doublement Chaînée en C

Ce projet implémente une **liste doublement chaînée** en langage C. Il permet d'ajouter des éléments en tête ou en queue de la liste, d'afficher les éléments dans les deux sens, et de libérer correctement la mémoire allouée.
- insertin en tete (`insertAtHead`)
- insertion en queue (`insertAtTail`)
- Affichage de la liste de gauche à droite
- Affichage de la liste de droite à gauche
- Libération de la mémoire (`freeList`)


Compilation et exécution

Compilation:

Utilisez `gcc` pour compiler :

```bash
gcc main.c -o liste

Executer:

./liste

Exemple de sorti de code:

Insertion en tête: 10
Insertion en tête: 20
Insertion en queue: 30
Insertion en queue: 40
Liste (gauche -> droite): 20 10 30 40 
Liste (droite -> gauche): 40 30 10 20 

