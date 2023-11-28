//题目描述
//布尔矩阵是指由0和1组成的矩阵，一个布尔矩阵有奇偶均势特性，当且仅当矩阵的每行、每列得总和为偶数，即包含偶数个1，该矩阵就具有奇偶均势特性。如下面这个4 * 4的矩阵就具有奇偶均势特性：
//
//1 0 1 0
//
//0 0 0 0
//
//1 1 1 1
//
//0 1 0 1
//
//每一行的和分别为2, 0, 4, 2, 每一列的和分别为2, 2, 2, 2。
//
//编写程序，读入一个n * n阶矩阵并检查它是否具有奇偶均势特性。如果没有，你的程序应当再检查一下它是否可以通过修改一位（把0改为1，把1改为0）来使它具有奇偶均势特性。如果不可能，这个矩阵就被认为是破坏了。
//
//输入：
//
//第一行是一个整数n(0 < n < 100)，代表该矩阵的大小。然后输入n 行，每行n个整数（0或1），由空格分隔。
//
//	输出：
//
//	如果矩阵具有奇偶均势特性，输出“OK”；如果能通过只修改该矩阵中的一位来使它具有奇偶均势特性，则输出“Change bit(i, j)”，这里i和j是被修改的元素的行与列（行，列号从1开始）；否则，输出“Corrupt”
//
//
//
//	附件
//
//	样例输入输出
//	样例1
//	输入 :
//4
//1 0 1 0
//0 0 0 0
//1 1 1 1
//0 1 0 1
//输出 :
//	OK
//	样例2
//	输入 :
//4
//1 0 1 0
//0 0 1 0
//1 1 1 1
//0 1 0 1
//输出 :
//	Change bit(2, 3)
//	样例3
//	输入 :
//4
//1 0 1 0
//0 1 1 0
//1 1 1 1
//0 1 0 1
//输出 :
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

    // 计算每行和每列的和
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
