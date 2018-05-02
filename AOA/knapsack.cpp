// 							0/1 Knapsack
#include<stdio.h>
#include<conio.h>

int max(int a,int b)
{
	if(a > b)
		return a;
	else
		return b;
}
int main()
{
	static int c[10][10],p[10],w[10],n,i,m,j;
	int totalprofit,items[10],k=0;
	
	printf("\nEnter total capacity of kmapsack : ");
	scanf("%d",&m);
	printf("\nEnter total number of items : ");
	scanf("%d",&n);
	
	printf("\n Enter item details \n ");
	p[0]= -1;
	w[0] = -1;
	for(i=1;i<=n;i++)
	{
		printf("\nEnter weight and profit of item %d : ",i);
		scanf("%d %d",&w[i],&p[i]);	
	}
		
	// making 0th row and 0th column as 0
	for(i=0;i<=n;i++)
		c[i][0] = 0;
	for(i=0;i<=m;i++)
		c[0][i] = 0;
		
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(j-w[i] >= 0)
			{
				c[i][j] = max(c[i-1][j] , p[i]+c[i-1][j-w[i]]);
			}
			else
				c[i][j] = c[i-1][j];
		}
	}
	
	printf("\n After processing the array c[][] is :\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%4d",c[i][j]);
		}
		printf("\n");
	}
	printf("\nbacktracking...");
	totalprofit = c[n][m];
	j=m;
	for(i=n;i>0;i--)
	{
			if(c[i][j] != c[i-1][j])
			{
				items[k] = i;
				j = j-w[i];	
				k++;
			}
	}
	printf("\nThe items added are : ");
	for(i=0;i<k;i++)
		printf("%3d",items[i]);
		
	printf("\nTotal profit : %d",totalprofit);
	getch();
	return 0;
}
