#include <stdio.h>
#define n 5
void main()
{
    int i,min,arr[5],gap;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(gap=n/2;gap>0;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            int temp = arr[i];
            int j;
            for (j=i;j>=gap && arr[j-gap]>temp;j-=gap)
            {
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}