#include <stdio.h>
#include <stdlib.h>
#define m 20
struct queue
{
    int data[m];
    int front, rear;
};

struct queue q;

void main()
{
    q.front = 0;
    q.rear = -1;
    int ch;

    while (1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.reverse\n5.exit\nenter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            reverse();
            break;

        case 5:
            exit(0);
        }
    }
}

void enqueue()
{
    if (q.rear >= m)
    {
        printf("queue is full : \n");
    }
    else
    {
        int n;
        printf("enter your value : \n");
        scanf("%d", &n);

        q.data[++q.rear] = n;
    }
}

void dequeue()
{
    if (q.front > q.rear)
    {
        printf("queue is empty : \n");
    }
    else
    {
        ++q.front;
    }
}

void display()
{
    int i;

    if (q.front > q.rear)
    {
        printf("queue is empty : \n");
    }

    else

    {
        int i;
        for (i = q.front; i <= q.rear; i++)
        {
            printf("%d\n", q.data[i]);
        }
    }
}

//---------------------------------------------------------------------

void reverse()
{
    int j, i, temp, start;
    printf("enter upto how much you want to reverse : ");
    scanf("%d", &j);
    if (j > q.rear)
    {
        printf("no. of elements are less than provided input :\n");
    }
    else
    {
        j--;
        for (i = 0; i < j; i++)
        {
            temp = q.data[i];
            q.data[i] = q.data[j];
            q.data[j] = temp;
            j--;
        }
    }
}
