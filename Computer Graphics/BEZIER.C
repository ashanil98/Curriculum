// cubic bezier
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
void Brezier(int x[],int y[])
{
	double i,color=0;
	float X,Y;

	for(i=0;i<=1;i=i+0.0001)
	{
		X = pow(1-i,3)*x[0] + 3*i*pow(1-i,2)*x[1] + 3*i*i*(1-i)*x[2] + i*i*i*x[3];
		Y = pow(1-i,3)*y[0] + 3*i*pow(1-i,2)*y[1] + 3*i*i*(1-i)*y[2] + i*i*i*y[3];
		putpixel(X,Y,color++);  // for colourful curve
		delay(1);         // delay of 1 sec
	}

}
void main()
{
	int gd=DETECT,gm,x[10],y[10],i,length=0,points[10];
	clrscr();

	printf("\nEnter x and y co-ordinates of every point (x,y):");
	for(i=0;i<4;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		//points is an array which will contain x,y values of specified points
		points[length++]=x[i] ;
		points[length++]=y[i];
		//length is length of array points

	}
	points[length++]=x[0];
	points[length++]=y[0];
	// this is done for using drawpoly()
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cleardevice();

	for(i=0;i<4;i++)
		putpixel(x[i],y[i],15);
		drawpoly(5,points);   //for drawing outer window

	Brezier(x,y);
	getch();
	closegraph();
}




