//lONGEST COMMON SUBSEQUENCE --> LCS
#include<stdio.h>
#include<conio.h>
#include<string.h>
char b[10][10] ,x[10],y[10],LCS[10],k=0;
int m,n;
void print(int i,int j)
{
	if(i==0||j==0)
		return;
	else
	{
		if(b[i][j] == 'd')
		{
			print(i-1,j-1);
			LCS[k] = x[i-1];
			k++;
		}
		else if(b[i][j] == 'l')
			print(i,j-1);
		else
			print(i-1,j);
	}
}


void lcs(char x[],char y[])
{
	static int c[10][10],i,j;
	m = strlen(x);
	n = strlen(y);
	for(i=0;i<=m;i++)
		c[0][i] = 0;
	for(i=0;i<=n;i++)
		c[i][0] = 0;
		
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(x[i-1] == y[j-1])
			{
				c[i][j] = c[i][j] + c[i-1][j-1] + 1;
				b[i][j] = 'd';
			}
			else
			{
				if(c[i-1][j] >= c[i][j-1])
				{
					c[i][j] = c[i-1][j];
					b[i][j] = 'u';
				}
				else
				{
					c[i][j] = c[i][j-1];
					b[i][j] = 'l';
				}
			}
		}
	}
	printf("lcs : \n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("(%d,%c)\t",c[i][j],b[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	printf("\nEnter sequence 1: ");
	gets(x);
	printf("\nEnter sequence 2: ");
	gets(y);
	lcs(x,y);
	print(m,n);
	printf("\nLCS : ");
	puts(LCS);
	return 0;
}
