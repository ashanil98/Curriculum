// Rabin KArp Algorithm
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
int RabinKarp(char [],char []);
int getHashValue(char [],int,int);
int main()
{
	int status;
	char text[90],pattern[90];
	printf("\nEnter TEXT : ");
	gets(text);
	printf("\nEnter pattern : ");
	gets(pattern);
	status = RabinKarp(text,pattern);
	if(status == -1)
		printf("\nThe pattern is not found !");
	else
		printf("\nThe pattern is found at position %d",status);
		
	getch();
	return 0;
}

int getHashValue(char pattern[],int start,int m)
{
	int i,hash=0;
	for(i=start;i<m;i++)
	{
		hash = hash + pow(pattern[i],(m-i));
	}
	printf("\n");
	printf("%d",hash);
	return hash;
}

int RabinKarp(char text[],char pattern[])
{
	int m,n,i,temp = 0,j,k;
	m = strlen(pattern);
	n = strlen(text);
	for(i=0;i<=n;i++)
	{
		temp++;
		if(getHashValue(text,i,i+m) == getHashValue(pattern,0,m))
		{
			for(j=0;j<n-m;j++)
			{
				for(k=0;k<m;k++)
				{
					if(text[k+j] != pattern[k])
						break;
				}
				if(j==m)
					return temp;
			}
		}
	}
	return -1;
}


