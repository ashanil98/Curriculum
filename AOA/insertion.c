// insertion sort
#include<stdio.h>
#include<conio.h>

int main()
{
	int array[10],n,i,j,temp;
	printf("\nEnter number of elements : ");
	scanf("%d",&n);
	printf("\nEnter elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	
	for(i=1;i<n;i++)
	{
		temp = array[i];
		j = i-1;
		while((temp<array[j]) && (j>=0))
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
	
	printf("\nAfter sorting : ");
	for(i=0;i<n;i++)
		printf("\t%d",array[i]);
	return 0;
}
