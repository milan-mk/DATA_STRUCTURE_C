#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n,t;

    printf("enter no of elements : ");
    scanf("%d",&n);

    printf("enter target sum :");
    scanf("%d",&t);


    quadra(n,t);
}


void quadra(int n,int t)
{
    int ele[50][50],arr[50],i,j,k,l,c=0,m,p=0,a;

    printf("enter your elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<=n-3;i++)
    {
        for(j=i+1;j<=n-2;j++)
        {
            for(k=j+1;k<=n-1;k++)
            {
                for(l=k+1;l<=n;l++)
                {
                    if(t==arr[i]+arr[j]+arr[k]+arr[l])
                    {
                        c++;
                        ele[p][0]=arr[i];
                        ele[p][1]=arr[j];
                        ele[p][2]=arr[k];
                        ele[p][3]=arr[l];
                        p++;
                    }
                }
            }
        }
    }



    if(c==0)
    {
        printf("empty list : ");
    }
    else{
        for(m=0;m<p;m++)
        {
            for(a=0;a<4;a++)
            {
                printf("%d ",ele[m][a]);
            }
            printf("\n");
        }
    }

}
