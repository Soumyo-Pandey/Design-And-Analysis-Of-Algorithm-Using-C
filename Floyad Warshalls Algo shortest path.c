#include<stdio.h>
#define MAX 100

void display(int matrix[MAX][MAX], int n);
int adj[MAX][MAX];
int n;
void create_graph();

int main()
{
	int i,j,k;
	int P[MAX][MAX];
	
	create_graph();
	printf("\nThe adjacency matrix is :\n");
	display(adj,n);
	
	for(i=0;i < n;i++)
	   for(j=0;j < n;j++)
	         P[i][j] = adj[i][j];
	
	for(k=0;k < n;k++)
	{
		for(i=0;i < n;i++)
		  for(j=0;j < n;j++)
		      P[i][j] = (P[i][j] || (P[i][j] && P[k][j] ));
		printf("\nP%d is :\n",k);
		display(P,n);
	}
	printf("\nP%d is the path matrix of the given graph\n",k-1);
}
void display(int matrix[MAX][MAX],int n)
{
	int i,j;
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
		        printf("%3d",matrix[i][j]);
		printf("\n");
	}
}
void create_graph()
{
	int i,max_edges,origin,destin;
	
	printf("\nEnter number of vertices: ");
	scanf("%d",&n);
	
	max_edges = n*(n-1);
	
	for(i=1;i<=max_edges;i++)
	{
		printf("\nEnter edge %d(-1 -1) to quit: ",i);
		scanf("%d %d",&origin,&destin);
		if((origin == -1)&&(destin == -1))
		        break;
		if(origin >= n || destin >= n || origin < 0 || destin < 0)
		{
			printf("\nInvalid edge!\n");
			i--;
		}
		else
		    adj[origin][destin] = 1;
	}
}
