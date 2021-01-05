/*
	Practical no: 9
	Filename	: graph.c
	Author		: TEJAS DEO
	Date 		: 28/09/2018
	Aim			: To study a graph data structure and demonstrate different
				  traversals on it - Depth First Search and Breadth First Search.

	Problem		: Write a C routine to create an arbitrary graph [a minimum of
				  6 vertices] using adjacency matrix representation.
				  Write menu driven C program that will include routines to - (1)
				  display the graph [the adjacency matrix], (2) execute depth-
				  first search, and (3) execute breadth-first search.
*/
//Libraries included
#include<stdio.h>
#include<stdlib.h>
void bfs(int g[][10],int src,int visited[],int v);
void dfs(int g1[][10],int src,int visited[],int v);
int main()
{
	int i,j,k=0,nov,s,d,op;
	int visited[10]={0,0,0,0,0,0,0,0,0,0};
	int visited1[10]={0,0,0,0,0,0,0,0,0,0};
	int g[10][10]={0};
	int src=0;
	printf("\nEnter the number of vertex:");
	scanf("%d",&nov);
	printf("\nNumber of Edges are:");
	printf("\nEdge_N\tSource\tDestination\tStatus");
	do
	{	k++;
		printf("\n%d\t",k);
		scanf("%d",&s);
		printf("\t");
		scanf("%d",&d);
		printf("\t");
		if(s>=nov || d>=nov)
			printf("\nStatus:Not possible");
		else if (g[s][d]==0)
		{
			g[s][d]=1;
			printf("\t\tEdge is created");
		}
		else
			printf("Edge does exist");
	}while(s!=-1);
	printf("\nThe adjacency table is:\n");
	for(i=0;i<nov;i++)
		printf("|%d\t",i);
	printf("\n_________________________________\n");
	for(i=0;i<nov;i++)
	{
		printf("\n%d\t",i);
		for(j=0;j<nov;j++)
		{
			printf("%d\t",g[i][j]);
		}
	}
	do
	{
	printf("\nEnter the type of traversal:\n");
	printf("1.Depth First Search\t2.Breadth First Search\t0.Exit");
	printf("\nYour choice:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:dfs(g,src,visited1,nov);
		       break;
		case 2:bfs(g,src,visited,nov);
		       break;
		case 0:
		       break;
	}
	}while(op!=0);
	return 0;
}
void dfs(int g[][10],int src,int visited1[],int v)
{
	int i,vknt=0;
	if(src==0)
		visited1[1]=0;
		visited1[src]=1;
		printf("%d\t",src);
		while(vknt<v)
		{
			if(g[src][vknt]==1 && visited1[vknt]==0)
			{
				dfs(g,vknt,visited1,v);
			}
			vknt++;
		}
	return ;
}
void bfs(int g[][10],int src,int visited[],int v)
{
	int vknt,front=-1,rear=-1,q[21];
	if(src==0)
		visited[1]=0;
	visited[src]=1;
	printf("%d\t",src);
	rear++;
	front++;
	q[rear]=src;
	while(front<=rear)
	{
		src=q[front];
		front++;
		vknt=0;
		while(vknt<v)
		{
			if(g[src][vknt]==1 && visited[vknt]==0)
			{
				visited[vknt]=1;
				printf("%d\t",vknt);
				rear++;
				q[rear]=vknt;
			}
			vknt++;
		}
	}
	return;
}





/*OUTPUT

Enter the number of vertex:7

Number of Edges are:
Edge_N	Source	Destination	Status
1	0	1
				Edge is created
2	0	2
				Edge is created
3	0	3
				Edge is created
4	1	0
				Edge is created
5	1	5
				Edge is created
6	1	6
				Edge is created
7	2	0
				Edge is created
8	2	4
				Edge is created
9	2	5
				Edge is created
10	3	0
				Edge is created
11	3	6
				Edge is created
12	4	1
				Edge is created
13	4       2
				Edge is created
14	4	5
				Edge is created
15	5	2
				Edge is created
16	6	1
				Edge is created
17	6	3
				Edge is created
18	-1	-1
				Edge is created
The adjacency table is:
|0	|1	|2	|3	|4	|5	|6
_________________________________

0	0	1	1	1	0	0	0
1	1	0	0	0	0	1	1
2	1	0	0	0	1	1	0
3	1	0	0	0	0	0	1
4	0	1	1	0	0	1	0
5	0	0	1	0	0	0	0
6	0	1	0	1	0	0	0
Enter the type of traversal:
1.Depth First Search	2.Breadth First Search	0.Exit
Your choice:1
0	1	5	2	4	6	3
Enter the type of traversal:
1.Depth First Search	2.Breadth First Search	0.Exit
Your choice:2
0	1	2	3	5	6	4
Enter the type of traversal:
1.Depth First Search	2.Breadth First Search	0.Exit
Your choice:0

*/
