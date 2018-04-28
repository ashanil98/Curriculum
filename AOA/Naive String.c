// program to demonstrate naive string matching algorithm
#include<stdio.h>
#include<conio.h>
#include<string.h>

int NaiveStringMatching(char [],char[]);
int main()
{
	char text[90],pattern[10],pass;
	//clrscr();
	printf("\nEnter text : ");
	gets(text);
	printf("\nEnter pattern : ");
	gets(pattern);
	
	pass = NaiveStringMatching(text,pattern);
	
	if(pass == -1)
		printf("\nThe pattern is not found !");
	else
		printf("\nThe pattern is found at position %d",pass);
	getch();
	return 0;
}

int NaiveStringMatching(char text[],char pattern[])
{
	int m,n,temp=0;
	int i,j;
	
	m = strlen(pattern);
	n = strlen(text);
	
	for(i=0;i<=n-m;i++)
	{
		temp++;
		for(j=0;j<m;j++)
		{
			if(text[i+j]!=pattern[j])
				break;
		}
		if(j == m)
			return temp;
	}
	return -1;
}
