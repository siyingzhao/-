#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

//计算一个正整十进制数n有多少位
int count(int n)
{
	int i = 1;
	for (; n >= 10; i++)
	{
		n = n - n % 10;
		n = n / 10;
	}
	return i;
}

//计算m的n次方，即m^n
float pow(float m,int n)
{
	float base;
	base = m;
	for (int i = 1; i < n; i++)
		base *= m;
	return base;
}

//输入一行数，中间用空格（或其他字符）隔开，最后回车，录入一维动态数组
{
	int N, i, num;
	char c;
	i = 0;
	countnum = 0;
	int* arr;
	scanf("%d", &N);//预定数组长度
	if ((arr = (int*)malloc(sizeof(int) * N)) == NULL)//创建动态数组
	{
		printf("Damn!\n");
		return -1;
	}
	//关键处理部分
	while (1)
	{
		scanf("%d", &num);
		c = getchar();
		arr[i++] = num;
		if (c == '\n')
			break;
	}
}

//各种排序算法
{
	//ShellSort 希尔排序
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

	//bubbleSort 冒泡排序
	void bubbleSort(int data[], int count) {
		int temp;
		int pass = 1; bool exchange = true;             // 从第一趟开始
		while (pass < count && exchange) {
			exchange = false;                 // 某趟是否有交换的标志，初始为无交换
			for (int j = count - 1; j >= pass; j--) //从最后元素开始到第一个未排序元素
				if (data[j - 1] > data[j]) {              //若需要交换则置换元素          
					temp = data[j - 1];
					data[j - 1] = data[j];
					data[j] = temp;
					exchange = true;
				}
			pass++;
		}
	}

	//insertSort 插入排序
	void insertSort(int data[], int l, int r) {
		int auxiliary = 0;
		for (int i = l + 1; i <= r; i++) {
			if (data[i] < data[i - 1]) {
				auxiliary = data[i];
				int j = i - 1;
				while (j >= l && data[j] > auxiliary) {
					data[j + 1] = data[j];
					j -= 1;
				}
				data[j + 1] = auxiliary;
			}
		}
	}

	//quickSort 快速排序
	void quickSort(int data[], int l, int r) {
		if (l < r) {
			int pivotL = l, pivotR = r, x = data[l];
			while (pivotL < pivotR) {
				while (pivotL<pivotR && data[pivotR]>x) pivotR--;
				//从右向左找第一个小于x的数  
				if (pivotL < pivotR) data[pivotL++] = data[pivotR];

				while (pivotL < pivotR && data[pivotL] < x) pivotL++;
				//从左向右找第一个大于等于x的数  
				if (pivotL < pivotR) data[pivotR--] = data[pivotL];
			}
			data[pivotL] = x;
			quickSort(data, l, pivotL - 1);   // 递归调用处理左子序列 
			quickSort(data, pivotL + 1, r);   // 递归调用处理右子序列
		}
	}

	//selectSort 选择排序
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
}

//quickPower 快速幂，快速次方（涉及位运算）
int quickPower(int a, int b)//是求a的b次方
{
	int ans = 1, base = a;//ans为答案，base为a^(2^n)
	while (b > 0)//b是一个变化的二进制数，如果还没有用完
	{
		if (b & 1)//&是位运算，b&1表示b在二进制下最后一位是不是1，如果是：
			ans *= base;//把ans乘上对应的a^(2^n)

		base *= base;//base自乘，由a^(2^n)变成a^(2^(n+1))
		b >>= 1;//位运算，b右移一位，如101变成10（把最右边的1移掉了），10010变成1001。现在b在二进制下最后一位是刚刚的倒数第二位。结合上面b & 1食用更佳
	}
	return ans;
}

//Floyd 寻路，最短路径问题
{
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (e[i][j] > e[i][k] + e[k][j])
				{
					e[i][j] = e[i][k] + e[k][j];
					p[i][j] = p[i][k];
				}
}

// 将两个正整数进行拼接
int concat(int a, int b) {
	// 将两个数转换为字符串
	char strA[20], strB[20];
	sprintf(strA, "%d", a);
	sprintf(strB, "%d", b);

	// 将字符串进行拼接
	strcat(strA, strB);

	// 将拼接后的字符串转换为整数并返回
	return atoi(strA);
}

//给任意一个正整数拆分成2的次方数的和
{
	int judge_mod(int n)
	{
		int i;
		i = 0;
		for (; n % 2 == 0; i++)
			n /= 2;
		return (pow(2, i));
	}

	int main()
	{
		unsigned int k;
		scanf("%u", &k);

		for (; k != 0;)
		{
			if (k % 2 == 1)
			{
				k = k - 1;
				printf("%u ", 1);
			}
			else
			{
				printf("%u ", judge_mod(k));
				k = k - judge_mod(k);
			}
		}

		return 0;
	}
}

//创建一个n*m的动态2维数组
{
	int n, m, num;
	char c;
	scanf("%d %d", &n, &m);
	//创建一个n*m的2维数组
	int** array = new int* [n];
	for (int i = 0; i < n; i++)
		array[i] = new int[m];
	//向数组中输入数据
	for (int i = 0; i <= n - 1; i++)
	{
		for (int k = 0; k <= m - 1;)
		{
			while (1)
			{
				scanf("%d", &num);
				c = getchar();
				array[i][k++] = num;
				if (c == '\n'||k==m)
					break;
			}
		}
	}
	//释放内存（勿忘）
	for (int i = 0; i < n; i++)
		delete[] array[i];
	delete[] array;

	return 0;
}

//寻找一个数组中出现最多的元素有多少个
int find_count(int arr[], int n)
{
	int count, temp;
	count = 0;
	ShellSort(arr, n);
	temp = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			temp++;
			if (count < temp)
				count = temp;
		}
		else if (arr[i] != arr[i + 1])
		{
			temp = 1;
			i = i + 1;
			if (count < temp)
				count = temp;
			continue;
		}
	}
	return count;
}

//连续输入一串数字，直到EOF(ctrl+z)
{
	int nExit, n;
	nExit = scanf("%d", &n);
	while (nExit != EOF)
	{
		......
        nExit = scanf("%d", &n);
	}

}

//输入空格间隔的一列单词，换行结尾
{ 
	while ((ch = getchar()) != '\n')
	{
		......
	}
}

/*字符串处理函数合集（勿忘先include string或string.h）
必须确保处理的是结尾包含'\0'的合法字符串*/
{
	char str[66]，str2[66];
	-gets(str) / 输入一个字符串到str中，会自动加‘\0’（因此输入长度要小于总长度）；
		/ 可以输入空格和TAB，但是不能输入回车；
		/ 返回值是str起始地址
	-puts(str) / 输出一个字符串，内容直到第一个遇到的\0，然后再自动输出一个换行
		/ 返回值表示输出字符的个数
		/ 可以输出转义字符
	-strcat(str, str2)/将str2连接到str后面，包括空格
		/保证str足够大
		/str2第一个元素会顶掉str最后的\0
	-strncat(str,str2,n)/防止前者不够大，str2取前n个元素接到str后面
	-strcpy(str,str2)/把str2复制到str中去
		/ “字符数组1”必须写成数组名形式(如str1)，“字符串2”可以是字符数组名，也可以是一个字符串常量。如strcpy(str1，′′China′′)；
		/ 复制时连同字符串后面的′\0′一起复制到字符数组1中。
	-strncpy(str,str2,n)/只复制str2前n个，复制完成后自动加\0
	-strcmp(str,str2)/ 函数值是比较的结果
		              •如果字符串1 = 字符串2，函数值为0。
		              •如果字符串1 > 字符串2，函数值为一正整数。
		              •如果字符串1 < 字符串2，函数值为一负整数。
		/ 字符串比较的规则是对两个字符串自左向右依次比较字符的ASCII数值，直到出现不同的字符或遇到空字符为止。
		/ 若全部字符相同，则认为字符串相等
		/ 若出现不同的字符则以第一个不相同的字符的比较结果为准。
		/ 一般地，数字字符小于字母、大写字母小于小写字母、英文小于汉字等
	-strlen(str)/ strlen是测试字符串长度的函数：从变量s扫描，直到碰到第一个'\0'为止，返回计数器值。
		/ 函数的值为字符串中的实际长度(不包括  ′＼0′在内)
		/区别于sizeof str【这个str无括号】，sizeof 为数组总共长度，如本例中为66
	-strlwr(str)/ 将字符串中大写字母换成小写字母
	-strupr(str)/ 将字符串中小写字母换成大写字母
	-atof(str)/ 返回对应的双精度浮点型值(对应double，lf)
	-atoi(str)/返回对应的整型值（对应int，d）
		/注意，atof、atoi均需要包括头文件<stdlib.h>
}

//创建动态结构体
{
	typedef struct cow
	{
		int x;
		int y;
		char dir;
		int respon;
		int hit;
	}my_cow;

	int num_cows;
	scanf("%d", &num_cows);
	my_cow* cows = (my_cow*)malloc(num_cows * sizeof(my_cow));
	for (int i = 0; i <= num_cows - 1; i++)
	{
		scanf(" %c %d %d", &cows[i].dir, &cows[i].x, &cows[i].y);
		cows[i].respon = 0;
		cows[i].hit = -1;
	}
	free(cows);//(释放动态内存)
}

//连续输入多个字符串，可含空格
for (int i = 0; i < num; i++)
{
	scanf("%[^\n]", a);
	getchar();//清除回车输入缓存
	printf("%s\n", a);
}

//最大位数的数据类型
unsigned long long int   2 ^ 64 - 1位

//总统选举排名题，很好的综合了输入、数据类型转换等内容，可以多看看
//大数用unsigned long long int，缩写%ull，大浮点数用long double（最长）
//输出打印%要用%%（连用）
{
	#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

void bubbleSort(unsigned long long int data[], int count) {
	unsigned long long int temp;
	int pass = 1; bool exchange = true;             // 从第一趟开始
	while (pass < count && exchange) {
		exchange = false;                 // 某趟是否有交换的标志，初始为无交换
		for (int j = count - 1; j >= pass; j--) //从最后元素开始到第一个未排序元素
			if (data[j - 1] > data[j]) {              //若需要交换则置换元素          
				temp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = temp;
				exchange = true;
			}
		pass++;
	}
}

int main()
{
	unsigned long long int numberori[12];
	unsigned long long int number[12];
	char name[12][22];
	int CandidateCount;
	scanf("%d", &CandidateCount);
	getchar();
	for (int i = 0; i < CandidateCount; i++)
	{
		scanf("%[^\n]", name[i]);
		getchar();
		scanf("%llu", &number[i]);
		getchar();
	}
	for (int i = 0; i < CandidateCount; i++)
		numberori[i] = number[i];
	bubbleSort(number, CandidateCount);
	long double rate[11];
	long double sum;
	sum = 0;
	for (int i = 0; i < CandidateCount; i++)
		sum += numberori[i];
	for (int i = 0; i < CandidateCount; i++)
		rate[i] = long double(100 * (long double(numberori[i]) / sum));
	int flag;
	for (int i = CandidateCount - 1; i >= 0; i--)
	{
		for (int k = 0; k < CandidateCount; k++)
			if (numberori[k] == number[i])
			{
				flag = k;
				break;
			}
		printf("%s\n", name[flag]);
		printf("%llu\n", number[i]);
		printf("%.2f%%\n",rate[flag]);
	}
	return 0;
}
}

//sprintf函数，将格式化后的数据按照指定的格式写入到字符串 str 中
{
	char buffer[50];
	int number = 123;
	float pi = 3.14159;
	sprintf(buffer, "Number: %d, Pi: %.2f", number, pi);
	printf("Formatted string: %s\n", buffer);
	return 0;
}

//str 是要分割的字符串，第一次调用时传入要分割的字符串，后续调用传入 NULL。
//delim 是分割符，即用于分割字符串的字符集合。（例子中是空格）
{
	char str[] = "The quick brown fox";
	const char delim[] = " ";

	// 第一次调用 strtok，传入要分割的字符串
	char* token = strtok(str, delim);

	// 循环调用 strtok，直到获取所有的子字符串
	while (token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, delim); // 后续调用传入 NULL
	}

	return 0;
}

//sscanf 函数是 C 标准库中的一个格式化输入函数，用于从字符串中读取数据并根据指定的格式进行解析。
{
	const char* str = "The temperature is 25.6 degrees Celsius";
	float temperature;

	// 使用 sscanf 从字符串中解析温度值
	int num_items = sscanf(str, "The temperature is %f degrees Celsius", &temperature);

	if (num_items == 1) {
		printf("Parsed temperature: %.1f\n", temperature);
	}
	else {
		printf("Failed to parse temperature\n");
	}

	return 0;
}

//n以内的素数（小于n）（最后一个输出是素数个数）（效率不是太高，1000左右就卡顿了）
{
	int count = 0;
	int a[1000];
	int i, j, n;
	a[0] = 0;
	a[1] = 0;
	scanf("%d", &n);
	for (i = 2; i < n; i++)
		a[i] = i;   //初始化
	//核心过程 sqrt((double)1000)也是借鉴了开根号的思想。
	for (i = 2; i < sqrt((double)n); i++)
		if ((a[i] != 0))
		{
			for (j = 2 * i; j < n; j += i)
				a[j] = 0;
		}
	//输出结果
	for (i = 2; i < n; i++)
		if (a[i]) {
			printf("%d\t", a[i]);
			count++;
		}
	printf("%d\t", count);

}

//大数乘法
{
	char num1[1000], num2[1000];
	int a[2000] = { 0 };
	int n, i, j, k, l1, l2;
	printf("please input two integers:\n");
	scanf("%s %s", num1, num2);
	printf("%s*%s=", num1, num2); //为了之后的输出
	l1 = strlen(num1);
	l2 = strlen(num2);
	/* 将字符转化为数字 */
	for (n = 0; n < l1; n++)
		num1[n] -= '0';
	for (n = 0; n < l2; n++)
		num2[n] -= '0';
	/* 第l1-1位*第l2-1位放在第0位(乘积最小的一位),第0位*第0位放在第l1-1+l2-1位(乘积最大的一位) */
	for (i = 0; i <= l1 - 1; i++)
		for (j = 0; j <= l2 - 1; j++)
			a[l1 - 1 - i + l2 - 1 - j] += num1[i] * num2[j];
	/* 从最小的一位开始——低位置为单位数，并将十位进到高位 */
	for (n = 0; n <= l1 + l2; n++)
	{
		a[n + 1] += a[n] / 10;
		a[n] %= 10;
	}
	/* 从最后往前找第一个非零位 */
	for (n = l1 + l2 + 1; a[n] == 0; n--)
		k = n;
	/* 从非零位的前一位开始打印 */
	for (n = k - 1; n >= 0; n--)
		printf("%d", a[n]);
	printf("\n");
	system("pause");
}

//大数加法
{
	char a[101] = "";
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
				sum[k] = temps + '0';
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

//gets函数和fgets函数
{
	char str[50];

	printf("Enter a string: ");
	gets(str); // 从标准输入获取字符串

	printf("You entered: %s\n", str);

	return 0;
}
{
	char str[50];

	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin); // 从标准输入获取一行字符串

	printf("You entered: %s\n", str);

	return 0;
}

//一个输入格式（九位小数）
 {
	double number;
	double* d_ptr = &number;

	// 从键盘读入一个小数，存储到双精度浮点数指针变量所指向的内存空间
	printf("Enter a decimal number: ");
	scanf("%lf", d_ptr);

	// 以科学计数法形式打印小数到屏幕上，小数点后保留9位数字
	printf("Scientific notation: %.9e\n", *d_ptr);

	return 0;
}

 //绝对值，浮点数和整数
#include <stdio.h>
#include <math.h>
 int main() {
	 double x = -3.14;
	 int y = -10;

	 // 计算浮点数的绝对值
	 double absolute_x = fabs(x);
	 printf("Absolute value of %.2f: %.2f\n", x, absolute_x);

	 // 计算整数的绝对值
	 int absolute_y = abs(y);
	 printf("Absolute value of %d: %d\n", y, absolute_y);

	 return 0;
 }

 //打印数组的阿斯克码
 int main() {
	 char array[] = "Hello";

	 printf("ASCII codes of array elements:\n");

	 for (int i = 0; array[i] != '\0'; ++i) {
		 printf("Element '%c' has ASCII code: %d\n", array[i], array[i]);
	 }

	 return 0;
 }

