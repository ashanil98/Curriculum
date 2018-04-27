// program to demonstrate prim's algorithm in c
#include<stdio.h>
#include<conio.h>
#define MAX 999

int main()
{
	int n=6,visited[]={0,0,0,0,0,0},i,j,distance[10],path[10],min,flag=0,k,mst=0;
	int graph[6][6] = {{0,1,10,0,0,2},{1,0,0,15,0,2},{10,0,0,0,6,0},{0,15,0,0,6,8},{0,0,6,6,0,4},{2,2,0,8,4,0}};	// adjacency matrix of graph		
	// initializing distance array with infinity
	for(i=0;i<n;i++)
		distance[i] = MAX;
	
	distance[0] = 0;
	path[0] = 0;
	
	for(i=0;i<n;i++)
	{
		for(k=0;k<n;k++)
		{
			if(visited[k] == 0)
			{
				min = k;
				// calculate the first occurrence of visited != 1
				break;
			}
		}
		for(k=min;k<n;k++)
		{
			if(visited[k] == 0)
			{
				if(distance[k] < distance[min])
				{
					min = k;	// calculate the minimum distance node;
				}
			}
		}
		printf("\nSelected node : %d\n",min);
		for(j=0;j<n;j++)
		{
			if((graph[min][j]!=0) && (visited[j] != 1))                        
			{
				if(graph[min][j] < distance[j] )
				{
					distance[j] = graph[min][j];
					path[j] = min;	
				}
			}
		}
		visited[min] = 1;
		
		printf("\n AFter %d  iteration distance array :",i);
		for(k=0;k<n;k++)
		{
			printf("\t%d",distance[k]);
		}
	}
	
	for(i=0;i<n;i++)
	{
		mst = mst + distance[i];
	}
	printf("\nTHE MST COST IS : %d",mst);	
}
