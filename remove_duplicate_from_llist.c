#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *add;
};

struct node *root;

struct node *insertitem(struct node *n, int val);
struct node *createnode(int val);
void insert();
void removedup();
void display(struct node *n);

int main()
{
    root = NULL;
    int ch;

    while (1)
    {
        printf("\nenter your choice :\n1.insert\n2.display\n3.remove duplicate\n4.exit\n->");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            display(root);
            break;

        case 3:
            removedup();
            break;

        case 4:
            exit(0);

        default:
            printf("enter proper choice :\n");
        }
    }
}

struct node *createnode(int val)
{
    struct node *k = (struct node *)malloc(sizeof(struct node));
    k->key = val;
    k->add = NULL;

    return k;
}

struct node *insertitem(struct node *n, int val)
{
    if (n == NULL)
    {
        return createnode(val);
    }
    else
    {
        n->add = insertitem(n->add, val);
    }

    return n;
}

void insert()
{
    int val;
    printf("enter your value ->");
    scanf("%d", &val);

    root = insertitem(root, val);
}

void display(struct node *n)
{
    if (n->add != NULL)
    {
        printf("%d ", n->key);
        display(n->add);
    }
    else
    {
        printf("%d ", n->key);
    }
}

void removedup()
{
    struct node *n, *dup, *k;

    n = root; /*storing the head element */
    dup = n;
    while (n->add != NULL) /*loop will iterate till end of the list */
    {
        k = n->add; /*storing the element next to the n pointer */

        while (k->add != NULL) /*inner loop to iterate till end in each iteration of outer loop */
        {
            if (n->key == k->key) /* if  duplicate element found if condition will execute*/
            {
                // dup = k->add;
                dup->add = k->add; /*dup pointer is just one behind teh k pointer therefore storing the next add of k in dup->add*/
                k->add = NULL;     /*making the next add of k null to free the node */
                free(k);           /* deleting the duplicate node */
                k = dup->add;      /* after deleting storing the next node in k*/
            }
            else
            {
                dup = k;    /* dup storing k*/
                k = k->add; /*k incremented one node*/
            }
        }
        if (n->key == k->key)   /* this if condition is to check the last element if same or not */
        {
            dup->add = NULL;    /*if last element match with any previous element the will free it*/
            free(k);
        }
        if (n->add != NULL) /* if the n->add is not null incrementing the n pointer for the outer loop*/
        {
            n = n->add;
            dup = n;    /* reseting dup and k pointer according to the n pointer*/
        }
    }
}