#include <stdio.h>
#include <stdlib.h>
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

int dele(int N,int arr[4])
{
	int  a, b, c, d;
	{
		d = N % 10;
		N -= d;
		N /= 10;
		c = N % 10;
		N -= c;
		N /= 10;
		b = N % 10;
		N -= b;
		N /= 10;
		a = N;
	}
	arr[0] = a; arr[1] = b; arr[2] = c; arr[3] = d;
	ShellSort(arr, 4);
	int max, min;
	a = arr[0]; b = arr[1]; c = arr[2]; d = arr[3];
	min = 1000 * a + 100 * b + 10 * c + d;
	max = 1000 * d + 100 * c + 10 * b + a;
	return (max - min);
}

int main()
{
	int N, flag, max, min;
	int arr[4];
	flag = 0;
	scanf("%d", &N);
	if (dele(N,arr) == 0)
	{
		printf("ERROR");
		return 0;
	}
	while (1)
	{
		if (flag != dele(N, arr))
		{
			min = 1000 * arr[0] + 100 * arr[1] + 10 * arr[2] + arr[3];
			max = 1000 * arr[3] + 100 * arr[2] + 10 * arr[1] + arr[0];
			flag = max - min;
			printf("(%d,%d,%d)\n", max, min, flag);
			N = flag;
		}
		else break;
	}
	return 0;
}