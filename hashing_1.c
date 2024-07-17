#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,k,n,key,ch;

    printf("enter key mod element :");
    scanf("%d",&key);
    int data[key];

    printf("enter how many element you want to insert :");
    scanf("%d",&n);

    for(i=0;i<key;i++)
    {
        data[i]=NULL;
    }

    for(i=0;i<n;i++)
    {
        printf("enter your data :");
        scanf("%d",&ch);

        k=ch%key;

        while(1)
        {
            if(data[k]==NULL)
            {
                data[k]=ch;
                break;
            }
            else{
                if(k>=key)
                {
                    break;
                }
            else
            {
                k++;
            }
            }
        }

    }

    for(i=0;i<key;i++)
    {
        printf("%d\n",data[i]);
    }
}
