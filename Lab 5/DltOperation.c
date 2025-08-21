// Perform deletion operation on a single linked list for different cases (beginning, end, at a position).
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted from the beginning\n");
}
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }   
struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("Node deleted from the end\n");
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from the end\n");
}
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        printf("Node deleted at position %d\n", position);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position %d does not exist in the list\n", position);
        return;
    }
    struct Node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
    printf("Node deleted at position %d\n", position);
}
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }   
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Initial ");
    printList(head);
    deleteAtBeginning(&head);
    printList(head);
    deleteAtEnd(&head);
    printList(head);
    deleteAtPosition(&head, 1);
    printList(head);
    deleteAtPosition(&head, 0);
    printList(head);
    deleteAtPosition(&head, 5);
    printList(head);

    // Free remaining nodes
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
