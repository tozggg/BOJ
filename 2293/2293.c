#include <stdio.h>

int		main()
{
	int	n;
	int	k;

	scanf("%d %d", &n, &k);
	int arr[n];
	for (int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	int DP[k+1];
	DP[0] = 1;
	for(int i=1; i<=k; i++)
		DP[i] = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=1; j<=k; j++)
		{
			if (j >= arr[i])
				DP[j] += DP[j - arr[i]];
		}
	}
	
	printf("%d\n", DP[k]);
}
