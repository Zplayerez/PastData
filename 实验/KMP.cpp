#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

// �����Ƚϴ���
int comparisons = 0;

// ��������ƥ���
vector<int> buildPartialMatchTable(const string& P) {
    int m = P.length();
    vector<int> table(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++) {
        while (j > 0 && P[i] != P[j]) {
            j = table[j - 1];
        }

        if (P[i] == P[j]) {
            j++;
        }

        table[i] = j;
    }

    return table;
}

// KMP�㷨�����Ӵ�P������S�е�λ��
void searchKMP(const string& S, const string& P) {
    int n = S.length();
    int m = P.length();
    vector<int> partialMatchTable = buildPartialMatchTable(P);
    int i = 0;
    int j = 0;

    while (i < n) {
        comparisons++; // �Ƚϴ�����1

        if (P[j] == S[i]) {
            if (j == m - 1) {
                // �ҵ�ƥ��
                cout << "Match found at position " << i - j << endl;
                return;
            }
            i++;
            j++;
        }
        else {
            if (j != 0) {
                j = partialMatchTable[j - 1];
            }
            else {
                i++;
            }
        }
    }

    // δ�ҵ�ƥ��
    cout << "no" << endl;
}

int main() {
    string S, P;
    cout << "Enter the main string S: ";
    cin >> S;
    cout << "Enter the substring P: ";
    cin >> P;

    // ����ִ��ʱ��
    auto start = chrono::high_resolution_clock::now();
    searchKMP(S, P);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
