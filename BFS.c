#include<stdio.h>
int a[50][50], q[50], visited[50], n, i, j, f = 0, r = -1;

void bfs(int v) {
	for (i = 1; i <= n; i++)
	if (a[v][i] && !visited[i])
	q[++r] = i;
	if (f <= r){
		visited[q[f]] = 1;
		bfs(q[f++]);
	}
}

int main()
{
	int v;
	printf("\n Enter the number of vertices:");
	scanf("%d", &n);
	
	for(i=1; i <= n; i++)
	{
		q[i] = 0;
		visited[i] = 0;
	}
	
	printf("\n Enter graph data in matrix form:\n");
	for (i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("\n Enter the starting Vertex:");
	scanf("%d", &v);
	bfs(v);
	printf("\n The node which are reachable are:\n");
	
	for(i=1; i <= n; i++){
		if(visited[i])
		
		printf("%d\t", i);
		
		else{
			
			printf("\n BFS is not possible. Not all nodes are reachable");
			
			break;
		}
	}
}
