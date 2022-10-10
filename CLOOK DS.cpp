// C LOOK DISK SCHEDULING
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,j,n,THM=0,in,size,index;
    printf("Enter the number of Requests : ");
    scanf("%d",&n);
    printf("Enter the Requests sequence : ");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position : ");
    scanf("%d",&in);
    printf("Enter total disk size : ");
    scanf("%d",&size);
    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(in<RQ[i])
        {
            index=i;
            break;
        }
    }
    for(i=index;i<n;i++)
    {
        THM=THM+abs(RQ[i]-in);
        in=RQ[i];
	}      
    for( i=0;i<index;i++)
    {
        THM=THM+abs(RQ[i]-in);
        in=RQ[i];
    }
    printf("SEEK TIME : %d",THM);
    return 0;
}
