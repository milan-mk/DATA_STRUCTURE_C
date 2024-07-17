#include <stdio.h>
#include <stdlib.h>

struct parsing
{
    char data[20];
    int ch;
};

struct parsing p;

void main()
{
    char eq[20], i;
    p.ch = -1;

    printf("enter your equation : ");
    scanf("%s", eq);

    i = 0;
    while (eq[i] != '\0')
    {
        if (eq[i] == '(' || eq[i] == '[' || eq[i] == '{')
        {
            ppush(eq[i]);
        }
        else
        {
            if (eq[i] == ')' || eq[i] == ']' || eq[i] == '}')
            {
                if (p.data[p.ch] == '(' && eq[i] == ')')
                {
                    ppop();
                }
                else
                {
                    if (p.data[p.ch] == '{' && eq[i] == '}')
                    {
                        ppop();
                    }
                    else
                    {
                        if (p.data[p.ch] == '[' && eq[i] == ']')
                        {
                            ppop();
                        }
                    }
                }
            }
        }
        i++;
    }

    if (eq[i] == '\0' && p.ch == -1)
    {
        printf("%s equation is correct : ", eq);
    }
    else
    {
        printf("%s is wrong : ", eq);
    }
}

void ppush(char a)
{
    p.data[++p.ch] = a;
}

void ppop()
{
    if (p.ch == -1)
    {
        printf("empty :");
        exit(0);
    }
    else
    {
        p.ch--;
    }
}
