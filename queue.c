#include<stdio.h>
#include<stdlib.h>


struct queue{
    int data[10];
    int front,rear;
};

struct queue q;

void main()
{
    int m;
    q.front=0;
    q.rear=-1;


    while(1)
    {
        printf("1. equeue\n2. dqueue\n3. display\n4. exit\nENTER YOUR CHOICE :");
        scanf("%d",&m);

        switch(m)
        {

        case 1:
            equeue();
            break;

        case 2:
            dqueue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);


        }
    }
}

//----------------------------insert function in queue-------------------------------------------------------------------

void equeue()
{
    int x;

    if(q.rear>=9)
    {
        printf("QUEUE IS FULL : \n");
    }

    else
    {
        printf("ENTER YOUR VALUE : ");
        scanf("%d",&x);

        q.data[++q.rear]=x;
    }
}


//-----------------------------DELETE FUNCTION--[FOLLOWS FIRST IN FIRST OUT]-------------------------------------------------------------------------

void dqueue()
{
    if(q.front>q.rear)
    {
        printf("QUEUE IS EMPTY : ");
    }

    else
    {
        q.front++;
    }
}

//---------------------------DISPLAY FUNCTION---------------------------------------------------------------

void display()
{
    int i;

    if(q.front>q.rear || q.rear==0)
    {
        printf("queue is empty : ");
    }

    else
    {
        for(i=q.front;i<=q.rear;i++)
        {
            printf("\n%d\n",q.data[i]);
        }
    }
}
