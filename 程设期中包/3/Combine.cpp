#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)


void ShellSort(int data[], int count) {
	int step = 0;
	int auxiliary = 0;
	for (step = count / 2; step > 0; step /= 2) {  // 从数组第step个元素开始
		for (int i = step; i < count; i++) {     // 每个元素与自己组内的数据进行直接插入排序
			if (data[i] < data[i - step]) {     // 插入排序的第一次判断
				auxiliary = data[i];           // 需要往前插入，对待插入数据进行缓存
				int j = i - step;
				while (j >= 0 && data[j] > auxiliary) { //对同组前面数据检测，若大则循环后移
					data[j + step] = data[j];
					j -= step;
				}
				data[j + step] = auxiliary;          // 插入数据
			}
		}
	}
}

int main()
{
	int n;
	int num;
	char c;
	scanf("%d", &n);
	int arr[5][22];
	for (int i = 0; i < n; i++)
	{
		int j;
		j = 0;
		while (1)
		{
			scanf("%d", &num);
			c = getchar();
			if (num != 0)
				arr[i][j++] = num;
			else if (num == 0 || j == 21)
			{
				arr[i][j] = 0;
				break;
			}
		}
		arr[i][j] = '\0';
	}
	int total[120];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (1)
		{
			if (arr[i][j] != 0)
			{
				total[count] = arr[i][j];
				count++;
			}
			else if (arr[i][j] == 0 || j == 21)
				break;
			j++;
		}
	}
	ShellSort(total, count);
	for (int i = 0; i < count - 1; i++)
		printf("%d,", total[i]);
	printf("%d", total[count - 1]);
	return 0;
}