#define M 5
#include<stdio.h>
int main()
{
    int i,j,val,a[M];
    printf("enter elements of array data");
    for(i=0;i<M;i++)
        scanf("%d",&a[i]);
    printf("before sorting array elements are\n");
    for(i=0;i<5;i++)
        printf("%4d",a[i]);
    for(i=1;i<M;i++)
    {
        val=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>val)
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=val;
    }
    printf("\nafter sorting\n");
    for(i=0;i<5;i++)
        printf("%4d",a[i]);
}
