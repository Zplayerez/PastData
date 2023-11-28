//��Ŀ����
//����һ��n* m�ľ�������˳����ʱ�뽻����ת�ķ�ʽ��ӡ��ÿ��Ԫ�ء�
//
//
//
//Input Format
//
//��һ��n m�� 0 < n, m < 100
//
//	��n�У�ÿ��m��������
//
//	Output Format
//	n * m������Ԫ�أ��ո������
//
//	Example
//	Input
//	4 4
//
//	1  2  3  4
//
//	12 13 16  5
//
//	11 14 15  6
//
//
//	10  9  8  7
//
//	Output
//	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
//
//	Input
//	3 4
//
//	1  2  3  4
//
//	10 11 12  5
//
//	9  8  7  6
//
//	Output
//
//	1 2 3 4 5 6 7 8 9 10 11 12
//
//	˵��
//
//
//	�����������
//	����1
//	���� :
//1 3
//3 4 1
//��� :
//	3 4 1
//	����2
//	���� :
//4 4
//1  2  3  4
//12 13 16  5
//11 14 15  6
//10  9  8  7
//��� :
//	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
//	����3
//	���� :
//3 1
//6
//5
//7
//��� :
//	6 5 7


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    bool clockwise = true;
    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = m - 1;

    while (row_start <= row_end && col_start <= col_end) {
        if (clockwise) {
            for (int i = col_start; i <= col_end; i++) {
                cout << matrix[row_start][i] << " ";
            }
            row_start++;

            for (int i = row_start; i <= row_end; i++) {
                cout << matrix[i][col_end] << " ";
            }
            col_end--;

            if (row_start <= row_end) {
                for (int i = col_end; i >= col_start; i--) {
                    cout << matrix[row_end][i] << " ";
                }
                row_end--;
            }

            if (col_start <= col_end) {
                for (int i = row_end; i >= row_start; i--) {
                    cout << matrix[i][col_start] << " ";
                }
                col_start++;
            }
        }
        else { // Counterclockwise
            for (int i = row_start; i <= row_end; i++) {
                cout << matrix[i][col_start] << " ";
            }
            col_start++;

            for (int i = col_start; i <= col_end; i++) {
                cout << matrix[row_end][i] << " ";
            }
            row_end--;

            if (col_start <= col_end) {
                for (int i = row_end; i >= row_start; i--) {
                    cout << matrix[i][col_end] << " ";
                }
                col_end--;
            }

            if (row_start <= row_end) {
                for (int i = col_end; i >= col_start; i--) {
                    cout << matrix[row_start][i] << " ";
                }
                row_start++;
            }
        }
        clockwise = !clockwise;
    }

    cout << endl;
    return 0;
}
