// Flood fill algorithm in c
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void FF(int,int,int,int);
void main()
{
	int x,y,radius;
	int gd=DETECT,gm;
	clrscr();
	printf("\nEnter centre of circle : ");
	scanf("%d%d",&x,&y);
	printf("\nEnter Radius : ");
	scanf("%d",&radius);
	initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
	setcolor(BLUE);
	circle(x,y,radius);
	FF(x,y,RED,BLACK);	// since the screen is BLACK
	getch();
	closegraph();
}
void FF(int x,int y,int fill,int old)
{
	if(getpixel(x,y) == old)
	{
		setcolor(fill);
		putpixel(x,y,fill);
		FF(x+1,y,fill,old);
		FF(x-1,y,fill,old);
		FF(x,y+1,fill,old);
		FF(x,y-1,fill,old);
	}
}