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
#pragma warning(disable:4996)

#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
using namespace std;

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

{
//fgets 是 C 标准库中的一个函数，定义在 stdio.h 头文件中。它用于从流中读取字符串，通常是从文件或标准输入读取。
//函数会从指定的流中读取字符，并将它们存储到一个字符串中，直到遇到换行符、到达文件末尾或者读取了指定数量的字符为止。

fgets(char *str, int n, FILE *stream);

str：指向存储读取字符串的字符数组的指针。
n：要读取的最大字符数，包括终止空字符（'\0'）。
stream：指向要读取的输入流的指针。一般为stdin

返回值：
成功时，返回 str 的指针。
失败或到达文件末尾时，返回 NULL。
示例代码：

if （fgets(buffer, sizeof(buffer), file) != NULL)
	...

}

{
	[^,],[^\n]表示截止到某个字符之前的所有字符构成字符串的代符
}

{
strcspn 是 C 标准库中的一个函数，用于计算字符串中从起始位置开始不包含指定字符集合的最大子串的长度。
它的函数原型在 string.h 头文件中定义，如下所示：

strcspn(const char *str1, const char *str2);

str1：要扫描的字符串。
str2：包含需要查找的字符集合。
返回值
strcspn 返回 str1 中第一个包含在 str2 中的字符的位置索引（从 0 开始）。
如果 str1 中没有包含 str2 中的任何字符，则返回 str1 的长度。

int main() {
    const char *str1 = "Hello, world!";
    const char *str2 = " ,!";
    size_t len = strcspn(str1, str2);
    printf("The length of the initial segment of str1 which consists only of characters not in str2 is: %zu\n", len);
    return 0;
}
在这个例子中，strcspn 函数计算 str1 中从起始位置开始不包含 str2 中任意字符的最大子串的长度。
字符串 str2 包含空格、逗号和感叹号字符。str1 中从起始位置开始，第一个不在 str2 中的字符是 'o'，它位于索引 5 处。因此，strcspn 返回 5。

输出结果将是：
strcspn 常用于需要查找字符串中某些字符位置的场景，例如：

从字符串中找到第一个空白字符的位置。
检查字符串中是否存在特定字符集，如数字或特殊符号。

一个应用：
str[strcspn(str, "\n")] = 0; 
}



{
strstr 

char *strstr(const char *haystack, const char *needle);
参数
haystack：要在其中进行查找的主字符串。
needle：要查找的子字符串。
返回值
如果找到子字符串 needle，strstr 返回一个指向 haystack 中第一个匹配位置的指针。
如果没有找到子字符串 needle，strstr 返回 NULL。

#include <stdio.h>
#include <string.h>

int main() {
    const char *haystack = "Hello, world!";
    const char *needle = "world";
    char *result = strstr(haystack, needle);

    if (result) {
        printf("Found '%s' in '%s' at position %ld.\n", needle, haystack, result - haystack);
    } else {
        printf("Did not find '%s' in '%s'.\n", needle, haystack);
    }

    return 0;
}

Found 'world' in 'Hello, world!' at position 7.
这个示例展示了如何使用 strstr 函数在字符串中查找子字符串，并打印出子字符串首次出现的位置。
}