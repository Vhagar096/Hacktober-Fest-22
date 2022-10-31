/*A program to solve the N Queen problem (Backtracking Algorithm)*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int count;

bool isSafe(int** grid, int i, int j, int n)
{
    int row;
    int x=i,y=j;
    for(row=0;row<=i-1;row++)
    {
        if(grid[row][j]==1)
            return false;
    }
    while(x>=0 && y>=0)
    {
        if(grid[x][y]==1)
            return false;
        x--;
        y--;
    }
    x=i;
    y=j;
    while(x>=0 && y<n)
    {
        if(grid[x][y]==1)
            return false;
        x--;
        y++;
    }

    return true;
}

void printGrid(int** mat, int n)
{
    int i,j;
    puts("Correct configuration of queens... ");
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=n-1;j++)
        {
            if(mat[i][j]==1)
                printf("Q ");
            else
                printf("_ ");
        }
        printf("\n");
    }
}

bool NQueenHelper(int** grid, int currentRow, int n)
{
    if(currentRow>=n)
    {
        count++;
        printGrid(grid,n);
        printf("\n");
        return false;
    }
    else
    {
        bool canNextQueenBePlaced;
        int currentCol=0;
        for(;currentCol<n;currentCol++)
        {
            if(isSafe(grid,currentRow,currentCol,n))
            {
                grid[currentRow][currentCol]=1;
                canNextQueenBePlaced=NQueenHelper(grid,currentRow+1,n);
                if(canNextQueenBePlaced)
                    return true;
                grid[currentRow][currentCol]=0;
            }
        }
        return false;
    }
}

void solveNQueen(int** grid, int n)
{
    int currentRow=0;
    bool result=NQueenHelper(grid,currentRow,n);
}

int main()
{
    int n,i,j;
    printf("Enter board size: ");
    scanf("%d",&n);
    int** grid=(int **)malloc(n*sizeof(int *));
    for(i=0;i<=n-1;i++)
        grid[i]=(int *)malloc(n*sizeof(int));
    for(i=0;i<=n-1;i++)
        for(j=0;j<=n-1;j++)
            grid[i][j]=0;

    solveNQueen(grid,n);
	
	if(count>0)
    	printf("\nNumber of configurations: %d",count);
    else
    	printf("!!! No solutions for board size %d !!!",n);

    for(i=0;i<=n-1;i++)
        free(grid[i]);
    free(grid);
    
    return 0;
}
