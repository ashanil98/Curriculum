// midpoint circle drawing algorithm
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void pixel(int,int,int,int);
void main()
{
	int xc,yc,x,y,r,dp;
	int gd = DETECT,gm;
	clrscr();
	printf("\nEnter centre of circle : ");
	scanf("%d%d",&xc,&yc);
	printf("\nEnter radius of circle : ");
	scanf("%d",&r);
	initgraph(&gd,&gm,"C://TurboC4//TC//BGI");
	dp=1-r;	// initial value of decision parameter
	x = 0;
	y = r;	// since we start plotting from second octant
	pixel(xc,yc,x,y);
	while(x<y)
	{
		x = x+1;
		if(dp<0)
		{
			dp = dp + (2*x) +1;
		}
		else
		{
			y = y-1;
			dp = dp + (2*x) - (2*y) + 1;
		}
		pixel(xc,yc,x,y);
	}
	getch();
	closegraph();
}

void pixel(int xc,int yc,int x,int y)
{
	putpixel(xc+x,yc+y,15);
	putpixel(xc+y,yc+x,15);
	putpixel(xc-y,yc+x,15);
	putpixel(xc-x,yc+y,15);
	putpixel(xc-x,yc-y,15);
	putpixel(xc-y,yc-x,15);
	putpixel(xc+x,yc-y,15);
	putpixel(xc+y,yc-x,15);
}
