#include<stdio.h>
#include<conio.h>
int x[70],g[70][70],n,i,j,m;
void next_value(int k)
{
	while(1)
	{
		x[k] = (x[k] + 1)%(m + 1);
		if (x[k] == 0)
		          return;
		for(j=1; j <= n; j++)
		{
			if(g[k][j]!=0 && (x[k] == x[j]))
			           break;
		}
		if (j == n+1)
		           return;
	}
}
void coloring(int k)
{
	do
	{
		next_value(k);
		if (x[k] == 0)
		           return;
		if (k == n)
		{
			for(i=1; i <= n; i++)
			                 printf("Vertex %d = color No. %d\t",i,x[i]);
		    printf("\n");
		}
		else
		    coloring(k+1);
	}while(k<n+1);
}
int main()
{
	int e,k,l;
	printf("Enter no. of Vertices:");
	scanf("%d",&n);
	printf("Enter no of edges:");
	scanf("%d",&e);
	m = n-1;
	printf("\n The maximum possible colours that can be assigned are:%d\n",m);
	for(i=0; i <= n; i++)
	         for(j=0;j <= n; j++)
	                 g[i][j] = 0;
	printf("Enter u and v of an edge\n");
	for(i=0; i <= e; i++)
	{
		printf("\nfor edges %d\n",i);
		scanf("%d %d",&k,&l);
		g[k][l] = 1;
		g[l][k] = 1;
	}
	for(i=0; i <= n; i++)
	              x[i] = 0;
	printf("\n The Colouring possibilities are:");
	   coloring(1);
	return 0;   
}
