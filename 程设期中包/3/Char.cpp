#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	char str[202] = "";
	char c;
	int len = 0;
	int abc = 0;
	int space = 0;
	int number = 0;
	int others = 0;
	while (1)
	{
		scanf("%c", &c);
		str[len++] = c;
		if (c == '\n' || len == 201)
			break;
	}
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			printf("%c", str[i] + 'A' - 'a');
			abc++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			printf("%c", str[i] + 'a' - 'A');
			abc++;
		}
		else if (str[i] == ' ')
		{
			printf("%c", str[i]);
			space++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			printf("%c", str[i]);
			number++;
		}
		else 
		{
			printf("%c", str[i]);
			others++;
		}
	}
	printf("%d\n", abc);
	printf("%d\n", space);
	printf("%d\n", number);
	printf("%d\n", others-1);
	return 0;
}