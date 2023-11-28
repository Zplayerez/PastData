//#include<iostream>
//
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//
//	int* m = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> m[i];
//	}
//
//	int minPrice = m[0];
//	int maxEarn = 0;
//
//	for (int i = 1; i < n; i++)
//	{
//		minPrice = m[i] < minPrice ? m[i] : minPrice;
//
//		maxEarn = m[i] - minPrice > maxEarn ? m[i] - minPrice : maxEarn;
//	}
//
//	cout << maxEarn << endl;
//
//	delete[] m;
//	return 0;
//}

//��Ŀ����
//����һ��������Ӣ�Ĵ�Сд��ĸ���ַ������� s���������������������ַ�������ͬһ����ĸ�Ĵ�Сд��ʽ�������Ϊ�����ַ�����
//
//������Ҫ���������ַ���ת��Ϊ�����ַ�����aaΪ���⣬aA��AaΪ�ǻ��⡣
//
//�����ÿ�β������Դ��ַ�����ѡ�������������������������ַ���ɾ����ֱ���ַ��������Ϊֹ��
//
//ע�������ս��Ϊ���ַ���������� - 1��
//
//Ҫ��ʱ�临�Ӷ�O(n)
//
//Input Format
//������һ���ַ�����ɡ�����������֤��Ψһ��
//
//Output Format
//���һ�У�Ϊ�����ַ����������ɴ�ɾ�������õ��Ļ����ַ�����
//
//Example
//Input
//abBAcCc
//
//Output
//c
//
//˵��
//���������ڶ���ת��·���������������ͬ
//
//"abBAcCc" -- > "aAcCc" -- > "cCc" -- > "c"
//
//"abBAcCc" -- > "abBAc" -- > "aAc" -- > "c"
//
//
//
//�����������
//����1
//���� :
//abBAcCc
//��� :
//c
//����2
//���� :
//AaBbCcDd
//��� :
//-1

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string transformToMutexString(string s) {
    stack<char> st;

    for (char c : s) {
        if (!st.empty() && abs(st.top() - c) == 32) {
            st.pop();
        }
        else {
            st.push(c);
        }
    }

    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result.empty() ? "-1" : result;
}

int main() {
    string s;
    cin >> s;

    string mutexString = transformToMutexString(s);
    cout << mutexString << endl;

    return 0;
}