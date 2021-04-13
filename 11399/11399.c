#include <stdio.h>

int 	N;

void	quickSort(int *arr, int start, int end)
{
	if (start >= end)
		return ;
	
	int p = start;
	int l = start + 1;
	int r = end;
	int temp;

	while (l <= r)
	{
		while (l <= end && arr[l] <= arr[p])
			++l;
		while (r > start && arr[r] >= arr[p])
			--r;
		if (l > r)
		{
			temp = arr[r];
			arr[r] = arr[p];
			arr[p] = temp;
		}
		else
		{
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}
	}
	quickSort(arr, start, r-1);
	quickSort(arr, r+1, end);
}

int		main()
{
	scanf("%d", &N);

	int arr[N];
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	
	quickSort(arr, 0, N-1);
	int res = 0;
	for(int i=0; i<N; i++)
	{
		int sum = 0;
		for(int j=0; j<=i; ++j)
			sum += arr[j];
		res += sum;
	}
	printf("%d", res);
}
