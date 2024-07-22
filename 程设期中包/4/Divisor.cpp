#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int maxi(int a, int b)
{
	if (b > a)
	{
		int temp;
		temp = b;
		b = a;
		a = temp;
	}
	int m;
	while (1)
	{
		m = a % b;
		if (m == 0)
			break;
		else 
		{
			a = b;
			b = m;
		}
	}
	return b;
}

int main()
{
	int p, q, r, num, max, count;
	int arr[500];
	num = 0;
	max = 0;
	count = 0;
	while (1)
	{
		scanf("%d %d %d", &p, &q, &r);
		if (p * q * r == 0)
			break;
		if (p < 0 || q < 0 || r < 0)
			printf("error\n");
		arr[num] = maxi(maxi(p, q), r);
		num++;
	}
	for (int k = 0; k < num; k++)
		if (max < arr[k])
			max = arr[k];
	for (int k = 0; k < num; k++)
		if (arr[k] == max)
			count++;
	printf("%d %d", max, count);
	return 0;
}