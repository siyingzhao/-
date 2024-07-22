#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void max(char arr[500])
{
	char wordlist[500][50];
	int i, j, count;
	i = 0;
	j = 0;
	count = 0;
	while (1)
	{
		if (count == strlen(arr))
			break;
		if (arr[count] != ' ' && arr[count] != ','&&arr[count]!='.')
		{
			wordlist[i][j] = arr[count];
			j++;
			count++;
		}
		else 
		{
			wordlist[i][j] = '\0';
			i++;
			j = 0;
			count++;
		}
	}
	int length[500];
	for (int k = 0; k < i; k++)
		length[k] = strlen(wordlist[k]);
	int max;
	max = 0;
	for (int k = 0; k < i; k++)
	{
		if (max < length[k])
			max = length[k];
	}
	for (int k = 0; k < i; k++)
	{
		if (length[k] == max)
		{
			printf("%s", wordlist[k]);
			break;
		}
	}
}

int main()
{
	char arr[500] = "";
	fgets(arr, sizeof(arr), stdin);
	max(arr);
	return 0;
}