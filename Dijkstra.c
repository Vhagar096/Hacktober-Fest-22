/*A program to implement Dijkstra's Algorithm for a graph to find the shortest path*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node
{
    int key;
    char parent;
    bool sptset;
}GRAPHNODE;

void path(int i, int** graph, GRAPHNODE *helper, int *cost)
{
	if(helper[i].parent=='N')
		return;
	else
	{
		(*cost)+=graph[helper[i].parent-64][i];
		path((int)helper[i].parent-64,graph,helper,cost);
		printf("%c->%c  ",helper[i].parent,(char)(i+64));
	}
}

void print(int vertex, int dest, int** graph, GRAPHNODE *helper)
{
    int i;
    int cost=0;
	if(i!=vertex)
	{
		printf("\nShortest path from vertex %c to vertex %c: ",(char)(vertex+64),(char)(dest+64));
		path(dest,graph,helper,&cost);
		if(helper[dest].key!=INT_MAX)
			printf("\nThe cost is: %d units",cost);
		else
			printf("\nThe cost is: Infinite");
	}
}

int extractMin(GRAPHNODE *helper, int n)
{
	int i,minIndex;
    int min=INT_MAX;
    for(i=1;i<=n;i++)
        if(helper[i].sptset==false && helper[i].key<min)
        {
            min=helper[i].key;
            minIndex=i;
        }

    return minIndex;
}

void dijkstras(int vertex, int** graph, GRAPHNODE *helper, int n)
{
	int i,j,u;
    for(i=1;i<=n;i++)
    {
        helper[i].key=INT_MAX;
        helper[i].parent='N';
        helper[i].sptset=false;
    }
    helper[vertex].key=0;
    for(i=1;i<=n;i++)
    {
        u=extractMin(helper,n);
        helper[u].sptset=true;
        for(j=1;j<=n;j++)
            if(graph[u][j]>0 && helper[j].sptset==false && helper[j].key>helper[u].key+graph[u][j])
            {
                helper[j].key=helper[i].key+graph[u][j];
                helper[j].parent=(char)(u+64);
            }
    }
}

int main()
{
    int i,j,n;
    char v,d;
    FILE *fp;
    char file[100];
    printf("Enter file name: ");
    gets(file);
    fp=fopen(file,"r");
    if(fp==NULL)
    {
        puts("\n!!! File not found !!!");
        exit(0);
    }
    fscanf(fp,"%d",&n);
    GRAPHNODE* helper=(GRAPHNODE *)malloc((n+1)*sizeof(GRAPHNODE));
    int** graph=(int **)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)
        graph[i]=(int *)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fscanf(fp,"%d",&graph[i][j]);
    printf("\nEnter the starting vertex: ");
    scanf("%c",&v);
    getchar();
    printf("\nEnter the destination vertex: ");
    scanf("%c",&d);
    if((v>=65 && v<(65+n)) && (d>=65 && d<(65+n)))
    {
        dijkstras(v-64,graph,helper,n);
        print(v-64,d-64,graph,helper);
    }
	else
        puts("!!! Invalid input. Please enter a valid vertex !!!");
    
    return 0;
}
