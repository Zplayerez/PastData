//题目描述
//根据KMP算法的next数组值，推断模式字符串。
//
//假设模式字符串中只存在0，1两种字符。给出首字符和next数组。请输出模式字符串。如果next数组不合法则输出ERROR
//
//Input Format
//先输入模式字符串首字符0或者1，然后输入尾字符0或者1
//
//再输入 模式字符串长度n，n <= 30
//
//最后输入n个以 - 1，0，起始的整数。
//
//Output Format
//
//模式字符串 或者 ERROR
//
//Example
//Input
//1 0 10
//
//- 1 0 1 2 3 4 0 1 2 3
//
//Output
//1111101110
//
//Input
//1 1 6
//
//- 1 0 0 0 0 0
//
//Output
//100001
//
//Input
//1 1 6
//
//- 1 0 2 0 0 0
//
//Output
//ERROR
//
//说明
//以传统未优化的KMP算法推导的next数组。
//
//
//
//样例输入输出
//样例1
//输入 :
//1 1 6
//
//- 1 0 0 0 0 0
//输出 :
//	100001
//	样例2
//	输入 :
//1 1 6
//- 1 0 2 0 0 0
//输出 :
//	ERROR
//	样例3
//	输入 :
//1 1 7
//- 1 0 1 2 3 4 2
//输出 :
//	ERROR

#include <iostream>
using namespace std;

int kmp(int* next, int f, int l, int n)
{
	int arr;
	int* temp = new int[n];
	temp[0] = f;
	for (int i = 2; i < n; i++)
	{
		if (next[i] == 0)//最大匹配长度为0 
		{
			if (f == 1) arr = 0;//当前字符的前一个字符与首字符相异 
			else arr = 1;
		}
		else
		{
			if (next[i] >= i || (i != next[i] + 1 && temp[i - next[i] - 1] == temp[0])) //错误：最大匹配长度过长或字符不匹配时不能回溯到正确位置  
			{
				cout << "ERROR" << endl;
				return 0;
			}
			arr = temp[next[i] - 1];
		}
		temp[i - 1] = arr;
	}
	for (int i = 0; i < n - 1; i++)
	{
		cout << temp[i];
	}
	cout << l;
	cout << endl;
	return 0;
}
int main()
{
	int f, l, n;
	cin >> f >> l >> n;
	int* next = new int[n];
	for (int i = 0; i < n; i++)
		cin >> next[i];
	kmp(next, f, l, n);
	return 0;
}