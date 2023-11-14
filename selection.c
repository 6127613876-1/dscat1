#include <stdio.h>
#define n 5
void main()
{
    int i,j,min,arr[5];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if (arr[j]<arr[min])
            {
                min=j;
            }
            
        }
        if (min!=i)
        {
           int temp = arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}