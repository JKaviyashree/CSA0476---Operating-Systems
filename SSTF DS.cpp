// SHORTEST SEEK TIME FIRST DISK SCHEDULING
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,n,THM=0,in,count=0;
    printf("Enter the number of Requests : ");
    scanf("%d",&n);
    printf("Enter the Requests sequence : ");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position : ");
    scanf("%d",&in);    
    while(count!=n)
    {
        int min=1000,d,ix;
        for(i=0;i<n;i++)
        {
           d=abs(RQ[i]-in);
           if(min>d)
           {
               min=d;
               ix=i;
           }
        }
        THM=THM+min;
        in=RQ[ix];
        RQ[ix]=1000;
        count++;
    }
    printf("SEEK TIME : %d",THM);
    return 0;
}
