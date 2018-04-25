// Bezier curve
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void Bezier(int [],int []);
void main()
{
	int x[5],y[5],i;
	int gd=DETECT,gm;
	clrscr();
	printf("\nEnter x and y values for control points :");
	for(i=0;i<4;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
	for(i=0;i<3;i++)
	{
		line(x[i],y[i],x[i+1],y[i+1]);
	}
	Bezier(x,y);
	getch();
	closegraph();
}
void Bezier(int x[],int y[])
{
	int X,Y;
	float i;
	for(i=0.0;i<=1.0;i=i+0.0001)
	{
		X = x[3]*pow(i,3) + 3*x[2]*pow(i,2)*(1-i) + 3*x[1]*i*pow(1-i,2) + x[0] * pow(1-i,3);
		Y = y[3]*pow(i,3) + 3*y[2]*pow(i,2)*(1-i) + 3*y[1]*i*pow(1-i,2) + y[0]*pow(1-i,3);
		putpixel(X,Y,15);
	}
}