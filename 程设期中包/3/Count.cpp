#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int turn(int N, int K, int M)
{
	if (N == 1)
		return 0;
	if (N > 1)
		return ((turn(N - 1,K,M ) + ((M-1)%N)+1) % N);
}


int main()
{
	int N, S;
	int num;
	char c;
	scanf("%d %d", &N, &S);
	int arr[1000][3];
	for(int i=0;i<S;i++)
		for (int j = 0; j < 2; )
		{
			while (1)
			{
				scanf("%d", &num);
				c = getchar();
				arr[i][j++] = num;
				if (c == '\n' || j == 2)
					break;
			}
		}
	for (int i = 0; i < S; i++)
	{
		printf("%d\n", ((turn(N, arr[i][0], arr[i][1]) + 1) + arr[i][0] - 2) % N + 1);
	}
	return 0;
}