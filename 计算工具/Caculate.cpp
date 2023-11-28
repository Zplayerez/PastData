#include<iostream>
#include<math.h>
using namespace std;
float Caculate(float a, float b, float c, float d, float e, float)
{
	float sum, ave;
	ave = (a + b + c + d + e) / 5;
	sum = pow((pow(a - ave, 2) + pow(b - ave, 2) + pow(c - ave, 2) + pow(d - ave, 2) + pow(e - ave, 2)) / 5, 0.5);
	return sum;
}
int main()
{
	float x1, x2, x3, x4, x5, x6;
	cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;
	cout << Caculate(x1, x2, x3, x4, x5, x6) << endl;
	cout << Caculate(x1, x2, x3, x4, x5, x6) / pow(5, 0.5) << endl;
	cout << Caculate(x1, x2, x3, x4, x5, x6) / pow(5, 0.5) * 1.14 << endl;
	cout << pow(pow(0.029, 2) + pow(Caculate(x1, x2, x3, x4, x5, x6) / pow(5, 0.5) * 1.14, 2), 0.5);
	return 0;
}