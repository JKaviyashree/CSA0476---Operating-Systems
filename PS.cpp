#include<stdio.h>
int main()
{
	int p[100],bt[100],wt[100],tat[100],pr[100],n,i,j,w=0,c=1,t1,t2,t3;
	printf("Enter the Number of Processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		printf("Enter the Burst Time : %d : ",i+1);
		scanf("%d",&bt[i]);
		printf("Enter the Priority Number for : Process %d : ",i+1);
		scanf("%d",&pr[i]);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(pr[i]>pr[j]){
				t1=pr[i];
				pr[i]=pr[j];
				pr[j]=t1;
				
				t2=bt[i];
				bt[i]=bt[j];
				bt[j]=t2;
				
				t3=p[i];
				p[i]=p[j];
				p[j]=t3;
			}}}
	for(i=0;i<n;i++)
	{
		wt[i]=w;
		w=w+bt[i];
	}
	for (i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
	printf("PRIORITY BASED\n");
	printf("Process \tBurst Time \tWaiting Time \tTurn Around Time");
	for(i=0;i<n;i++)
	{
		printf("\n%d \t\t%d \t\t%d \t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
}
