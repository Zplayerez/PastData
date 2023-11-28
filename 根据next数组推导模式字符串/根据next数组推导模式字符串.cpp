//��Ŀ����
//����KMP�㷨��next����ֵ���ƶ�ģʽ�ַ�����
//
//����ģʽ�ַ�����ֻ����0��1�����ַ����������ַ���next���顣�����ģʽ�ַ��������next���鲻�Ϸ������ERROR
//
//Input Format
//������ģʽ�ַ������ַ�0����1��Ȼ������β�ַ�0����1
//
//������ ģʽ�ַ�������n��n <= 30
//
//�������n���� - 1��0����ʼ��������
//
//Output Format
//
//ģʽ�ַ��� ���� ERROR
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
//˵��
//�Դ�ͳδ�Ż���KMP�㷨�Ƶ���next���顣
//
//
//
//�����������
//����1
//���� :
//1 1 6
//
//- 1 0 0 0 0 0
//��� :
//	100001
//	����2
//	���� :
//1 1 6
//- 1 0 2 0 0 0
//��� :
//	ERROR
//	����3
//	���� :
//1 1 7
//- 1 0 1 2 3 4 2
//��� :
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
		if (next[i] == 0)//���ƥ�䳤��Ϊ0 
		{
			if (f == 1) arr = 0;//��ǰ�ַ���ǰһ���ַ������ַ����� 
			else arr = 1;
		}
		else
		{
			if (next[i] >= i || (i != next[i] + 1 && temp[i - next[i] - 1] == temp[0])) //�������ƥ�䳤�ȹ������ַ���ƥ��ʱ���ܻ��ݵ���ȷλ��  
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