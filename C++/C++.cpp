#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;

//���һ��Rational�࣬���д����������㡣Ҫ��
//��1����������������Ա������ʾ���Ӻͷ�ĸ, ���Ҷ�Ϊ������
//��2������һ���������������ʼ���Ĺ��캯�������ṩ����ʱ�����캯��Ӧ�ṩĬ��ֵ������Ĭ��Ϊ0����ĸĬ��Ϊ1����������ųɼ���ʽ�����������2 / 4��Ӧ�ڶ����д�ųɷ���1�ͷ�ĸ2����ʽ��
//��3�����ó�Ա�����ķ�ʽ���ؼӷ��������������������Ԫ�����ķ�ʽ���س˷��ͳ����������ʵ�����¹��ܣ�
//a������Rationalֵ��ӣ��������ɼ���ʽ�������
//b������Rationalֵ������������ɼ���ʽ�������
//c������Rationalֵ��ˣ��������ɼ���ʽ�������
//d������Rationalֵ������������ɼ���ʽ�������
//e������++�������ʵ�ֶ�����Rationalֵ�������������������ɼ���ʽ�������1 / 2++�Ľ��Ϊ3 / 2����
//f�����ظ�ֵ������� = ��, ���������Rational R1��R2; ������Rationalֵ���Ӻͷ�ĸ�ߵ�λ�ú󣬸�ֵ��R1��R2�������������2 / 3 ��Ϊ 3 / 2�������ĸ��1��ֱ�����������ʽ����
//g�������������� << ����a / b��ʽ��ӡRationalֵ������aΪ���ӣ�bΪ��ĸ��
//��4����a / b��ʽ��ӡRationalֵ������aΪ���ӣ�bΪ��ĸ��Ҫ��
//a��������Ϊ0�������0��
//b�������Ƿ�ĸΪ0�������
//c�������ӷ�ĸ����ֵ��ȣ��� - 1 / 1, 1 / 1������� - 1��1��
//d���ٷ������ּ��ɣ���7 / 4����д��1��3 / 4��

//class Rational{
//private:
//	int num, den;
//
//public:
//	// շת����������Լ��
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
//    int m, n; //����ά�ȣ�m�У�n�У�
//    int** pr; //�����ά����ָ��
//public:
//    Matrix(int m, int n); //���캯��������ʼ��m��n�е�����Ϊint�Ķ�ά���飬����Ԫ�ؾ�Ϊ0
//    Matrix(const Matrix& other); //���ƹ��캯����ע��ʵ�����
//    ~Matrix(); //�����������ͷŶ�ά����ռ�
//
//    void setValue(int i, int j, int v); //�������i�е�j��Ԫ�ظ�ֵΪv
//    Matrix operator + (const Matrix& other); //����ӷ�    
//    Matrix operator - (const Matrix& other); //�������
//    Matrix operator * (const Matrix& other); //����˷���ע�ⲻ��Ԫ�ؼ����  
//    Matrix transpose(); //����ת�ã�ע�Ᵽ��ԭ���󲻱䣬���µ�ת�þ��󷵻�
//    bool operator==(const Matrix& other);
//    void show(ostream&); //�������
//};
//
//Matrix::Matrix(int m, int n) {
//    this->m = m;
//    this->n = n;
//
//    //�����ڴ�ռ�
//    pr = new int* [m];
//    for (int i = 0; i < m; i++) {
//        pr[i] = new int[n];
//        //��ʼ������Ԫ��Ϊ0
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
//    //�����ڴ�ռ�
//    pr = new int* [m];
//    for (int i = 0; i < m; i++) {
//        pr[i] = new int[n];
//        //���ƾ���Ԫ��
//        for (int j = 0; j < n; j++) {
//            pr[i][j] = other.pr[i][j];
//        }
//    }
//}
//
//Matrix::~Matrix() {
//    //�ͷ��ڴ�ռ�
//    for (int i = 0; i < m; i++) {
//        delete[] pr[i];
//    }
//    delete[] pr;
//}
//
//void Matrix::setValue(int i, int j, int v) {
//    //���i��j�Ƿ�Խ��
//    if (i < 0 || i >= m || j < 0 || j >= n) {
//        cout << "Invalid index!" << endl;
//        return;
//    }
//    pr[i][j] = v;
//}
//
//Matrix Matrix::operator + (const Matrix& other) {
//    //������������ά���Ƿ����
//    if (m != other.m || n != other.n) {
//        return *this;
//    }
//
//    //�����µľ��󲢳�ʼ��Ԫ��Ϊ0
//    Matrix result(m, n);
//
//    //���о���ӷ�
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
//    //������������ά���Ƿ����
//    if (m != other.m || n != other.n) {
//        return *this;
//    }
//    //�����µľ��󲢳�ʼ��Ԫ��Ϊ0
//    Matrix result(m, n);
//
//    //���о������
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
//    //������������ά���Ƿ��������˷�������
//    if (n != other.m) {
//        return *this;
//    }
//    //�����µľ��󲢳�ʼ��Ԫ��Ϊ0
//    Matrix result(m, other.n);
//
//    //���о���˷�
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
//    //�����µľ��󲢳�ʼ��Ԫ��Ϊ0
//    Matrix result(n, m);
//    //���о���ת��
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
//    //���ո�ʽ�������Ԫ��
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            os << pr[i][j] << " ";
//        }
//        os << endl;
//    }
//}
//
////����<<����������ڷ����������
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

//���������Date��ʱ����Time�����Դ�����Ϊ������������ʱ����DateTime������������ꡢ�¡��ճ�Ա��ʱ�������ʱ���֡����Ա������ʱ�����ܹ�ʵ������ʱ������Ƚϴ�С�Ĺ��ܡ�
//
//Ҫ��
//
//1������ == ��������ж���������ʱ���Ƿ���ȡ�
//
//2������<��>��������ж���������ʱ���С���涨����ȥ��ʱ������ڵ�ʱ��С������2023 - 3 - 3 18:45 : 46 > 2022 - 7 - 8 19:54 : 56��
//
//3�����ؼ������ - �����Զ�����ʱ����
//
//4������ÿ���¶���30�죬���������꣬�����ǹ�Ԫǰ��24Сʱ�ƣ�24���ʾΪ0 : 0 : 0���ɡ�
//
//4�������ʽΪXX - XX - XX XX - XX - XX�����ں�ʱ���ÿո�������ڲ��� - ��������2019 - 1 - 8 18 : 12 : 0�������벻��Ҫ�á�00����ʾ��

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

//��Ŀ����
//���һ���򵥵��ַ�����String�����������ַ����������ַ������ݼ����ȵȹ��ܣ�
//֧����ָ��λ�ò���insert��ɾ��erase���滻�ַ�replace�������������ܺ�������ֵΪ�������ͣ���String& (�����п���return* this������)
//����������ַ���Ϊ"1234567890"��λ�ü�����1��ʼ��
//����ָ�����磺i 1 a����ʾ����Ϊ���루insert���������λ��Ϊ��1λ��������ַ�Ϊa��
//ɾ��ָ�����磺d 2����ʾ����Ϊɾ����delete����ɾ����λ��Ϊ��2λ��
//�滻ָ�����磺r 6 b����ʾ����Ϊ�滻��replace�����滻��λ��Ϊ��6λ������6λ���ַ��滻Ϊb��
//�˳�ָ�����磺q����ʾ���������
//�����ʽ��
//ÿһ�У�����������Ŀ��ָ��
//�����ʽ��
//�������ָ��ִ�к�����ַ�����

//��Ŀ����
//����һ������ΪNumber�࣬����������ֱ�Ϊ����Int��ͷ���Decimal�࣬��������add�麯�������ֱ��������������м̳У���ɶ����������Ǹ������ͷǸ���������Ӽ��㡣
//
//ע�⣺
//
//1.���е�С�������ΪXXX.XXX��ʽ
//
//2.�������ǳ���ʱ�������������⡣��С��λ���ǳ���ʱ������־��Ȳ������⡣��ˣ������ʹ���ַ�����ʽ��ʾ������С����

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