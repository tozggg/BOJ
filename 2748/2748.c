#include <stdio.h>

int		N;

int		main()
{
	scanf("%d", &N);
	
	long long	arr[91];
	arr[0] = 0;
	arr[1] = 1;
	
	int i = 2;
	while (i <= N)
	{
		arr[i] = arr[i-1] + arr[i-2];
		++i;
	}
	printf("%lld", arr[N]);
}
