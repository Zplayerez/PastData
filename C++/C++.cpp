#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;

//设计一个Rational类，进行带分数的运算。要求：
//（1）包含两个整数成员变量表示分子和分母, ，且都为整数。
//（2）包含一个对所声明对象初始化的构造函数。不提供参数时，构造函数应提供默认值（分子默认为0，分母默认为1）。分数存放成简化形式，例如分数“2 / 4”应在对象中存放成分子1和分母2的形式。
//（3）采用成员函数的方式重载加法、减法运算符，采用友元函数的方式重载乘法和除法运算符，实现如下功能：
//a）两个Rational值相加，结果保存成简化形式并输出。
//b）两个Rational值相减，结果保存成简化形式并输出。
//c）两个Rational值相乘，结果保存成简化形式并输出。
//d）两个Rational值相除，结果保存成简化形式并输出。
//e）重载++运算符，实现对两个Rational值的自增操作，结果保存成简化形式并输出（1 / 2++的结果为3 / 2）。
//f）重载赋值运算符” = ”, 声明类对象Rational R1，R2; 将两个Rational值分子和分母颠倒位置后，赋值给R1和R2，并简化输出。（2 / 3 变为 3 / 2，如果分母是1，直接输出整数形式。）
//g）重载输出运算符 << ，按a / b形式打印Rational值，其中a为分子，b为分母。
//（4）按a / b形式打印Rational值，其中a为分子，b为分母，要求：
//a）若分子为0，则输出0；
//b）不考虑分母为0的情况；
//c）若分子分母绝对值相等，如 - 1 / 1, 1 / 1则需输出 - 1或1；
//d）假分数保持即可，如7 / 4无需写成1又3 / 4。

//class Rational{
//private:
//	int num, den;
//
//public:
//	// 辗转相除法求最大公约数
//	int gcd(int a, int b) {
//		if (a < 0) a = -a;
//		if (b < 0) b = -b;
//		return b == 0 ? a : gcd(b, a % b);
//	}
//
//	Rational() :num(0), den(1) {}
//
//	Rational(int a = 0, int b = 0) :num(a), den(b){
//		int g = gcd(a, b);
//		num = a / g;
//		den = b / g;
//		if (den < 0)
//		{
//			num = -num;
//			den = -den;
//		}
//	}
//
//	Rational operator+(const Rational &A) {
//		int a = num * A.den + den * A.num;
//		int b = A.den * den;
//		return Rational(a, b);
//	}
//
//	Rational operator-(const Rational& A) {
//		int a = num * A.den - den * A.num;
//		int b = A.den * den;
//		return Rational(a, b);
//	}
//
//	Rational operator*(const Rational& A) {
//		int a = A.num * num;
//		int b = A.den * den;
//		return Rational(a, b);
//	}
//
//	Rational operator/(const Rational& A) {
//		int a = num * A.den;
//		int b = den * A.num;
//		return Rational(a, b);
//	}
//
//	Rational& operator++() {
//		num = num + den;
//		return *this;
//	}
//
//	Rational operator++ (int) {
//		Rational temp = *this;
//		++(*this);
//		return temp;
//	}
//
//	Rational& operator--() {
//		num = num - den;
//		return *this;
//	}
//
//	Rational operator=(const Rational& A) {
//		num = A.num;
//		den = A.den;
//		return *this;
//	}
//
//	Rational operator%(const Rational& A) {
//		num = A.den;
//		den = A.num;
//		return *this;
//	}
//
//	void show() {
//		if (den == 1)
//		{
//			cout << num;
//		}
//		else cout << num << "/" << den;
//	}
//};
//
//int main() {
//	int num1, den1, num2, den2;
//	cin >> num1 >> den1 >> num2 >> den2;
//	Rational R1(num1, den1), R2(num2, den2);
//	Rational R(0, 1);
//	R = R1 + R2;
//	R.show();
//	cout << endl;
//	R = R1 - R2;
//	R.show();
//	cout << endl;
//	R = R1 * R2;
//	R.show();
//	cout << endl;
//	R = R1 / R2;
//	R.show();
//	cout << endl;
//	R = R1;
//	R++;
//	R.show();
//	cout << " ";
//	R = R2;
//	R++;
//	R.show();
//	cout << endl;
//	R1++;
//	R = R % R1;
//	R.show();
//	cout << " ";
//	R2++;
//	R = R % R2;
//	R.show();
//	return 0;
//}

//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//
//class Matrix {
//private:
//    int m, n; //矩阵维度（m行，n列）
//    int** pr; //矩阵二维数组指针
//public:
//    Matrix(int m, int n); //构造函数，即初始化m行n列的类型为int的二维数组，并且元素均为0
//    Matrix(const Matrix& other); //复制构造函数，注意实现深拷贝
//    ~Matrix(); //析构函数，释放二维数组空间
//
//    void setValue(int i, int j, int v); //给矩阵第i行第j列元素赋值为v
//    Matrix operator + (const Matrix& other); //矩阵加法    
//    Matrix operator - (const Matrix& other); //矩阵减法
//    Matrix operator * (const Matrix& other); //矩阵乘法，注意不是元素间相乘  
//    Matrix transpose(); //矩阵转置，注意保持原矩阵不变，将新的转置矩阵返回
//    bool operator==(const Matrix& other);
//    void show(ostream&); //输出矩阵
//};
//
//Matrix::Matrix(int m, int n) {
//    this->m = m;
//    this->n = n;
//
//    //分配内存空间
//    pr = new int* [m];
//    for (int i = 0; i < m; i++) {
//        pr[i] = new int[n];
//        //初始化矩阵元素为0
//        for (int j = 0; j < n; j++) {
//            pr[i][j] = 0;
//        }
//    }
//}
//
//Matrix::Matrix(const Matrix& other) {
//    m = other.m;
//    n = other.n;
//
//    //分配内存空间
//    pr = new int* [m];
//    for (int i = 0; i < m; i++) {
//        pr[i] = new int[n];
//        //复制矩阵元素
//        for (int j = 0; j < n; j++) {
//            pr[i][j] = other.pr[i][j];
//        }
//    }
//}
//
//Matrix::~Matrix() {
//    //释放内存空间
//    for (int i = 0; i < m; i++) {
//        delete[] pr[i];
//    }
//    delete[] pr;
//}
//
//void Matrix::setValue(int i, int j, int v) {
//    //检查i、j是否越界
//    if (i < 0 || i >= m || j < 0 || j >= n) {
//        cout << "Invalid index!" << endl;
//        return;
//    }
//    pr[i][j] = v;
//}
//
//Matrix Matrix::operator + (const Matrix& other) {
//    //检查两个矩阵的维度是否相等
//    if (m != other.m || n != other.n) {
//        return *this;
//    }
//
//    //创建新的矩阵并初始化元素为0
//    Matrix result(m, n);
//
//    //进行矩阵加法
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            result.pr[i][j] = pr[i][j] + other.pr[i][j];
//        }
//    }
//
//    return result;
//}
//
//Matrix Matrix::operator - (const Matrix& other) {
//    //检查两个矩阵的维度是否相等
//    if (m != other.m || n != other.n) {
//        return *this;
//    }
//    //创建新的矩阵并初始化元素为0
//    Matrix result(m, n);
//
//    //进行矩阵减法
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            result.pr[i][j] = pr[i][j] - other.pr[i][j];
//        }
//    }
//
//    return result;
//}
//
//Matrix Matrix::operator * (const Matrix& other) {
//    //检查两个矩阵的维度是否满足矩阵乘法的条件
//    if (n != other.m) {
//        return *this;
//    }
//    //创建新的矩阵并初始化元素为0
//    Matrix result(m, other.n);
//
//    //进行矩阵乘法
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < other.n; j++) {
//            for (int k = 0; k < n; k++) {
//                result.pr[i][j] += pr[i][k] * other.pr[k][j];
//            }
//        }
//    }
//
//    return result;
//}
//
//Matrix Matrix::transpose() {
//    //创建新的矩阵并初始化元素为0
//    Matrix result(n, m);
//    //进行矩阵转置
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            result.pr[j][i] = pr[i][j];
//        }
//    }
//
//    return result;
//}
//
//bool Matrix::operator==(const Matrix& other)
//{
//    if (this->m != other.m || this->n != other.n){
//        return false;
//    }
//    for (int i = 0; i < this->m; i++) {
//        for (int j = 0; j < this->n; j++) {
//            if (this->pr[i][j] != other.pr[i][j]) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//void Matrix::show(ostream& os) {
//    //按照格式输出矩阵元素
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            os << pr[i][j] << " ";
//        }
//        os << endl;
//    }
//}
//
////重载<<运算符，用于方便输出矩阵
//ostream& operator << (ostream& os, Matrix& mat) {
//    mat.show(os);
//    return os;
//}
//
//int main() {
//    int m1, n1, m2, n2;
//    cin >> m1 >> n1 >> m2 >> n2;
//    Matrix A(m1, n1);
//    for (int i = 0; i < m1; i++)
//    {
//        for (int j = 0; j < n1; j++)
//        {
//            int v;
//            cin >> v;
//            A.setValue(i, j, v);
//        }
//    }
//    Matrix B(m2, n2);
//    for (int i = 0; i < m2; i++)
//    {
//        for (int j = 0; j < n2; j++)
//        {
//            int v;
//            cin >> v;
//            B.setValue(i, j, v);
//        }
//    }
//
//    Matrix C = A + B;
//    if (C == A)
//    {
//        cout << "error" << endl;
//    }
//    else cout << C;
//
//    Matrix D = A - B;
//    if (D == A)
//    {
//        cout << "error" << endl;
//    }
//    else cout << D;
//
//    Matrix E = A * B;
//    if (E == A)
//    {
//        cout << "error" << endl;
//    }
//    else cout << E;
//
//    Matrix F = A.transpose();
//    cout << F;
//
//    return 0;
//}

//设计日期类Date和时间类Time，并以此两类为基类派生日期时间类DateTime，日期类包括年、月、日成员，时间类包括时、分、秒成员，日期时间类能够实现日期时间的求差、比较大小的功能。
//
//要求：
//
//1、重载 == 运算符，判断两个日期时间是否相等。
//
//2、重载<和>运算符，判断两个日期时间大小，规定：过去的时间比现在的时间小，比如2023 - 3 - 3 18:45 : 46 > 2022 - 7 - 8 19:54 : 56。
//
//3、重载减运算符 - ，可以对日期时间求差。
//
//4、假设每个月都是30天，不考虑闰年，不考虑公元前，24小时制，24点表示为0 : 0 : 0即可。
//
//4、输出格式为XX - XX - XX XX - XX - XX，日期和时间用空格隔开，内部用 - 隔开，如2019 - 1 - 8 18 : 12 : 0，其中秒不需要用”00“表示。

//#include<iostream>
//
//using namespace std;
//
//class Date {
//
//public:
//
//	long long year;
//	long long month;
//	long long day;
//
//	Date(long long a = 0, long long b = 0, long long c = 0) :year(a), month(b), day(c) {}
//
//};
//class Time {
//
//public:
//
//	long long hour;
//	long long minute;
//	long long second;
//
//	Time(long long a = 0, long long b = 0, long long c = 0) :hour(a), minute(b), second(c) {}
//
//};
//
//class DateTime :public Date, public Time {
//
//public:
//
//	DateTime(long long a, long long b, long long c, long long d, long long e, long long f) :Date(a, b, c), Time(d, e, f) {}
//	
//	DateTime operator=(const DateTime& other) {
//		this->year = other.year;
//		this->month = other.month;
//		this->day = other.day;
//		this->hour = other.hour;
//		this->minute = other.minute;
//		this->second = other.second;
//		return *this;
//	}
//
//	bool operator==(const DateTime& other) {
//		if (this->year == other.year && this->month == other.month && this->day == other.day && this->hour == other.hour && this->minute == other.minute && this->second == other.second)
//			return true;
//		else return false;
//	}
//
//	bool operator >(const DateTime& other) {
//		if (this->second + this->minute * 100 + this->hour * 10000 + this->day * 1000000 + this->month * 100000000 + this->year * 10000000000 > other.second + other.minute * 100 + other.hour * 10000 + other.day * 1000000 + other.month * 100000000 + other.year * 10000000000)
//			return true;
//		else return false;
//	}
//
//	bool operator <(const DateTime& other) {
//		if (this->second + this->minute * 100 + this->hour * 10000 + this->day * 1000000 + this->month * 100000000 + this->year * 10000000000 < other.second + other.minute * 100 + other.hour * 10000 + other.day * 1000000 + other.month * 100000000 + other.year * 10000000000)
//			return true;
//		else return false;
//	}
//
//	DateTime operator-(const DateTime& other) {
//		if (this->second - other.second >= 0) {
//			this->second = this->second - other.second;
//		}
//		else {
//			this->second = 60 + this->second - other.second;
//			this->minute -= 1;
//		}
//
//		if (this->minute < 0) {
//			this->minute = 60 + this->minute;
//			this->hour -= 1;
//		}
//
//		if (this->minute - other.minute >= 0) {
//			this->minute = this->minute - other.minute;
//		}
//		else {
//			this->minute = 60 + this->minute - other.minute;
//			this->hour -= 1;
//		}
//
//		if (this->hour < 0)
//		{
//			this->hour = 24 + this->hour;
//		}
//
//		if (this->hour - other.hour >= 0) {
//			this->hour = this->hour - other.hour;
//		}
//		else {
//			this->hour = 24 + this->hour - other.hour;
//			this->day -= 1;
//		}
//
//		if (this->day < 0) {
//			this->day = 30 + this->day;
//			this->month -= 1;
//		}
//
//		if (this->day - other.day >= 0) {
//			this->day = this->day - other.day;
//		}
//		else {
//			this->day = 30 + this->day - other.day;
//			this->month -= 1;
//		}
//
//		if (this->month < 0){
//			this->month = 12 + this->month;
//			this->year -= 1;
//		}
//
//		if (this->month - other.month >= 0) {
//			this->month = this->month - other.month;
//		}
//		else {
//			this->month = 12 + this->month - other.month;
//			this->year -= 1;
//		}
//
//		if (this->year - other.year >= 0) {
//			this->year = this->year - other.year;
//		}
//
//		return *this;
//	}
//
//	void show() {
//		cout << year << '-' << month << '-' << day << ' ' << hour << ':' << minute << ':' << second;
//	}
//};
//
//int main() {
//
//	int a1, b1, c1, d1, e1, f1, a2, b2, c2, d2, e2, f2;
//	cin >> a1 >> b1 >> c1 >> d1 >> e1 >> f1 >> a2 >> b2 >> c2 >> d2 >> e2 >> f2;
//	DateTime dt1(a1, b1, c1, d1, e1, f1), dt2(a2, b2, c2, d2, e2, f2);
//	dt1.show();
//	cout << endl;
//	dt2.show();
//	cout << endl;
//
//	if (dt1 == dt2) cout << "dt1 == dt2 : " << "true";
//	else cout << "dt1 == dt2 : " << "false";
//	cout << endl;
//
//	if (dt1 > dt2) cout << "dt1 > dt2 : " << "true";
//	else cout << "dt1 > dt2 : " << "false";
//	cout << endl;
//
//	if (dt1 < dt2) cout << "dt1 < dt2 : " << "true";
//	else cout << "dt1 < dt2 : " << "false";
//	cout << endl;
//
//	DateTime temp(0, 0, 0, 0, 0, 0);
//	if (dt1 > dt2) {
//		temp = dt1 - dt2;
//		cout << "dt1 - dt2 : ";
//		temp.show();
//	}
//	else {
//		temp = dt2 - dt1;
//		cout << "dt2 - dt1 : ";
//		temp.show();
//	}
//
//	return 0;
//
//}

//题目描述
//设计一个简单的字符串类String，包含输入字符串、返回字符串内容及长度等功能；
//支持在指定位置插入insert、删除erase、替换字符replace。其中三个功能函数返回值为引用类型，即String& (函数中可以return* this来返回)
//假设程序有字符串为"1234567890"，位置计数从1开始；
//插入指令形如：i 1 a，表示操作为插入（insert），插入的位置为第1位，插入的字符为a；
//删除指令形如：d 2，表示操作为删除（delete），删除的位置为第2位；
//替换指令形如：r 6 b，表示操作为替换（replace），替换的位置为第6位，将第6位的字符替换为b；
//退出指令形如：q，表示程序结束。
//输入格式：
//每一行：输入形如题目的指令
//输出格式：
//输出单条指令执行后的新字符串。

//题目描述
//给定一个基类为Number类，两个派生类分别为整数Int类和分数Decimal类，请你声明add虚函数，并分别在两个派生类中继承，完成对任意两个非负整数和非负分数的相加计算。
//
//注意：
//
//1.所有的小数输入均为XXX.XXX形式
//
//2.当整数非常大时，会出现溢出问题。当小数位数非常多时，会出现精度不够问题。因此，你可以使用字符串形式表示整数和小数。

#include<iostream>

#include<string>

using namespace std;

class Number {
public:
	string Num;
	Number() {};

	virtual void add() {};

};

class Int :public Number {
public:
	Int(string str) {
		Num = str;
	}

	string add(Int& num1, Int& num2) {

		int len1 = num1.Num.length();
		int len2 = num2.Num.length();
		bool flag = false;

		string result;

		int i = num1.Num.length() - 1;
		int j = num2.Num.length() - 1;

		for (; i >= 0 && j >= 0; i--, j--)
		{
			int sum = num1.Num[i] + num2.Num[j];
			if (flag)
			{
				sum += 1;
				flag = false;
			}
			if (sum >= 10)
			{
				sum = sum % 10;
				flag = true;
			}
			result.push_back(sum + '0');
		}

		for (; i >= 0; --i)
		{
			int sum = num1.Num[i] - '0';
			if (flag)
			{
				sum += 1;
				flag = false;
			}
			if (sum >= 10)
			{
				sum = sum % 10;
				flag = true;
			}
			result.push_back(sum + '0');
		}
		for (; j >= 0; --j)
		{
			int sum = num2.Num[j] - '0';
			if (flag)
			{
				sum += 1;
				flag = false;
			}
			if (sum >= 10)
			{
				sum = sum % 10;
				flag = true;
			}
			result.push_back(sum + '0');
		}

		if (flag)
		{
			result.push_back('1');
		}
		i = 0;
		j = result.length() - 1;
		while (i < j)
		{
			char ch = result[i];
			result[i++] = result[j];
			result[j--] = ch;
		}
		
		return result;
	}
};

class Decimal :public Number {

};

int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	Int n1(s1), n2(s2), n("0");
	cout << n.add(n1, n2) << endl;
}