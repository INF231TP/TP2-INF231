#include <stdio.h>
#include <stdlib.h>

// Fonction pour afficher les éléments du tableau
void afficherListe(int liste[], int taille) {
    printf("Liste actuelle : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", liste[i]);
    }
    printf("\n");
}

int main() {
    // Initialisation d'un tableau de démonstration
    int liste[] = {10, 5, 10, 20, 5, 30, 10};
    int taille = sizeof(liste) / sizeof(liste[0]); // Calcule la taille actuelle du tableau

    // Affichage de la liste originale
    afficherListe(liste, taille);

    // Demande à l'utilisateur de saisir l'élément à supprimer
    int elementASupprimer;
    printf("Entrez l'élément à supprimer de la liste : ");
    scanf("%d", &elementASupprimer);

    // Boucle pour supprimer toutes les occurrences
    int nouvelleTaille = taille; // Initialise la nouvelle taille avec l'ancienne
    for (int i = 0; i < nouvelleTaille; ) {
        if (liste[i] == elementASupprimer) {
            // Si l'élément correspond, on décale les éléments suivants vers la gauche
            for (int j = i; j < nouvelleTaille - 1; j++) {
                liste[j] = liste[j + 1];
            }
            nouvelleTaille--; // Diminue la taille effective de la liste
            // On ne change pas 'i' car le nouvel élément à l'index 'i' doit être vérifié
        } else {
            i++; // Passe à l'élément suivant si ce n'est pas l'élément à supprimer
        }
    }

    // Affichage de la liste après suppression
    printf("Après suppression de toutes les occurrences de %d :\n", elementASupprimer);
    afficherListe(liste, nouvelleTaille);

    return 0;
}