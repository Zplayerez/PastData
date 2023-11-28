//��Ŀ����
//����������ָ��0��1��ɵľ���һ��������������ż�������ԣ����ҽ��������ÿ�С�ÿ�е��ܺ�Ϊż����������ż����1���þ���;�����ż�������ԡ����������4 * 4�ľ���;�����ż�������ԣ�
//
//1 0 1 0
//
//0 0 0 0
//
//1 1 1 1
//
//0 1 0 1
//
//ÿһ�еĺͷֱ�Ϊ2, 0, 4, 2, ÿһ�еĺͷֱ�Ϊ2, 2, 2, 2��
//
//��д���򣬶���һ��n * n�׾��󲢼�����Ƿ������ż�������ԡ����û�У���ĳ���Ӧ���ټ��һ�����Ƿ����ͨ���޸�һλ����0��Ϊ1����1��Ϊ0����ʹ��������ż�������ԡ���������ܣ��������ͱ���Ϊ���ƻ��ˡ�
//
//���룺
//
//��һ����һ������n(0 < n < 100)������þ���Ĵ�С��Ȼ������n �У�ÿ��n��������0��1�����ɿո�ָ���
//
//	�����
//
//	������������ż�������ԣ������OK���������ͨ��ֻ�޸ĸþ����е�һλ��ʹ��������ż�������ԣ��������Change bit(i, j)��������i��j�Ǳ��޸ĵ�Ԫ�ص������У��У��кŴ�1��ʼ�������������Corrupt��
//
//
//
//	����
//
//	�����������
//	����1
//	���� :
//4
//1 0 1 0
//0 0 0 0
//1 1 1 1
//0 1 0 1
//��� :
//	OK
//	����2
//	���� :
//4
//1 0 1 0
//0 0 1 0
//1 1 1 1
//0 1 0 1
//��� :
//	Change bit(2, 3)
//	����3
//	���� :
//4
//1 0 1 0
//0 1 1 0
//1 1 1 1
//0 1 0 1
//��� :
//	Corrupt

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> rowSum(n, 0);
    vector<int> colSum(n, 0);

    // ����ÿ�к�ÿ�еĺ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }

    bool hasOddSum = false;
    bool hasEvenSum = false;

    for (int i = 0; i < n; i++) {
        if (rowSum[i] % 2 != 0 || colSum[i] % 2 != 0) {
            hasOddSum = true;
        }
        else {
            hasEvenSum = true;
        }
    }

    if (!hasOddSum) {
        cout << "OK" << endl;
    }
    else if (hasOddSum && hasEvenSum) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((rowSum[i] + 1) % 2 == 0 && (colSum[j] + 1) % 2 == 0) {
                    cout << "Change bit (" << i + 1 << "," << j + 1 << ")" << endl;
                    return 0;
                }
            }
        }
        cout << "Corrupt" << endl;
    }
    else {
        cout << "Corrupt" << endl;
    }

    return 0;
}
