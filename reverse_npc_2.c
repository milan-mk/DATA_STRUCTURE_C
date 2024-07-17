#include <stdio.h>
#include <stdlib.h>

struct llink
{
    int data;
    struct llink *add;
};

struct llink *p;
int c = 0, n;

void insert();
void ddelete();
void display();

void main()
{
    p = NULL;

    while (1)
    {
        int ch;
        printf("enter your choice :\n1.insert\n2.delete\n3.display\n4.exit\n5.reverse\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            ddelete();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        case 5:
            reverse();
            break;
        }
    }
}

void insert()
{
    struct llink *k, *temp;
    int val;

    printf("enter your value : ");
    scanf("%d", &val);

    k = (struct llink *)malloc(sizeof(struct llink));

    k->data = val;
    k->add = NULL;

    if (p == NULL)
    {
        p = k;
    }
    else
    {
        temp = p;
        c++;

        while (temp->add != NULL)
        {
            temp = temp->add;
        }
        temp->add = k;
    }
}

void display()
{
    struct llink *temp;

    if (p == NULL)
    {
        printf("list is empty : ");
    }
    else
    {

        temp = p;
        while (temp->add != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->add;
        }
        printf("%d\n", temp->data);
    }
}

void ddelete()
{
}

void reverse()
{
    if (p == NULL)
    {
        printf("list is empty :");
    }

    else
    {
        struct llink *pre, *next, *cur;
        cur = p;
        pre = cur;

        cur = cur->add;
        pre->add = NULL;
        while (cur->add != NULL)
        {
            next = cur->add;
            cur->add = pre;
            pre = cur;
            cur = next;
        }
        cur->add = pre;
        p = cur;
    }
}
