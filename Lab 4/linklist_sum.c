// In the above linked list, find sum of its contents and find the average of it.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

int main()
{
    struct node *start = NULL, *ptr = NULL, *new = NULL;
    int data, i, n;
    int sum = 0;
    float avg = 0.0;

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
                ptr = ptr->link; 
            }
            ptr->link = new; // Link the new node at the end
        }
    }

    printf("Linked list contents: ");
    for (ptr = start; ptr != NULL; ptr = ptr->link)
    {
        printf("%d ", ptr->info); // Print the data in each node
        sum += ptr->info;         // Add to sum
    }

    if (n > 0)
        avg = (float)sum / n;

    printf("\nSum = %d\n", sum);
    printf("Average = %.2f\n", avg);
   
    return 0;
}