#include <stdio.h>
#include <stdlib.h>
#define mod 10

// hashing using chaining

struct node
{
    int data;
    struct node *chain;
};
struct node *root[mod];

void display();

void main()
{
    for (int i = 0; i < mod; i++)
    {
        root[i] = NULL;
    }

    int val, ch, k;
    for (int i = 0; i < mod; i++)
    {
        printf("enter your data ->");
        scanf("%d", &val);
        struct node *n;
        n = (struct node *)malloc(sizeof(struct node));
        n->data = val;
        n->chain = NULL;

        k = val % mod;

        if (root[k] == NULL)
        {
            root[k] = n;
        }
        else
        {
            struct node *a;
            a = root[k];
            while (a->chain != NULL)
            {
                a = a->chain;
            }
            a->chain = n;
        }
    }

    struct node *j;

    for (int i = 0; i < mod; i++)
    {
        if (root[i] == NULL)
        {
            printf("0 ,");
        }
        else
        {

            j = root[i];
            while (j->chain != NULL)
            {
                printf("%d ,", j->data);
                j = j->chain;
            }
            printf("%d ,", j->data);
        }
    }
}