#include <stdio.h>

struct node
{
    int info;
    struct node *link;
};

int main()
{
    struct node *start = NULL, *ptr = NULL, *new = NULL;
    int data, i, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        new->info = data;
        new->link = NULL;
        if (start == NULL)
        {
            start = new; // First node
        }
        else
        {
            ptr = start;
            while (ptr->link != NULL)
            {
                ptr = ptr->link; // Traverse to the end of the list
            }
            ptr->link = new; // Link the new node at the end
        }
    }
    for (ptr = start; ptr != NULL; ptr = ptr->link)
    {
        printf("%d ", ptr->info); // Print the data in each node
    }
    return 0;
}


