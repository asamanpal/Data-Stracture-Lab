// Perform deletion operation on a single linked list for different cases (beginning, end, at a position).
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node *start = NULL;
    struct Node *new = NULL;
    struct Node *ptr = NULL;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        new = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data : ");
        scanf("%d", &data);
        new->data = data;
        new->next = NULL;
        if (start == NULL) {
            start = new;
        }
        else {
            ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = new;
        }
    }
    return start;   
}

void deleteAtBeginning(struct Node** start) {
    if (*start == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct Node* ptr = *start;
    *start = (*start)->next;
    free(ptr);
    printf("Node deleted from the beginning\n");
}

void deleteAtEnd(struct Node** start) {
    if (*start == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct Node* ptr = *start;
    if (ptr->next == NULL) {
        free(ptr);
        *start = NULL;
        printf("Node deleted from the end\n");
        return;
    }
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    printf("Node deleted from the end\n");
}

void deleteAtPosition(struct Node** start, int position) {
    if (*start == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *ptr = *start;
    if (position == 0){
        *start = ptr->next;
        free(ptr);
        printf("Node deleted at position %d\n", position);
        return;
    }  
    for (int i = 0; ptr != NULL && i < position - 1; i++) {
        ptr = ptr->next;
    }   
    if (ptr == NULL || ptr->next == NULL) {
        printf("Position %d does not exist in the list\n", position);
        return;
    }
    struct Node* nextNode = ptr->next->next;
    free(ptr->next);
    ptr->next = nextNode;
    printf("Node deleted at position %d\n", position);
}
void printList(struct Node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }       
    struct Node* ptr = start;
    printf("List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    head = createNode(0);
    printList(head); 
    deleteAtBeginning(&head); 
    printList(head);
    deleteAtEnd(&head); 
    printList(head);
    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);
    deleteAtPosition(&head, position);
    printList(head); 
    return 0;
}