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

//题目描述
//给定一个仅含有英文大小写字母的字符串序列 s，若其中任意两个相邻字符都不是同一个字母的大小写形式，则称其为互斥字符串。
//
//程序需要将给定的字符串转换为互斥字符串。aa为互斥，aA和Aa为非互斥。
//
//程序的每次操作可以从字符串中选出满足上述条件的两个相邻字符并删除，直到字符串整理好为止。
//
//注：若最终结果为空字符串，请输出 - 1。
//
//要求时间复杂度O(n)
//
//Input Format
//输入由一行字符串组成。测试样例保证答案唯一。
//
//Output Format
//输出一行，为输入字符串经过若干次删除操作得到的互斥字符串。
//
//Example
//Input
//abBAcCc
//
//Output
//c
//
//说明
//该样例存在多种转换路径，但最终输出相同
//
//"abBAcCc" -- > "aAcCc" -- > "cCc" -- > "c"
//
//"abBAcCc" -- > "abBAc" -- > "aAc" -- > "c"
//
//
//
//样例输入输出
//样例1
//输入 :
//abBAcCc
//输出 :
//c
//样例2
//输入 :
//AaBbCcDd
//输出 :
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