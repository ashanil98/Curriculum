// DDA line drawing alogorithm in c
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void DDA(int,int,int,int);
int round(float);
void main()
{
	int x1,y1,x2,y2;
	int gd=DETECT,gm;
	clrscr();
	printf("\nEnter starting point of line : ");
	scanf("%d%d",&x1,&y1);
	printf("\nEnter Ending point of line : ");
	scanf("%d%d",&x2,&y2);
	initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
	DDA(x1,y1,x2,y2);
	getch();
	closegraph();
}
void DDA(int x1,int y1,int x2,int y2)
{
	float x,y,xinc,yinc;
	int dx,dy,steps,i;

	dx = x2-x1;
	dy = y2-y1;

	if(abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	xinc = (float)dx/steps;
	yinc = (float)dy/steps;

	x=x1;
	y=y1;

	// let's plot the first point
	putpixel(round(x),round(y),WHITE);

	for(i=1;i<steps;i++)
	{
		x = x + xinc;
		y = y + yinc;
		putpixel(round(x),round(y),WHITE);
	}
}
int round(float x)
{
	int temp = (int)x;
	if(x > (temp+0.5))
		return temp+1;
	else
		return temp;
}
