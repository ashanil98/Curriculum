// knapsack
#include<stdio.h>
#include<conio.h>
struct knapsack
{
	int profit;
	int weight;
	float pbyw; // used to calculate profit / weight
}p[100],temp;

int main()
{
	int i,n,j;
	float capacity , totalprofit=0;
	printf("\nEnter total capacity of knapsack : ");
	scanf("%f",&capacity);
	printf("\nEnter number of items : ");
	scanf("%d",&n);
	printf("\nEnter item details : ");
	for(i=0;i<n;i++)
	{
		printf("\nEnter weight and profit of item %d : ",(i+1));
		scanf("%d %d",&p[i].weight,&p[i].profit);
		p[i].pbyw = (float)(p[i].profit/p[i].weight);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].pbyw < p[j].pbyw)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	
	printf("\n After processing data : \n");
	printf("\nprofit\tweight\tp[i]/w[i]\n");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%f",p[i].profit,p[i].weight,p[i].pbyw);
	}
	
	printf("\n Filling the knapsack with objects.... ");
	for(i=0;i<n;i++)
	{
		if(capacity > p[i].weight)
		{
			capacity = capacity - p[i].weight;
			totalprofit = totalprofit + p[i].profit;
		}
		if((capacity < p[i].weight) && capacity!=0)
		{
			totalprofit = totalprofit + (float)((capacity/p[i].weight) * p[i].profit);
			capacity = capacity - (float)((capacity/p[i].weight) * p[i].weight);
		}
		if(capacity == 0)
			break;
	}
	
	printf("\n Final capacity : %f",capacity);
	printf("\n Final profit : %f",totalprofit);
	getch();
	return 0;
}
