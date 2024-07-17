#include<stdio.h>
#include<stdlib.h>

void main() /*--------------------------binary search---------------------*/
{
    int arr[1000],j,n,i,l,key;

    printf("enter length of the array : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("enter your key element : ");
    scanf("%d",&key);

    l=n/2;


     while (l <= n) {
        int j = l + (n - l) / 2;

        // Check if key is present at mid
        if (arr[j] == key)
           {
               printf(" key value is present at index no : %d ",j);
           }
        // If key greater, ignore left half
        if (arr[j] < key)
            {l = j + 1;
            }
        // If key is smaller, ignore right half
        else{
            n = j - 1;
        }
    }


}
