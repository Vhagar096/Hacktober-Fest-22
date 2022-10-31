/*A program to implement Floyd-Warshall Algorithm for a graph to find the all pair of shortest path*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

void apsp(int** graph, int** pred, int start, int end, int n)
{
	if(start==end)
        printf("%d ",start);
	else
    {
		apsp(graph,pred,start,pred[start][end],n);
		printf("-> %d ",end);
	}
}

int floydWarshall(int** graph, int** pred, int start, int end, int n)
{
    int i,j,k;
    int DP[n+1][n+1];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			DP[i][j]=graph[i][j];
	for(k=1;k<=n;k++)
    {
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(DP[i][k]+DP[k][j]<DP[i][j])
                {
					DP[i][j]=DP[i][k]+DP[k][j];
					pred[i][j]=pred[k][j];
				}
		puts("\nCost table...");
		for(i=1;i<=n;i++)
        {
			for(j=1;j<=n;j++)
				printf("%d  ",DP[i][j]);
			printf("\n");
		}
		puts("\nPred table...");
		for(i=1;i<=n;i++)
        {
			for(j=1;j<=n;j++)
				printf("%d  ",pred[i][j]);
			printf("\n");
		}
	}
	if(start==end)
        printf("\nShortest distance between Vertex %d and Vertex %d: 0\n",start,end);
	else if(pred[start][end]==-1)
        printf("\n!!! No direct path exits between Vertex %d and Vertex %d !!!\n",start,end);
	else
    {
        printf("\nShortest path from vertex %d to vertex %d: ",start,end);
		apsp(graph,pred,start,end,n);
		printf("\n\nThe cost is: %d units",DP[start][end]);
	}
}

int main()
{
	int i,j,n,start,end;
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
    int** graph=(int **)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)
        graph[i]=(int *)malloc((n+1)*sizeof(int));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			fscanf(fp,"%d",&graph[i][j]);
    int** pred=(int **)malloc((n+1)*sizeof(int *));
	for(i=0;i<=n;i++)
		pred[i]=(int *)malloc((n+1)*sizeof(int));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(graph[i][j]==999 || graph[i][j]==0)
                pred[i][j]=-1;
			else
                pred[i][j]=i;
    printf("\nEnter the starting vertex: ");
    scanf("%d",&start);
    printf("\nEnter the destination vertex: ");
    scanf("%d",&end);
	floydWarshall(graph,pred,start,end,n);

    return 0;
}
