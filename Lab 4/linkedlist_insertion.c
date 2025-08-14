// In the above linked list, do the following operations:
//          3.1 insertion at beginning 
//          3.2 insertion after a particular node
//          3.3 insertion at end




#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};


void printList(struct node *start) {
    struct node *ptr = start;
    printf("Linked list: ");
    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}


struct node* insertAtBeginning(struct node *start, int data) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->info = data;
    new->link = start;
    return new;
}


void insertAfterNode(struct node *start, int key, int data) {
    struct node *ptr = start;
    while (ptr != NULL && ptr->info != key) {
        ptr = ptr->link;
    }
    if (ptr != NULL) {
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->info = data;
        new->link = ptr->link;
        ptr->link = new;
    } else {
        printf("Node with value %d not found.\n", key);
    }
}


struct node* insertAtEnd(struct node *start, int data) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->info = data;
    new->link = NULL;
    if (start == NULL) {
        return new;
    }
    struct node *ptr = start;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = new;
    return start;
}

int main() {
    struct node *start = NULL;
    int n, data, key;

    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        start = insertAtEnd(start, data);
    }
    printList(start);

    
    printf("Enter data to insert at beginning: ");
    scanf("%d", &data);
    start = insertAtBeginning(start, data);
    printList(start);

    
    printf("Enter node value after which to insert: ");
    scanf("%d", &key);
    printf("Enter data to insert after %d: ", key);
    scanf("%d", &data);
    insertAfterNode(start, key, data);
    printList(start);

    
    printf("Enter data to insert at end: ");
    scanf("%d", &data);
    start = insertAtEnd(start, data);
    printList(start);

    return 0;
}