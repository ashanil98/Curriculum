 // program for character generation
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int gd=DETECT,gm;
	int a[7][7]={{1,1,1,1,1,1,1},
		     {0,0,0,1,0,0,0},
		     {0,0,0,1,0,0,0},
		     {0,0,0,1,0,0,0},
		     {0,0,0,1,0,0,0},
		     {0,0,0,1,0,0,0},
		     {1,1,1,1,1,1,1}
		     };
	// array initialized to character 'I'
	int i,j;
	clrscr();
	initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			if(a[i][j]==1)
			{
				putpixel(100+j,100+i,15);
			}
		}
	}
	getch();
	closegraph();
}