#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main()
{
	char a[101]="";
	char b[101] = "";
	char sum[102] = "";
	scanf("%s", &a);
	scanf("%s", &b);
	int na, nb;
	na = strlen(a);
	nb = strlen(b);
	int det;
	int temps;
	int flag;
	flag = 0;
	if (na >= nb)
	{
		det = na - nb;
		char b2[102] = "";
		for (int i = 0; i < det; i++)
			b2[i] = '0';
		for (int j = 0; j < nb; j++)
			b2[j + det] = b[j];
		for (int k = na - 1; k >= 1; k--)
		{
			if (flag == 1)
			{
				sum[k] = '1';
				flag = 0;
			}
			else sum[k] = '0';
			temps = (a[k] - '0') + (b2[k] - '0') + sum[k] - '0';
			if (temps < 10)
				sum[k] = temps + '0' ;
			else if (temps >= 10)
			{
				temps %= 10;
				sum[k] = temps + '0';
				flag = 1;
			}
		}
		if ((a[0] - '0') + (b2[0] - '0') + flag >= 10)
		{
			for (int i = na; i >= 2; i--)
				sum[i] = sum[i - 1];
			int finalsum = (a[0] - '0') + (b2[0] - '0') + flag;
			sum[1] = finalsum % 10 + '0';
			sum[0] = (finalsum - finalsum % 10) / 10 + '0';
		}
		else sum[0] = (a[0] - '0') + (b2[0] - '0') + flag + '0';
	}
	if (na < nb)
	{
		det = nb - na;
		char a2[102] = "";
		for (int i = 0; i < det; i++)
			a2[i] = '0';
		for (int j = 0; j < na; j++)
			a2[j + det] = a[j];
		for (int k = nb - 1; k >= 1; k--)
		{
			if (flag == 1)
			{
				sum[k] = '1';
				flag = 0;
			}
			else sum[k] = '0';
			temps = (b[k] - '0') + (a2[k] - '0') + sum[k] - '0';
			if (temps < 10)
				sum[k] = temps + '0';
			else if (temps >= 10)
			{
				temps %= 10;
				sum[k] = temps + '0';
				flag = 1;
			}
		}
		if ((b[0] - '0') + (a2[0] - '0') + flag >= 10)
		{
			for (int i = nb; i >= 2; i--)
				sum[i] = sum[i - 1];
			int finalsum = (b[0] - '0') + (a2[0] - '0') + flag;
			sum[1] = finalsum % 10 + '0';
			sum[0] = (finalsum - finalsum % 10) / 10 + '0';
		}
		else sum[0] = (b[0] - '0') + (a2[0] - '0') + flag + '0';
	}
	printf("%s", sum);
	return 0;
}