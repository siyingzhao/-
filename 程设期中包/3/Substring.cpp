#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	char str[300] = "";
	scanf("%s", str);
	int count, len;
	count = 0;
	len = strlen(str);
	for (int i = 0; i <= len - 3; i++)
		if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'a')
			count++;
	printf("%d", count);
	return 0;
}