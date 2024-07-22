#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int n, a, count;
	count = 0;
	int arr[100];
	scanf("%d %d", &n, &a);
	for (; n != 0;)
	{
		count++;
		arr[count - 1] = n % a;
		n = n - n % a;
		n /= a;
	}
	for (; count > 0; count--)
		printf("%d", arr[count - 1]);
	return 0;
}