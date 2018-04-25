// boundary fill algorithm
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void BF(int,int,int,int);
void main()
{
	int x,y,radius;
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
	x=getmaxx()/2;
	y=getmaxy()/2;
	radius = 10;
	setcolor(BLUE);
	circle(x,y,radius);
	BF(x,y,RED,BLUE); // RED is fill color and BLUE is boundary color
	getch();
	closegraph();
}
void BF(int x,int y,int fill,int boundary)
{
	int current = getpixel(x,y);
	if((current != boundary) && (current != fill))
	{
		setcolor(fill);
		putpixel(x,y,fill);
		BF(x+1,y,fill,boundary);
		BF(x-1,y,fill,boundary);
		BF(x,y+1,fill,boundary);
		BF(x,y-1,fill,boundary);
	}
}