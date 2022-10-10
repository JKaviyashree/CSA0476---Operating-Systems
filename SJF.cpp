#include<stdio.h>
int main()
{
	int p[100],bt[100],wt[100],tat[100],n,i,j,w=0,t1,t2,c=1;
	printf("Enter the number of Processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=c;
		c+=1;
		printf("Enter Burst Time : %d : ",i+1);
		scanf("%d",&bt[i]);
	}
	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if(bt[i]>bt[j])
			{
				t1=bt[i];
				bt[i]=bt[j];
				bt[j]=t1;
				
				t2=p[i];
				p[i]=p[j];
				p[j]=t2;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		wt[i]=w;
		w+=bt[i];
	}
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
	printf("SHORTEST JOB FIRST\n");
	printf("Process \tBurst Time \tWaiting Time \tTurn Around Time");
	for(i=0;i<n;i++)
	{
		printf("\n%d \t\t%d \t\t%d \t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
}
