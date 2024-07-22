#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	int final;
	char words[100][100];
	char END[4] = { 'e','n','d','\0' };
	int i, j;
	char ch;
	i = 0;
	j = 0;
	
	while ((ch = getchar() )!= '\n')
	{
		if (ch == ' ' || ch == '\t')
		{
			words[i][j] = '\0';
			i++;
			j = 0;
		}
		else
		{
			words[i][j] = ch;
			j++;
		}
	}
	words[i][j] = '\0'; 

	int number[100];
	final = 0;
	for (int y = 0; y <= i; )
	{
		if (strcmp(words[y], END) == 0)
		{
			final = y;
			break;
		}
		else
			y++;
	}

	for (int k = 0; k <= final; k++)
	{
		int count;
		count = 1;
		for (int p = k + 1; p <= final; p++)
		{
			if (strcmp(words[k], words[p]) == 0)
				count++;
		}
		number[k] = count;
	}

	int max;
	max = 0;
	for (int x = 0; x <= final; x++)
	{
		if (max < number[x])
			max = number[x];
	}

	for (int q = 0; q <= final; q++)
	{
		if (number[q] == max&&strcmp(words[q],END)!=0)
		{
			printf("%s", words[q]);
			printf(" %d\n", max);
		}
	}
	return 0;
}
	
