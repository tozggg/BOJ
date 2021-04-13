#include <stdio.h>

int		N;
int		cnt;

int		isHorizontal(int *arr, int col)
{
	for (int i=0; i<col; i++)
	{
		if (arr[col] == arr[i])
			return (1);
	}
	return (0);
}

int		isDiagonal(int *arr, int col)
{
	for (int i=0; i<col; i++)
	{
		if ((col-i == arr[col]-arr[i]) || (col-i == arr[i]-arr[col]))
			return (1);
	}
	return (0);
}

void	solve(int *arr, int col)
{
	if (col == N)
	{
		++cnt;
		return ;
	}
	for (int i=0; i<N; i++)
	{
		arr[col] = i;
		if (!(isDiagonal(arr, col)) && !(isHorizontal(arr, col)))
			solve(arr, col+1);
	}
}

int		main()
{
	scanf("%d", &N);
	int arr[N];

	solve(arr, 0);
	printf("%d", cnt);
}
