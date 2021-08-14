#include<stdio.h>
#include<conio.h>

int main()
{
	int array[100],n,c,d,pos,t;
	
	printf("\nEnter the no of Elements:");
	scanf("%d",&n);
	
	printf("Enter %d integers\n", n);
	
	for(c=0;c<n;c++)
	  scanf("%d", &array[c]);
	
	for(c=0;c<(n-1);c++)
	{
		pos=c;
		
		for(d=c+1;d<n;d++)
		{
			if (array[pos] > array[d])
			  pos=d;
		}
		if (pos != c)
		{
			t=array[c];
			array[c] = array[pos];
			array[pos] = t;
		}
	}
	
	printf("Sorted list in asending order:\n");
	
	for(c=0;c<n;c++)
	  printf("%d\n",array[c]);
	
	return 0;
}
