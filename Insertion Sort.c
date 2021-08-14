#include<stdio.h>
#include<conio.h>

int main()
{
	int i,j,n,temp;
	int arr[70];
	
	printf("Enter the no of elements:");
	scanf("%d",&n);
	
	printf("Enter %d integers\n", n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<=n-1;i++)
	{
		j = i;
		while(j > 0 && arr[j-1] > arr[j])
		{
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}
	printf(" Sorted list in ascending order:\n");
	
	printf("\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d",arr[i]);
	}
	return 0;
}
