#include <stdio.h>
#define n 5
void main()
{
    int i,j,key,arr[5];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}