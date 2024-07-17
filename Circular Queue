
#include <stdio.h>
#include <stdlib.h>
#define n 10
// extern int c = 0;

struct node
{
    int data[n];
    int front, rear;
};

struct node p;

void enqueue(int val);
void display();
void dequeue();

void enqueue(int val)
{   p.rear=(p.rear + 1) % n ;
    if (p.rear == p.front)
    {
        printf("queue is full :\n");
        if(p.rear==0)
        {
            p.rear=n-1;
        }
        else{
            p.rear=p.rear-1;
        }

    }
        else
        {
            
            p.data[p.rear] = val;
        }

}

// #########################################################################################

void dequeue()
{

    if (p.front== p.rear)
    {
        
        printf("queue is empty :");
    }
    else
    {
        p.front = (p.front + 1) % n;
        printf("element dequeued -> %d\n",p.data[p.front]);
    }
}

// #########################################################################################

void display()
{


    if (p.front == p.rear)
    {
        printf("queue is empty :");
    }
    else
    {
        if (p.rear >= p.front)
        {
            for (int i = p.front+1; i <= p.rear; i++)
            {
                printf("%d  ", p.data[i]);
            }
        }
        else
        {
            for (int i = p.front; i < n; i++)
            {
                printf("%d  ", p.data[i]);
            }
            for (int j = 0; j <=p.rear; j++)
            {
                printf("%d  ", p.data[j]);
            }
        }
    }
}

void main()
{
    int m, key;
    p.front = 0;
    p.rear = 0;

    while (1)
    {
        printf("\n1. equeue\n2. dqueue\n3. display\n4. exit\nENTER YOUR CHOICE :");
        scanf("%d", &m);

        switch (m)
        {

        case 1:
            printf("enter your data :");
            scanf("%d", &key);
            enqueue(key);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
        }
    }
}
