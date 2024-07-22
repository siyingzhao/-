#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void selectSort(int Data[], int count) {
	int i, j, index, temp;
	for (i = count - 1; i > 0; i--) { // 从后往前
		index = i;
		for (j = 0; j < i + 1; j++) { // 遍历前面未排序，选择最大元素
			if (Data[j] > Data[index]) index = j;
		}
		if (index != i) {              // 交换
			temp = Data[i];
			Data[i] = Data[index];
			Data[index] = temp;
		}
	}
}

int sum(int arr[],int n)
{
	int sum;
	sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

int main()
{
	int m, n;
	int num;
	char c;
	scanf("%d %d", &m, &n);
	if (m > 0 && m <= 20 && n > 0 && n <= 20)
	{
		int ori[21][21];
		for(int i=0;i<m;i++)
			for (int j = 0; j < n;)
			{
				while (1)
				{
					scanf("%d", &num);
					c = getchar();
					ori[i][j++] = num;
					if (c == '\n' || j == n)
						break;
				}
			}
		for (int i = 0; i < m; i++)
			selectSort(ori[i], n);
		int sumarr[21];
		for (int i = 0; i < m; i++)
			sumarr[i] = sum(ori[i], n);
		selectSort(sumarr, m);
		int fin[21][21];
		int flag;
		flag = 0;
		for(int i=0;i<m;i++)
			for (int j = 0; j < m; j++)
			{
				if (sum(ori[j], n) == sumarr[i])
				{
					for (int k = 0; k < n; k++)
						fin[flag][k] = ori[j][k];
					flag++;
					break;
				}
			}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (j != n - 1)
					printf("%d ", fin[i][j]);
				else if (j == n - 1)
					printf("%d\n", fin[i][j]);
			}
	}
	else printf("error");
	return 0;
}