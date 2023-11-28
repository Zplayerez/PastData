//��Ŀ����
//��֪˳��洢�����Ա����δ�������ֱ��С�������Ա���a1...an)(b1....bm)����ai >= ai - 1, bj >= bj - 1(1 < i <= n, 1 < j <= m)��������㷨�ϲ���Ϊһ���ǽ������Ա�Ҫ�����洢�ռ临�Ӷ�ΪO(1)���Է����㷨��ʱ�临�Ӷȡ�
//
//	���룺�������Ա���n, m, n + m���ֱ������������
//
//	������ǽ������С�
//
//
//
//
//
//	�����������
//	����1
//	���� :
//3 5
//1 5 8 3 4 7 9 11
//��� :
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

	int i = n - 1; // ָ��a��ĩβ
	int j = m - 1; // ָ��b��ĩβ
	int k = n + m - 1; // ָ��ϲ���������ĩβ

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