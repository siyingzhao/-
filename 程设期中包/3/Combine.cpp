#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)


void ShellSort(int data[], int count) {
	int step = 0;
	int auxiliary = 0;
	for (step = count / 2; step > 0; step /= 2) {  // �������step��Ԫ�ؿ�ʼ
		for (int i = step; i < count; i++) {     // ÿ��Ԫ�����Լ����ڵ����ݽ���ֱ�Ӳ�������
			if (data[i] < data[i - step]) {     // ��������ĵ�һ���ж�
				auxiliary = data[i];           // ��Ҫ��ǰ���룬�Դ��������ݽ��л���
				int j = i - step;
				while (j >= 0 && data[j] > auxiliary) { //��ͬ��ǰ�����ݼ�⣬������ѭ������
					data[j + step] = data[j];
					j -= step;
				}
				data[j + step] = auxiliary;          // ��������
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