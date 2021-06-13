#include <stdio.h>

int		heapify(int *heap, int len)
{
	int ret;
	int tmparr[len + 1];
	int tmp;
	int	j;

	for (int i=1; i<=len; i++)
	{
		tmparr[i] = heap[i];
		j = i;
		while (j > 1 && tmparr[j] > tmparr[j / 2])
		{
			tmp = tmparr[j];
			tmparr[j] = tmparr[j / 2];
			tmparr[j / 2] = tmp;
			j = j / 2;
		}
	}
	for (int i=1; i<len; i++)
		heap[i] = tmparr[i + 1];
	return tmparr[1];
}

void	heap_sort(int *arr, int size)
{
	int heap[size + 1];

	for (int i=0; i<size; i++)
		heap[i + 1] = arr[i];
	for (int i=0; i<size; i++)
		arr[i] = heapify(heap, size - i);
}

int		main(void)
{
	int n;
	scanf("%d", &n);
	int	arr[n];
	for (int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	heap_sort(arr, n);
	for (int i=0; i<n; i++)
		printf("%d\t", arr[i]);
	

	return 0;
}
