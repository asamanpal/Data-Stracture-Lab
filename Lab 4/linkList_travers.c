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
            start = new; 
        }
        else
        {
            ptr = start;
            while (ptr->link != NULL)
            {
                ptr = ptr->link; 
            }
            ptr->link = new; 
        }
    }
    for (ptr = start; ptr != NULL; ptr = ptr->link)
    {
        printf("%d ", ptr->info); 
    }
    return 0;
}


