//	program to implement Liang Barsky

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{

	float x1,y1,x2,y2,dx,dy;
	float u1[10],u2[10],p[4],q[4];
	float r[4];
	float U1 ,U2;
	int xmin,xmax,ymin,ymax;	//window co-ordinates
	int i,flag=0;
	int lengthu1=0,lengthu2=0; 						// u1 is 0 and u2 is 1
	float max,min;

	float X1,Y1,X2,Y2;	// final co-ordinates after clipping

	int gd=DETECT,gm;
	clrscr();

	//taking window co-ordinates from user
	printf("Enter lowest window coordinates(xmin,ymin): ");
	scanf("%d%d",&xmin,&ymin);
	printf("\nEnter highest window co-ordinates(xmax,ymax): ");
	scanf("%d%d",&xmax,&ymax);

	//taking first and last point of line from user
	printf("\nEnter co-ordinates of first point (x1,y1):");
	scanf("%f%f",&x1,&y1);
	printf("\nEnter co-ordinates of last point (x2,y2): ");
	scanf("%f%f",&x2,&y2);

	initgraph(&gd,&gm,"C:\\TurboC4\\BGI");
	rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);
	getch();

	// initialize u1 and u2 as specified in algorithm
	u1[0]=0;	lengthu1++;
	u2[0]=1;	lengthu2++;

	// calculate the difference
	dx=x2-x1;
	dy=y2-y1;

	// calculate value of p1,p2,p3,p4
	p[0]= -dx;
	p[1]= dx;
	p[2] = -dy;
	p[3]=dy;

	// calculate value of q1,q2,q3,q4
	q[0] = x1-xmin;
	q[1] = xmax-x1;
	q[2] = y1-ymin;
	q[3] = ymax-y1;

	// now let's write a condition if a line is outside window
	for(i=0;i<4;i++)
	{       flag=0;
		if(p[i] == 0 && q[i] < 0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		for(i=0;i<4;i++)
		{
			if(p[i] == 0)
				continue;
			else
			{
				printf("\n%f",r[i]);
				r[i] = q[i]/p[i];
				if(p[i] < 0)
					u1[lengthu1++] = r[i];
				else if(p[i] > 0)
					u2[lengthu2++] = r[i];
			}
		}
		max=u1[0];

		for(i=0;i<lengthu1;i++)
		{
			if(max < u1[i])
				max = u1[i];

		}
		min = u2[0];
		for(i=0;i<lengthu2;i++)
		{
			if(u2[i] < min)
				min = u2[i];
		}

		printf("\n dx = %f",dx);
		printf("\n dy = %f",dy);

		printf("%f",x1+(max*dx));

		X1 = x1+(max*dx);
		Y1 = y1+(max*dy);

		X2 = x1 + min*dx;
		Y2 = y1 + min*dy;

		cleardevice();
		outtextxy(0,0,"After clipping");
		rectangle(xmin,ymin,xmax,ymax);
		line(X1,Y1,X2,Y2);

		printf("\n( %f %f)",X1,Y1);
		printf("\n( %f %f)",X2,Y2);
		getch();

	}
	else if(flag==1)
		printf("Line lies outside the window");
		getch();
	getch();
}