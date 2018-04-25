// Bresenham's line drawing algorithm
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void Bresenham(int,int,int,int);
void main()
{
	int x1,y1,x2,y2;
	int gd=DETECT,gm;
	clrscr();
	printf("\nEnter starting point : ");
	scanf("%d%d",&x1,&y1);
	printf("\nEnter Ending point : ");
	scanf("%d%d",&x2,&y2);
	initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
	Bresenham(x1,y1,x2,y2);
	getch();
}
void Bresenham(int x1,int y1,int x2,int y2)
{
	int dx,dy,k,dp;
	dx = abs(x2-x1);
	dy = abs(y2-y1);

	dp = 2*dx - dy;	// initial dp

	for(k=0;k<dx;k++)
	{
		if(dp<0)
		{
			x1 = x1+1;
			putpixel(x1,y1,WHITE);
			dp = dp + 2*dy;
		}
		else
		{
			x1 = x1 + 1;
			y1 = y1 + 1;
			putpixel(x1,y1,WHITE);
			dp = dp + 2*dy - 2*dx;
		}
	}
}