#include <stdio.h>
#include <stdlib.h>

// Définition de la structure de nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Création d'un nouveau nœud
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insertion dans une liste triée (ordre croissant)
void insertSorted(Node** head, int value) {
    Node* newNode = createNode(value);

    // Cas 1 : liste vide ou nouvel élément plus petit que la tête
    if (*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Cas 2 : parcourir la liste pour trouver la bonne position
    Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    // Insérer après current
    newNode->next = current->next;
    current->next = newNode;
}

// Affichage de la liste
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Programme principal pour tester
int main() {
    Node* head = NULL;

    insertSorted(&head, 30);
    insertSorted(&head, 10);
    insertSorted(&head, 20);
    insertSorted(&head, 40);
    insertSorted(&head, 25);

    printf("Liste triée :\n");
    printList(head);

    return 0;
}
