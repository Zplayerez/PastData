//题目描述
//一个刚出锅的山芋，在围成一圈的n（以编号1，2，3...n分别表示 ）个孩子间传递。大家一起数数，从编号为1的孩子开始报数，每数一次，当前拿着山芋的孩子就把山芋交给紧邻其右的孩子。 一旦数到事先约定的某个数k ， 那个人就出列，他的下一个人又从1开始报数，数到数k的那个人就出列。如此反复，最后剩下的那个孩子就是幸运者。
//
//试实现算法josephus（int n, int k），输出孩子们出列的次序
//
//程序输入：n k
//
//程序输出：孩子们出列的次序
//
//
//
//样例输入输出
//样例1
//输入 :
//8 3
//输出 :
//	3->6->1->5->2->8->4->7

#include<iostream>
#include<queue>

using namespace std;

int main() {
	queue<int> result;

	int n, k;
	cin >> n >> k;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	int i = 0;
	int flag = 1, count = 0;
	while (count < n)
	{
		if (arr[i])
		{
			if (flag == k)
			{
				result.push(arr[i]);
				arr[i] = 0;
				count++;
			}
			i = (++i) % n;
			flag++;
			if (flag > k)
			{
				flag = 1;
			}
		}
		else i = (++i) % n;
	}

	int j = 0;
	while (!result.empty() && j < n - 1)
	{
		int a = result.front();
		result.pop();
		cout << a << "->";
		j++;
	}
	if (!result.empty())
	{
		int a = result.front();
		cout << a;
	}

	delete[] arr;

	return 0;
}

//#include<iostream>
//
//using namespace std;
//
//int main() {
//
//	int n, k;
//	cin >> n >> k;
//
//	int* arr = new int[n];
//
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = i + 1;
//	}
//
//	int count = 0;
//	int flag = 1;
//
//	int* result = new int[n];
//
//	int i = 0, j = 0;
//	while (count < n)
//	{
//		if (arr[i])
//		{
//			if (flag == k)
//			{
//				result[j] = arr[i];
//				arr[i] = 0;
//				j++;
//				count++;
//			}
//			i++;
//			flag++;
//			if (i >= n)
//				i = 0;
//			if (flag > k)
//				flag = 1;
//		}
//		else {
//			i++;
//			if (i >= n)
//				i = 0;
//		}
//	}
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		cout << result[i] << "->";
//	}
//	cout << result[n - 1];
//
//	delete[] arr;
//	delete[] result;
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> josephus(int n, int k) {
//    vector<int> result;
//    vector<int> people(n);
//
//    for (int i = 0; i < n; i++) {
//        people[i] = i + 1;
//    }
//
//    int currentIndex = 0;
//    for (int count = 0; count < n; count++) {
//        currentIndex = (currentIndex + k - 1) % people.size();
//        result.push_back(people[currentIndex]);
//        people.erase(people.begin() + currentIndex);
//    }
//
//    return result;
//}
//
//int main() {
//    int n, k;
//    cin >> n >> k;
//
//    vector<int> result = josephus(n, k);
//
//    for (size_t i = 0; i < result.size() - 1; i++) {
//        cout << result[i] << "->";
//    }
//    cout << result[result.size() - 1] << endl;
//
//    return 0;
//}
