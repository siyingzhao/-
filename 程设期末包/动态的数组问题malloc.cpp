#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reversebubbleSort(int data[], int count) {
		int temp;
		int pass = 1; bool exchange = true;             // �ӵ�һ�˿�ʼ
		while (pass < count && exchange) {
			exchange = false;                 // ĳ���Ƿ��н����ı�־����ʼΪ�޽���
			for (int j = count - 1; j >= pass; j--) //�����Ԫ�ؿ�ʼ����һ��δ����Ԫ��
				if (data[j - 1] < data[j]) {              //����Ҫ�������û�Ԫ��          
					temp = data[j - 1];
					data[j - 1] = data[j];
					data[j] = temp;
					exchange = true;
				}
			pass++;
		}
	}

void bubbleSort(int data[], int count) {
		int temp;
		int pass = 1; bool exchange = true;             // �ӵ�һ�˿�ʼ
		while (pass < count && exchange) {
			exchange = false;                 // ĳ���Ƿ��н����ı�־����ʼΪ�޽���
			for (int j = count - 1; j >= pass; j--) //�����Ԫ�ؿ�ʼ����һ��δ����Ԫ��
				if (data[j - 1] > data[j]) {              //����Ҫ�������û�Ԫ��          
					temp = data[j - 1];
					data[j - 1] = data[j];
					data[j] = temp;
					exchange = true;
				}
			pass++;
		}
	}

int **InputArray(int* m, int* n) 
{
	scanf("%d %d",m,n);
	int **A;
	A=(int**)malloc(sizeof(int*)*(*m));
	for(int i=0;i<*m;i++)
	{
		A[i]=(int*)malloc(sizeof(int)*(*n));
	}
	
	for(int i=0;i<*m;i++)
		for(int j=0;j<*n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	return A;
}

void PrintArray(int m, int n, int **arr)
{
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
			if(j==n-1)
				printf("\n");
		}
}

void ZeroArray(int m, int n, int **arr, int r) 
{
	for(int i=0;i<n;i++)
	{
		arr[r][i]=0;
		arr[i][r]=0;
	}
}

int *FlattenArray(int m, int n, int **arr)
{
	int *vec;
	vec=(int*)malloc(sizeof(int)*(m*n));
	int count=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			vec[count++]=arr[i][j];
	return vec;
}

int *SortArray(int m, int n, int **arr) 
{
	int* vec;
	vec=FlattenArray(m,n,arr);
	reversebubbleSort(vec,m*n);
	int count=0;
	for(int i=0;i<m*n;i++)
	{
		if(vec[i]!=0)
			count=i;
		else 
			break;
	}
	count++;
	bubbleSort(vec,count);
	return vec;
}

int main()
{
	int m,n;
	int** arr=InputArray(&m,&n);
	int r;
	scanf("%d",&r);
	ZeroArray(m,n,arr,r);
	PrintArray(m,n,arr);
	int* vec=SortArray(m,n,arr);
	for(int i=0;i<m*n;i++)
		printf("%d ",vec[i]);
	system("pause");
	return 0;
}