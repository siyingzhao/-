#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	char orikey[500] = "";
	char image[500] = "";
	int numori;
	scanf("%s %s", orikey, image);
	numori = strlen(orikey);
	char finkey[50];
	finkey[0] = orikey[0];
	int fincount = 1;
	for (int i = 1; i < numori; i++)
	{
		int flag;
		flag = 0;
		for (int j = 0; j < i; j++)
		{
			if (finkey[j] == orikey[i])
				flag = 1;
		}
		if (flag == 0)
		{
			finkey[fincount] = orikey[i];
			fincount++;
		}
	}
	finkey[fincount] = '\0';

	char alphabeta[26][2];
	for (int i = 0; i < 26; i++)
		alphabeta[i][0] = 'A' + i;
	for (int i = 0; i < fincount; i++)
		alphabeta[i][1] = finkey[i];
	char c = 'A';
	for (int i = fincount; i < 26; i++)
	{
		int fla = 0;
		for (int j = 0; j < fincount; j++)
		{
			if (alphabeta[j][1] == c)
				fla = 1;
		}
		if (fla == 0)
		{
			alphabeta[i][1] = c;
			c++;
		}
		else if (fla == 1)
		{
			c++;
			i--;
		}
	}

	for (int i = 0; i < strlen(image); i++)
	{
		if (i == strlen(image))
			break;
		for (int j = 0; j < 26; j++)
		{
			if (alphabeta[j][0] == image[i])
			{
				printf("%c", alphabeta[j][1]);
				break;
			}
			else if (j == 26)
				break;
		}
	}
	return 0;
 }