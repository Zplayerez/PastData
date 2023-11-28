//二元一次多项式的幂（大整数）
//题目描述
//给定一个常数项为0的二元一次多项式，求该多项式的幂。
//
//设未知数为x, y，输入为x和y的整数系数a, b以及整数幂n，输出形如以下样式
//
//求幂运算的结果，按照x的幂降序排列
//
//Input Format
//输入未知数整数系数 a, b(-1000 < a, b < 1000), n(2 < n < 20)
//
//	Output Format
//	幂运算的结果的多项式，按照x幂降序排列
//
//	Example
//	Input
//	99 100 15
//	Output
//	860058354641288524893953951499x15 + 13031187191534674619605362901500x14y + 92139707414891638724482363950000x13y2 + 403305116630838822699754455000000x12y3 + 1222136717063147947575013500000000x11y4 + 2715859371251439883500030000000000x10y5 + 4572153823655622699495000000000000x9y6 + 5937862108643665843500000000000000x8y7 + 5997840513781480650000000000000000x7y8 + 4712108147752005000000000000000000x6y9 + 2855823119849700000000000000000000x5y10 + 1311213553650000000000000000000000x4y11 + 441486045000000000000000000000000x3y12 + 102910500000000000000000000000000x2y13 + 14850000000000000000000000000000xy14 + 1000000000000000000000000000000y15
//	说明
//	幂为1时不输出 ^ 1
//	系数为1时不输出系数， - 1只输出负号。

#include<iostream>
#include<queue>
#include<string>
#include<string.h>
using namespace std;

//将数字的非符号部分存入字符串 
string getNum(const string& s) {
	int t = s.size();
	string str = "";
	if (s[0] == '-')
	{
		for (int i = 1; i < t; i++)
			str += s[i];
	}
	else
	{
		for (int i = 0; i < t; i++)
			str += s[i];
	}
	return str;
}

//乘法，逐位计算，将结果存入数组再转为字符串 
string multi(const string& a, const string& b)
{
	int len1, len2;
	int isNeg = 0;
	if (((a[0] == '-' && b[0] != '-') || (a[0] != '-' && b[0] == '-')) && (a != "0" && b != "0")) isNeg = 1;
	string num1 = getNum(a);
	string num2 = getNum(b);
	len1 = num1.size();
	len2 = num2.size();

	int* res = new int[len1 + len2];
	memset(res, 0, sizeof(int) * (len1 + len2));


	for (int i = len1 - 1; i >= 0; --i)
	{
		for (int j = len2 - 1; j >= 0; --j) {
			res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
		}
	}
	for (int i = len1 + len2 - 1; i >= 0; --i)
	{
		if (res[i] >= 10) {
			res[i - 1] += res[i] / 10;
			res[i] %= 10;
		}
	}
	string ans = "";
	for (int i = 0; i < len1 + len2; ++i) ans += res[i] + '0';
	if (isNeg) ans = '-' + ans;
	return ans;
}

//加法 
string plusNum(const string& num1, const string& num2)
{
	int len1 = num1.size(), len2 = num2.size();
	int len = max(len1, len2) + 1;
	int length = len;
	string ans = "";
	int* res = new int[length];
	memset(res, 0, sizeof(int) * length);

	while (len1 > 0 && len2 > 0)
	{
		res[len - 1] = (num1[len1 - 1] - '0') + (num2[len2 - 1] - '0');
		len1--;
		len2--;
		len--;
	}
	while (len1 > 0)
	{
		res[len - 1] = (num1[len1 - 1] - '0');
		len1--;
		len--;
	}
	while (len2 > 0)
	{
		res[len - 1] = (num2[len2 - 1] - '0');
		len2--;
		len--;
	}
	for (int i = length - 1; i >= 0; --i)
	{
		if (res[i] >= 10)
		{
			res[i - 1] += res[i] / 10;
			res[i] %= 10;
		}
	}

	int k;
	for (k = 0; k < length; k++)
		if (res[k] != 0)break;
	if (k == length)ans = "0";
	else
	{
		for (int i = k; i < length; i++)
			ans += res[i] + '0';
	}
	return ans;
}

//减法 
string minusNum(string& num1, string& num2)
{
	int len1 = num1.size();
	int len2 = num2.size();
	int len;
	if (len1 >= len2)
	{
		for (int i = 1; i <= len1 - len2; i++)
			num2 = '0' + num2;
		len = len1;
	}
	if (len2 > len1)
	{
		for (int i = 1; i <= len2 - len1; i++)
			num1 = '0' + num1;
		len = len2;
	}

	int* num_a = new int[len];
	int* num_b = new int[len];
	for (int i = 0; i < len; ++i)
	{
		num_a[i] = num1[i] - '0';
		num_b[i] = num2[i] - '0';
	}
	int q = 0;//记录退位 
	for (int i = len - 1; i >= 0; --i)
	{
		num_a[i] -= q;
		if (num_a[i] < num_b[i]) {
			num_a[i] += 10;
			q = 1;
		}
		num_b[i] = num_a[i] - num_b[i];
	}

	int k;
	string ans = "";
	for (k = 0; k < len; k++)
		if (num_b[k] != 0)break;
	if (k == len)ans = "0";
	else
	{
		for (int i = k; i < len; i++)
			ans += num_b[i] + '0';
	}
	return ans;
}

//判断两数相减结果是否为非负 
bool isPos(const string& str1, const string str2)
{
	if (str1.size() > str2.size())
		return true;
	if (str1.size() == str2.size())
		return str1 > str2;
	return false;
}

//计算系数 
void powerFun(queue<string>& q, int n, const string& a, const string& b)
{
	string t = "0";
	string s;
	string num1, num2;
	string ans;
	for (int i = 2; i <= n; i++)
	{
		q.push(to_string(0));
		for (int j = 1; j <= i + 1; j++)
		{
			s = q.front();
			q.pop();

			num1 = multi(t, b);
			num2 = multi(s, a);
			if (num1[0] != '-' && num2[0] != '-')
				ans = plusNum(num1, num2);
			else if (num1[0] == '-' && num2[0] == '-')
			{
				ans = plusNum(getNum(num1), getNum(num2));
				ans = '-' + ans;
			}
			if (num1[0] == '-' && num2[0] != '-')
			{
				num1 = getNum(num1);
				if (isPos(num2, num1))
				{
					ans = minusNum(num2, num1);
				}
				else
				{
					ans = '-' + minusNum(num1, num2);
				}
			}
			if (num1[0] != '-' && num2[0] == '-')
			{
				num2 = getNum(num2);
				if (isPos(num1, num2))
				{
					ans = minusNum(num1, num2);
				}
				else
				{
					ans = '-' + minusNum(num2, num1);
				}
			}
			q.push(ans);
			t = s;
		}
	}
}

//表达式输出处理 
void showRes(queue<string>& q, int n)
{
	int k = n;
	int flag = 1;
	while (!q.empty())
	{
		if (q.front() == "0")
		{
			q.pop();
			k--;
			flag = 0;
			continue;
		}
		else if (q.front() == "1")
		{
			if (flag != 0 && k < n)cout << '+';
			flag = 1;
		}
		else if (q.front()[0] != '-')
		{
			if (k < n)cout << '+';
			cout << q.front();
		}
		else if (q.front() == "-1") cout << '-';
		else if (q.front()[0] == '-') cout << q.front();

		if (k == 1) cout << 'x';
		else if (k != 0) cout << "x^" << k;
		if (k == n - 1) cout << 'y';
		else if (k != n) cout << "y^" << n - k;

		q.pop();
		k--;
	}
	cout << endl;
}



int main()
{
	int a, b, n;
	cin >> a >> b >> n;
	queue<string>q;
	string str1 = to_string(a);
	string str2 = to_string(b);
	q.push(str1);
	q.push(str2);
	powerFun(q, n, str1, str2);
	showRes(q, n);
	return 0;
}
