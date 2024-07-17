#include<stdio.h>
#include<stdlib.h>

void main()
{
    int arr[5];
    int i, j, k;

    printf("enter your input :");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 5; i++)
    {
        if (i != 4)
        {
            j = i + 1;
        }
        /*else{
            j=i+1;
        }*/
        while (1)
        {
            if (j == 5)
            {
                j = 0;
            }
            if (arr[i] < arr[j])
            {
                printf("%d ", arr[j]);
                break;
            }
            else
            {
                if (arr[i] == arr[j])
                {
                    printf("-1 ");
                    break;
                }
            }
            j++;
        }
    }
}