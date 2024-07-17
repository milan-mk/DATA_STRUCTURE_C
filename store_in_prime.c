#include <stdio.h>
#include <stdlib.h>

int A[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
int B[10] = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30};

int C[200];

int isprime(int key);

int main()
{
    int i, j, k, l, a = 0, b = 0, c;
    for (i = 0; i < 200; i++)
    {
        C[i] = 0;
    }
    k = 0;
    for (j = 0; j < 30; j++)
    {
        if (isprime(j))
        {
            if (b < 11)
            {
                C[j] = B[b++];
            }
        }
        else
        {
            if (a < 21)
            {
                C[j] = A[a++];
            }
        }
    }

    for (k = 0; k < 200; k++)
    {
        printf("%d , ", C[k]);
    }
    return 0;
}

int isprime(int key)
{
    int i, count = 0;
    for (i = 2; i < key; i++)
    {
        if (key % i == 0)
        {
            count++;
        }
    }
    if (count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
