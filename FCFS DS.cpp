// FCFS DISK SCHEDULING
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,n,THM=0,in;
    printf("Enter the number of Requests : ");
    scanf("%d",&n);
    printf("Enter the Requests sequence : ");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position : ");
    scanf("%d",&in);
    for(i=0;i<n;i++)
    {
        THM=THM+abs(RQ[i]-in);
        in=RQ[i];
    }
    printf("SEEK TIME : %d",THM);
    return 0;
}
