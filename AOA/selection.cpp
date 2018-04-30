#include<stdio.h>
#include<conio.h>

void swap(int*,int*);
int minimum(int[],int,int);
int main()
{
	int array[10],n,i,min,k;
	printf("\nEnter number of elements : ");
	scanf("%d",&n);
	printf("\nEnter elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	
	for(i=0;i<n;i++)
	{	
		min = minimum(array,i,n);		// function returns the index having minimum value
		swap(&array[min],&array[i]);
		printf("\nAfter %d iterations ",i+1);
		for(k=0;k<n;k++)
			printf("%d\t",array[k]);
	}	
	return 0;
}

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int minimum(int array[],int start,int end)
{
	int i,min = start;
	for(i=start;i<end;i++)
	{
		if(array[i]<array[min])
			min = i;
	}
	return min;
}
