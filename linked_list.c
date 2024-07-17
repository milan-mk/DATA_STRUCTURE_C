#include <stdio.h>
#include <stdlib.h>

struct llink
{
    int data;
    struct llink *add;
};

struct llink *p; // STRUCTURE POINTER VARIABLE

/*-------------------------------DEFINING PROTOTYPES------------------------------------------------------------*/
void insert();
void display();
void ddelete();
void d_first();
void d_last();
void d_any();

void main()
{
    p = NULL;
    while (1)
    {
        int n;
        printf("1.insert\n2.display\n3.delete\n4.exit\nenter your choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            ddelete();
            break;

        case 4:
            exit(0);
        }
    }
}

//---------------INSERT FUNCTION-----------------------------------------------------------------------------

void insert()
{
    int val;
    struct llink *k, *temp;
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

        while (temp->add != NULL)
        {
            temp = temp->add;
        }
        temp->add = k;
    }
}
//-----------------DISPLAY FUNCTION------------------------------------------------------------------------

void display()
{
    struct llink *temp;

    if (p == NULL)
    {
        printf("list is empty : \n");
    }

    else
    {
        temp = p;
        while (temp->add != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->add;
        }
        // temp->add=k;
        printf("%d\n", temp->data);
    }
}

//----------------DELETE FUNCTION----------------------------------------------------------------

void ddelete()
{
    int ch;

    if (p == NULL)
    {
        printf("list is empty : \n");
    }

    else
    {

        while (1)
        {
            printf("1. first\n2. last\n3. any \n4. display\n5. exit\nenter your choice which you want : ");
            scanf("%d", &ch);

            switch (ch)
            {

            case 1:
                d_first();
                break;

            case 2:
                d_last();
                break;

            case 3:
                d_any();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("enter correct option : \n");
            }
        }
    }
}

//------------------TO DELETE THE FIRST ELEMENT--------------------------------------------------------------------------------

void d_first()
{
    struct llink *temp;

    if (p == NULL)
    {
        printf("no data : \n");
    }

    else
    {
        temp = p;
        p = p->add;
        temp->add = NULL;

        free(temp);
    }
}

//------------------TO DELETE THE LAST ELEMENT ------------------------------------------------------------------------------

void d_last()
{
    struct llink *temp1, *temp2;

    if (p == NULL)
    {
        printf("no data : ");
    }

    else
    {
        temp1 = p;

        while (temp1->add != NULL)
        {
            temp2 = temp1;

            temp1 = temp1->add;
        }
        temp2->add = NULL;

        free(temp1);
    }
}

//--------------------TO DELETE ANY FUNCTION ----------------------------------------------------------------------------

void d_any()
{
    struct llink *t1, *t2;
    int v, c = 0;

    printf("enter value which you want to delete : ");
    scanf("%d", &v);

    t1 = p;

    // printf("%d",t1->data);
    while (t1->data != v)
    {
        t2 = t1;

        c++;
        t1 = t1->add;
    }

    if (c == 0)
    {
        p = p->add;
        t1->add = NULL;

        free(t1);
    }
    else
    {

        t2->add = NULL;
        t2->add = t1->add;
        t1->add = NULL;

        free(t1);
    }
}


