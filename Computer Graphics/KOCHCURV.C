// program for koch curve
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void Koch(int,int,int,int,int);
void main()
{
	int x1,y1,x2,y2,iterations;
	int gd=DETECT,gm;
	clrscr();
	printf("\nEnter the starting point of line : ");
	scanf("%d%d",&x1,&y1);
	printf("\nEnter the ending point of line : ");
	scanf("%d%d",&x2,&y2);
	printf("\nEnter number of iterations : ");
	scanf("%d",&iterations);
	initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
	Koch(x1,y1,x2,y2,iterations);
	getch();
	closegraph();
}
void Koch(int x1,int y1,int x2,int y2,int iterations)
{
	int x3,y3,x4,y4,x,y;
	float angle=60*(M_PI/180);
	x3 = (2*x1 + x2)/3;
	y3 = (2*y1 + y2)/3;

	x4 = (x1 + 2*x2)/3;
	y4 = (y1 + 2*y2)/3;

	x = x3 + (x4-x3)*cos(angle) + (y4-y3)*sin(angle);
	y = y3 - (x4-x3)*sin(angle) + (y4-y3)*cos(angle);

	if(iterations>0)
	{
		Koch(x1,y1,x3,y3,iterations-1);
		Koch(x3,y3,x,y,iterations-1);
		Koch(x,y,x4,y4,iterations-1);
		Koch(x4,y4,x2,y2,iterations-1);
	}
	else
	{
		line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x2,y2);
	}
}