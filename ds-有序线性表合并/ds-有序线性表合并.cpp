//题目描述
//已知顺序存储的线性表，依次存放两个分别大小有序线性表，（a1...an)(b1....bm)，即ai >= ai - 1, bj >= bj - 1(1 < i <= n, 1 < j <= m)尝试设计算法合并成为一个非降序线性表。要求辅助存储空间复杂度为O(1)。试分析算法的时间复杂度。
//
//	输入：有序线性表长度n, m, n + m个分别有序的整数。
//
//	输出：非降序序列。
//
//
//
//
//
//	样例输入输出
//	样例1
//	输入 :
//3 5
//1 5 8 3 4 7 9 11
//输出 :
//	1 3 4 5 7 8 9 11

#include<iostream>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int* arrN = new int[n];
	int* arrM = new int[m];
	int* arr = new int[m + n];

	for (int i = 0; i < n; i++)
	{
		cin >> arrN[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> arrM[i];
	}

	int i = n - 1; // 指向a的末尾
	int j = m - 1; // 指向b的末尾
	int k = n + m - 1; // 指向合并后的数组的末尾

	while (i >= 0 && j >= 0) {
		if (arrN[i] >= arrM[j]) {
			arr[k] = arrN[i];
			i--;
		}
		else {
			arr[k] = arrM[j];
			j--;
		}
		k--;
	}

	while (j >= 0) {
		arr[k] = arrM[j];
		j--;
		k--;
	}

	while (i >= 0) {
		arr[k] = arrN[i];
		i--;
		k--;
	}

	for (int i = 0; i < m + n - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << arr[m + n - 1];

	delete[] arrN;
	delete[] arrM;
	delete[] arr;

	return 0;
}