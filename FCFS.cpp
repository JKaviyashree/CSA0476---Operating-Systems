#include<stdio.h>
int main()
{
	int n,i,bt[100],wt[100],tat[100],at=0,w=0;
	printf("Enter the number of Process : ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("Burst Time : %d : ",i+1);
		scanf("%d",&bt[i]);
	}
	for (i=0;i<n;i++)	
	{
		wt[i]=w;
		w=w+bt[i];
		printf("Waiting Time : %d : %d \n",i+1,wt[i]);
	}
	for (i=0;i<n;i++)	
	{
		tat[i]=wt[i]+bt[i];
		printf("Turn Around Time : %d : %d \n",i+1,tat[i]);
	}
}
