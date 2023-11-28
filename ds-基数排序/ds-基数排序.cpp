//题目描述
//根据输入，输出基数排序的每趟排序结果。
//
//输入格式：输入数字为正整数，先输入排序数字个数，然后输入需要排序的数字序列。
//
//输出格式：每趟排序结果。行尾无空格。
//
//要求：程序需要实现排序，其他可以使用STL包。
//
//
//
//样例输入输出
//样例1
//输入 :
//8
//2343
//6
//66
//152310
//5594
//592783
//27
//8
//输出:
//152310 2343 592783 5594 6 66 27 8
//6 8 152310 27 2343 66 592783 5594
//6 8 27 66 152310 2343 5594 592783
//6 8 27 66 152310 2343 592783 5594
//6 8 27 66 2343 5594 152310 592783
//6 8 27 66 2343 5594 152310 592783

#include<iostream>
#include <cmath>

using namespace std;

int getDigit(int number, int digit) {
    while (digit > 0) {
        number /= 10;
        digit--;
    }
    return number % 10;
}

void bubbleSort(int* arr1, int* arr2, int n) {
	
	bool swapped;

	for (int i = 0; i < n - 1; i++) {
		swapped = false;

		for (int j = 0; j < n - i - 1; j++) {
			if (arr2[j] > arr2[j + 1]) {
				// 交换 arr[j] 和 arr[j+1]
				swap(arr2[j], arr2[j + 1]);
				swap(arr1[j], arr1[j + 1]);
				swapped = true;
			}
		}

		// 如果在一趟中没有发生任何交换，说明数组已经有序，可以提前退出
		if (!swapped) {
			break;
		}
	}
}

int main() {
	
	int n, maxDigit = 0;
	cin >> n;
	int* arr1 = new int[n];
	int* arr2 = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	for (int i = 0; i < n; i++)
	{
		int k = 1;
		while (arr1[i] / (int)pow(10, k)) {//pow返回的是一个浮点数
			k++;
		}
		maxDigit = maxDigit > k ? maxDigit : k;
	}

	for (int i = 0; i < maxDigit; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr2[j] = getDigit(arr1[j], i);
		}

		bubbleSort(arr1, arr2, n);

		for (int i = 0; i < n - 1; i++)
		{
			cout << arr1[i] << " ";
		}
		cout << arr1[n - 1] << endl;
	}

	delete[] arr1;
	delete[] arr2;

	return 0;
}