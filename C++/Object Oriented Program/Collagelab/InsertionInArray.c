#include<stdio.h>
int main()
{
    int arr[20]={12,34,56,7,7,87};
    int i,x,pos,n=5;
    printf("Array elements before insertion");

    for(i=0;i<n;i++)
    {
        printf("%d",arr[1]);
    }
    x=50;
    pos=4;
    n++;
    for(i=n-1;i>=pos;i--)
       arr[i]=arr[i-1];
    arr[pos-1]=x;
}