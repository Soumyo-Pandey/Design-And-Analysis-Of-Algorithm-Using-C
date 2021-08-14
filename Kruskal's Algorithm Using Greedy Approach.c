#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[10][10],parent[9];
int find(int);
int uni(int,int);
int main()
{
	printf("\n Implementation of Kruskals Algorithm");
	printf("\n Enter the no. of Vertices:");
	scanf("%d",&n);
	printf("\n Enter the cost of Adjacency Matrix:\n");
	for(i=0;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			       cost[i][j]=999;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree\n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[a][b]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
	return 0;
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
