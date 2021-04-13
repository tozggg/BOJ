#include <stdio.h>

int		main()
{
	int N;
	scanf("%d", &N);

	int arr[N];
	for (int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	
	int DP[N];
	for (int i=0; i<N; i++)
	{
		DP[i] = 1;
		for (int j=0; j<i; j++)
		{
			if (arr[j] > arr[i] && !(DP[j] + 1 <= DP[i]))
			//if 조건문의 두번째 조건은 +1 해봤자 자기자신보다 작으면 굳이 들어올 필요가 없기 때문
				DP[i] = DP[j] + 1;
		}
	}

	int res = 0;
	for (int i=0; i<N; i++)
		res = DP[i] > res ? DP[i] : res;
	// 여기 DP배열의 마지막항이 최대값인거 같은데 굳이 배열전체를 확인하는 이유는?
	// => 5 4 3 2 10 순서로 오면 마지막창의 res값은 1이였다고함..

	printf("%d", res);
}
