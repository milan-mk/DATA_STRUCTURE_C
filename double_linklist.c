#include <stdio.h>
#include <stdlib.h>

struct dl // constructing structure for double link list
{
    int data;
    struct dl *p_add, *n_add; //  p_add = store previous add & n_add = store next add
};

struct dl *p;

// defining prototype

void insert();
void delete();
void display();
void reverse();
void sort();

void main()
{
    p = NULL;

    while (1)
    {
        int ch;
        printf("enter your choice:\n1.insert\n2.display\n3.delete\n4.reverse\n5.sort\n6.exit\n->");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert(); // insert function to enter value
            break;

        case 2:
            display(); // display function to display the inserted value
            break;

        case 3:
            delete (); // delete function to delete any value
            break;

        case 4:
            reverse(); // reverse function to print list in reverse order {it will not reverse the list}
            break;

        case 5:
            sort();
            break;

        case 6:
            exit(0); // to exit the loop

        default:
            printf("enter proper choice :");
        }
    }
}

//-----------------------------------------------------------------------------------

void insert()
{
    struct dl *k, *pre, *next; // defining structure pointer variable
    int val;

    printf("enter your value :");
    scanf("%d", &val);

    k = (struct dl *)malloc(sizeof(struct dl)); // allocating memeory dynamically

    k->data = val;
    k->n_add = NULL; // making previous add null and next add null
    k->p_add = NULL;

    if (p == NULL)
    {
        p = k;
    }
    else
    {
        next = p;
        while (next->n_add != NULL) // loop till last element entered
        {
            pre = next;
            next = next->n_add;
        }
        k->p_add = next;   // storing the current add in the next element
        next->p_add = pre; // storing previous add in the current element
        next->n_add = k;
    }
}

//-----------------------------------------------------------------------------------------------------

void display()
{
    struct dl *temp;
    if (p == NULL)
    {
        printf("list is empty : \n");
    }
    else
    {
        temp = p;
        while (temp->n_add != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->n_add;
        }
        printf("%d\n", temp->data);
    }
}

void delete()
{
    struct dl *pre, *cur,*temp;
    if (p == NULL)
    {
        printf("list is empty : ");
    }
    else
    {
        int n;
        printf("enter which you want to delete :\n->");
        scanf("%d", &n);

        cur = p;
        
        if (cur->data == n) // to delete the first element
        {
            p = cur->n_add;
            temp=p;
            temp->p_add=NULL;
            cur->n_add = NULL;
            
            free(cur); // making the deleted element free
        }
        else
        {
            while (cur->data != n) // loop till we get the data user want to delete
            {
                pre = cur;
                cur = cur->n_add;
                if (cur->n_add == NULL) // if data not present in list then loop breaks after last element
                {
                    break;
                }
            }

            if (cur->data == n)
            {
                pre->n_add = cur->n_add;
                cur->n_add = NULL;
                free(cur);
            }
            else
            {
                printf("data is not present in list :\n");
            }
        }
    }
}

void reverse() // to print the list in reverse order { not reversing the list permanently }
{
    struct dl *temp; // temperorary structure pointer

    if (p == NULL)
    {
        printf("list is empty :");
    }
    else
    {
        temp = p;
        while (temp->n_add != NULL) // loop till last element
        {
            temp = temp->n_add;
        }

        while (temp->p_add != NULL) // iterating with previous add in reverse order and printing the data
        {
            printf("%d\n", temp->data);
            temp = temp->p_add;
            if (temp == p) // loop will break in reaching the head node
            {
                break;
            }
        }
        printf("%d\n", temp->data);
    }
}

void sort()
{
    //struct dl *pivot, *next, *pre;
     truct dl *t1, *t2, *t3;
     int t4;
    //int temp;

    if (p == NULL)
    {
        printf("list is empty :");
    }
    /*else
    {
        pre = p;
        pivot = pre;
        next = pre->n_add;

        while (pivot->n_add != NULL)
        {
            if (pivot->data <= next->data)
            {
                next = next->n_add;
            }

            else
            {
                if (pivot->data > next->data)
                {
                    temp = pivot->data;
                    pivot->data = next->data;
                    next->data = temp;
                }

                if (next->n_add == NULL)
                {
                    if (pivot->data > next->data)
                    {
                        temp = pivot->data;
                        pivot->data = next->data;
                        next->data = temp;
                    }
                    pivot = pivot->n_add;
                    next = pivot;
                }
            }
        }
    }*/

    
    else
    {
        t1 = p;
        t2 = t1;

        t1 = t1->n_add;
        t3 = t1;

        while (t2->n_add != NULL)
        {
            if (t2->data <= t3->data)
            {
                t3 = t3->n_add;
            }
            else
            {
                if (t2->data > t3->data)
                {
                    t4 = t3->data;
                    t3->data = t2->data;
                    t2->data = t4;
                }
            }

            if (t3->n_add == NULL)
            {
                if (t2->data > t3->data)
                {
                    t4 = t3->data;
                    t3->data = t2->data;
                    t2->data = t4;
                }
                t2 = t2->n_add;
                t3 = t2;
            }
        }
    }
}
