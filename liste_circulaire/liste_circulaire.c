#include <stdio.h>
#include <stdlib.h>

// Définition d’un nœud de la liste
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Pointeur vers le début et la fin de la liste
Node* head = NULL;
Node* tail = NULL;

// Création d’un nouveau nœud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d’allocation mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insertion en tête
void insertAtHead(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Insertion en tête: %d\n", data);
}

// Insertion en queue
void insertAtTail(int data) {
    Node* newNode = createNode(data);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("Insertion en queue: %d\n", data);
}

// Affichage de la liste de gauche à droite
void displayForward() {
    Node* temp = head;
    printf("Liste (gauche -> droite): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Affichage de la liste de droite à gauche
void displayBackward() {
    Node* temp = tail;
    printf("Liste (droite -> gauche): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Libération de la mémoire
void freeList() {
    Node* temp = head;
    while (temp != NULL) {
        Node* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
}

int main() {
    insertAtHead(10);
    insertAtHead(20);
    insertAtTail(30);
    insertAtTail(40);

    displayForward();
    displayBackward();

    freeList();
    return 0;
}
