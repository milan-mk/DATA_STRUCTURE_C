#include<stdio.h>
#include<stdlib.h>

struct palin{
    int data[20];
    int sp;
};

struct palin p,q;

void push();
//void pop();
void display();
//void peep();
void check();


void main()
{
    int ch;
    p.sp=-1;
    q.sp=-1;

    while(1)
    {
        printf("enter your choice\n1. push\n2. pop\n3. display\n4. clearscreen\n5. peep\n6. check\n7.exit\n ");

        scanf("%d",&ch);

        switch(ch)
        {
            case 1:     //to enter values
            push();
            break;

            case 2:     //to delete last entered value
            pop();
            break;

            case 3:     //to display all the entered values
            display();
            break;

           /*case 4:     //to clear the screen
            clrscr();
            break;*/

            case 5:     //to display the last entered data
            peep();
            break;

            case 6:
                check();
                break;

            case 7:     //to exit the code
            exit(0);

            default:
            printf("Invalid  : ");

        }
    }
}

void push()
{
    int val;

    if(p.sp==19)
    {
        printf("stack is full : ");
    }
    else{
        printf("enter your value : ");
        scanf("%d",&val);

        p.data[++p.sp]=val;
    }

}

void display()
{   int i;
    if(p.sp==-1)
    {
        printf("stack is empty : ");
    }
    else{
            for(i=0;i<=p.sp;i++)
            {
                printf("%d\n",p.data[i]);
            }

    }
}

void check()
{
    if(p.sp==-1)
    {
        printf("stack is empty :  ");
    }
    else{ int c=0,i=0;
            while(q.sp>p.sp || q.sp!=p.sp)
            {
                q.data[++q.sp]=p.data[p.sp--];

                if(q.data[q.sp]==p.data[i++])
                {
                    continue;
                }
                else{
                    c++;
                    break;
                }
            }
            if(c==0)
            {
                printf("palindrome\n");
            }
            else{
                    printf("not palindrome\n");
            }
    }
}
void pop()
{

}
void peep()
{

}
