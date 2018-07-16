#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int hamming[10],i,j,temp[7],p0,p1,p4,countp0;
	clrscr();
	printf("\nEnter 4 bit number: ");
	for(i=1;i<=4;i++)
		scanf("%d",&temp[i]);
	printf("\nYou enterd: ");
	for(i=1;i<=4;i++)
		printf("%d",temp[i]);
	for(i=1;i<=7;i++)
		hamming[i] = -1;
	j=1;
	i=1;
	while(i<=7)
	{
		if(i==1||i==2||i==4)
			i++;
		else
		{
			hamming[i]=temp[j];
			i++;
			j++;
		}
	}
	for(i=1;i<=7;i++)
		printf("\n%d",hamming[i]);
	printf("\nChecking for Po");
	countp0 = 0;
	for(i=1;i<=7;i++)
	{
		if(i%2 == 0)
		{
			continue;
		}
		else
		{
			if(hamming[i] == 1)
				countp0++;
		}
	}
	if(countp0%2==0)
		p0=0;
	else if(countp0%2!=0)
		p0=1;
	hamming[1] = p0;
	countp0=0;
	printf("\npo = %d",p0);
	for(i=2;i<=7;i=i+2)
	{
		 if(hamming[i] == 1)
		 {
			countp0++;
		 }
		 if(hamming[i+1] == 1)
			countp0++;
	}
	printf("\np1 = %d",countp0);
	if(countp0%2==0)
		p1=0;
	else if(countp0%2!=0)
		p1=1;
	hamming[2]=p1;
	countp0=0;
		if(hamming[4]==1)
			countp0++;
		if(hamming[5]==1)
			countp0++;
		if(hamming[6]==1)
			countp0++;
		if(hamming[7]==1)
			countp0++;
	printf("\nP3 = %d",countp0);
	if(countp0%2==0)
		p4=0;
	else if(countp0%2!=0)
		p4=1;
	hamming[4] = p4;
	printf("\nThe final hamming code is: ");
	for(i=1;i<=7;i++)
	{
		printf("%d",hamming[i]);
	}
	getch();
}
