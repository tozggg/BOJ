#include <stdio.h>

int		main()
{
	int n;
	int k;
	
	scanf("%d %d", &n, &k);
	
	int weight[n+1];
	int value[n+1];
	weight[0] = 0;
	value[0] = 0;
	for(int i=1; i<=n; i++)
		scanf("%d %d", &weight[i], &value[i]);
	
	int DP[n+1][k+1];
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=k; j++)
			DP[i][j] = 0;
	}
	
	for	(int i=1; i<=n; i++)
	{
		for (int j=1; j<=k; j++)
		{
			// 넣을수 없을때
			if (j < weight[i])
				DP[i][j] = DP[i-1][j];
			// 넣을수 있을때 -> 자리가 없을때와 자리가 있을때
			else
				DP[i][j] = ( DP[i-1][j] > (DP[i-1][j-weight[i]]+value[i]) ? DP[i-1][j] : (DP[i-1][j-weight[i]]+value[i]) );
		}
	}

	//for (int i=0; i<=n; i++)
	//{
	//	for (int j=0; j<=k; j++)
	//		printf("%d\t", DP[i][j]);
	//	printf("\n");
	//}

	printf("%d\n", DP[n][k]);
}
