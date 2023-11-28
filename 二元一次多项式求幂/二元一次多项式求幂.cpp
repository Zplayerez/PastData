//��Ŀ����
//����һ��������Ϊ0�Ķ�Ԫһ�ζ���ʽ����ö���ʽ���ݡ�
//
//��δ֪��Ϊx, y������Ϊx��y������ϵ��a, b�Լ�������n���������������ʽ
//
//��������Ľ��������x���ݽ�������
//
//Input Format
//����δ֪������ϵ�� a, b(-100 < a, b < 100), n(1 < n < 6)
//
//	Output Format
//	������Ľ���Ķ���ʽ������x�ݽ�������
//
//	Example
//	Input
//	2 3 2
//
//	Output
//	4x ^ 2 + 12xy + 9y ^ 2
//
//	˵��
//	��Ϊ1ʱ����� ^ 1
//
//	ϵ��Ϊ1ʱ�����ϵ���� - 1ֻ������š�
//
//
//
//	�����������
//	����1
//	���� :
//2 3 2
//��� :
//	4x ^ 2 + 12xy + 9y ^ 2

#include <iostream>
#include <cmath>
using namespace std;

int combination(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return combination(n - 1, k - 1) + combination(n - 1, k);
}

int main() {

    long long a, b, n;
    cin >> a >> b >> n;

    if (a == 0 && b == 0)
    {
        cout << 0;
    }
    if (a == 0 && b != 0)
    {
        if (b == 1)
        {
            cout << 'y' << '^' << n;
        }
        if (b == -1)
        {
            cout << '-' << 'y' << '^' << n;
        }
        if (b != 1 && b != -1)
        {
            cout << pow(b, n) << 'y' << '^' << n;
        }
    }
    if (a != 0 && b == 0)
    {
        if (a == 1)
        {
            cout << 'x' << '^' << n;
        }
        if (a == -1)
        {
            cout << '-' << 'x' << '^' << n;
        }
        if (a != 1 && a != -1)
        {
            cout << pow(a, n) << 'x' << '^' << n;
        }
    }
    if (a != 0 && b != 0)
    {
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
            {
                if (pow(a, n) == 1)
                {
                    cout << 'x' << '^' << n;
                }
                if (pow(a, n) == -1)
                {
                    cout << '-' << 'x' << '^' << n;
                }
                if (pow(a, n) != 1 && pow(a, n) != -1)
                {
                    cout << pow(a, n) << 'x' << '^' << n;
                }
            }

            if (i > 0 && i < n)
            {
                if (pow(a, n - i) * pow(b, i) > 0)
                {
                    if (combination(n, i) * pow(a, n - i) * pow(b, i) == 1)
                    {
                        if (i == 1 && n - i != 1)
                        {
                            cout << '+' <<  'x' << '^' << n - i << 'y';
                        }
                        if (i != 1 && n - i == 1)
                        {
                            cout << '+' <<  'x' << 'y' << '^' << i;
                        }
                        if (i == 1 && n - i == 1)
                        {
                            cout << '+' <<  'x' << 'y';
                        }
                        if (i != 1 && n - i != 1)
                        {
                            cout << '+' <<  'x' << '^' << n - i << 'y' << '^' << i;
                        }
                    }
                    else {
                        if (i == 1 && n - i != 1)
                        {
                            cout << '+' << combination(n, i) * pow(a, n - i) * pow(b, i) << 'x' << '^' << n - i << 'y';
                        }
                        if (i != 1 && n - i == 1)
                        {
                            cout << '+' << combination(n, i) * pow(a, n - i) * pow(b, i) << 'x' << 'y' << '^' << i;
                        }
                        if (i == 1 && n - i == 1)
                        {
                            cout << '+' << combination(n, i) * pow(a, n - i) * pow(b, i) << 'x' << 'y';
                        }
                        if (i != 1 && n - i != 1)
                        {
                            cout << '+' << combination(n, i) * pow(a, n - i) * pow(b, i) << 'x' << '^' << n - i << 'y' << '^' << i;
                        }
                    }
                }
                if (pow(a, n - i) * pow(b, i) < 0)
                {
                    if (combination(n, i) * pow(a, n - i) * pow(b, i) == -1)
                    {
                        if (i == 1 && n - i != 1)
                        {
                            cout << '-' << 'x' << '^' << n - i << 'y';
                        }
                        if (i != 1 && n - i == 1)
                        {
                            cout << '-' << 'x' << 'y' << '^' << i;
                        }
                        if (i == 1 && n - i == 1)
                        {
                            cout << '-' << 'x' << 'y';
                        }
                        if (i != 1 && n - i != 1)
                        {
                            cout << '-' << 'x' << '^' << n - i << 'y' << '^' << i;
                        }
                    }
                    else {
                        if (i == 1 && n - i != 1)
                        {
                            cout << combination(n, i) * pow(a, n - i) * pow(b, i) << 'x' << '^' << n - i << 'y';
                        }
                        if (i != 1 && n - i == 1)
                        {
                            cout << combination(n, i) * pow(a, n - i) * pow(b, i) << 'x' << 'y' << '^' << i;
                        }
                        if (i == 1 && n - i == 1)
                        {
                            cout << combination(n, i) * pow(a, n - i) * pow(b, i) << 'x' << 'y';
                        }
                        if (i != 1 && n - i != 1)
                        {
                            cout << combination(n, i) * pow(a, n - i) * pow(b, i) << 'x' << '^' << n - i << 'y' << '^' << i;
                        }
                    }
                }
            }

            if (i == n)
            {
                if (pow(b, n) > 0)
                {
                    if (pow(b, n) == 1)
                    {
                        cout << '+' << 'y' << '^' << n;
                    }
                    else cout<<'+'<< pow(b, n) << 'y' << '^' << n;
                }
                if (pow(b, n) < 0)
                {
                    if (pow(b, n) == -1)
                    {
                        cout << '-' << 'y' << '^' << n;
                    }
                    else cout << pow(b, n) << 'y' << '^' << n;
                }
            }
        }
    }
    

    return 0;
}