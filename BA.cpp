#include<stdio.h>
int main()
{
	int p,r,count=0,i,j,terminate=0;
	printf("Enter the number of processes:");
	scanf("%d",&p);
	printf("Enter the number of resources:");
	scanf("%d",&r);
	
	int alc[p][r],max[p][r],need[p][r],safe[p],avail[r],done[p];
	
	printf("Enter the allocation of resources of all processes:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&alc[i][j]);
		}
		printf("\n");
	}
	
	printf("Enter the max resource process required:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
		printf("\n");
	}
	
	printf("Enter the Available Resource:\n");
	for(i=0;i<r;i++)
	{
		scanf("%d",&avail[i]);
	}
	printf("Need resources matrix:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alc[i][j];
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<p;i++)
	{
		done[i]=0;
	}
	while(count<p)
	{
		for(i=0;i<p;i++)
		{
			if(done[i]==0)
			{
				for(j=0;j<r;j++)
				{
					if(need[i][j]>avail[j])
					{
						break;
					}
				}
				if(j==r)
				{
					safe[count]=i;
					done[i]=1;
					for(j=0;j<r;j++)
					{
						avail[j]+=alc[i][j];
					}
					count++;
					terminate=0;
				}
				else
				{
					terminate++;
				}
			}
		}
		if(terminate==(p-1))
		{
			printf("Safe Sequence does not exist");
		}
	}
	if(terminate!=(p-1))
	{
		printf("\n Available Resource after completion:\n");
		for(i=0;i<r;i++)
		{
			printf("%d\t",avail[i]);
		}
		printf("\nSafe Sequence is:\n");
		for(i=0;i<p;i++)
		{
			printf("P%d\t",safe[i]);
		}
	}
	return 0;
}
