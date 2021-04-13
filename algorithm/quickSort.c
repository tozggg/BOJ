#include <stdio.h>

void	quickSort(int *arr, int start, int end)
{
	if (start >= end)
		return;

	int p = start;
	int l = start + 1;
	int r = end;
	int tmp;

	while (l <= r)
	{
		while (arr[l] <= arr[p] && l <= end)
			++l;
		while (arr[r] >= arr[p] && r > start)
			--r;
		if (l <= r)
		{
			tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
		}
		else
		{
			tmp = arr[r];
			arr[r] = arr[p];
			arr[p] = tmp;
		}
	}
	quickSort(arr, start, r-1);
	quickSort(arr, r+1, end);
}

int		main()
{
	int arr[] = {1, 3, 2, 5, 4};

	quickSort(arr, 0, 4);

	for(int i=0; i<5; i++)
		printf("%d", arr[i]);
}
