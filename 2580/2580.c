#include <stdio.h>

int catch = 0;
int sdk[9][9];
/*
{ 
	{0, 3, 5, 4, 6, 9, 2, 7, 8}, 
	{7, 8, 2, 1, 0, 5, 6, 0, 9}, 
	{0, 6, 0, 2, 7, 8, 1, 3, 5}, 
	{3, 2, 1, 0, 4, 6, 8, 9, 7}, 
	{8, 0, 4, 9, 1, 3, 5, 0, 6}, 
	{5, 9, 6, 8, 2, 0, 4, 1, 3},
	{9, 1, 7, 6, 5, 2, 0, 8, 0}, 
	{6, 0, 3, 7, 0, 1, 9, 5, 2}, 
	{2, 5, 8, 3, 9, 4, 7, 6, 0} 
};
*/

int		isHorizon(int row, int col)
{
	for (int i=0; i<9; i++)
	{
		if (i != col && sdk[row][i] != 0)
		{
			if (sdk[row][col] == sdk[row][i])
				return (1);
		}
	}
	return (0);
}

int		isVertical(int row, int col)
{
	for (int i=0; i<9; i++)
	{
		if (i != row && sdk[i][col] != 0)
		{
			if (sdk[row][col] == sdk[i][col])
				return (1);
		}
	}
	return (0);
}

int		isSquare(int row, int col)
{
	for (int i=(row/3*3); i<(row/3*3+3); i++)
	{
		for (int j=(col/3*3); j<(col/3*3+3); j++)
		{
			if (!(i == row && j == col) && sdk[i][j] != 0)
			{
				if (sdk[row][col] == sdk[i][j])
					return (1);
			}
		}
	}
	return (0);
}

void	sdkPrint()
{
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			printf("%d", sdk[i][j]);
			if (j == 8)
				printf("\n");
			else
				printf(" ");
		}
	}
}

void	solve()
{
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			if (sdk[i][j] == 0)
			{
				for (int k=1; k<=10; k++)
				{
					if (k == 10)
					{
						sdk[i][j] = 0;
						return ;
					}
					sdk[i][j] = k;
					if (!isHorizon(i, j) && !isVertical(i, j) && !isSquare(i, j))
					{
						solve(i, j);
						if (catch == 1)
							return ;
					}
				}
			}
			else if (i == 8 && j == 8)
			{
				sdkPrint();
				catch = 1;
			}
		}
	}
}

int		main()
{

	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
			scanf("%d", &sdk[i][j]);
	}


	solve();
}
