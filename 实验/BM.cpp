#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

// �����Ƚϴ���
int comparisons = 0;

// �����Ӵ� P ��ÿ���ַ����Ӵ��е�����λ��
void preprocessBadCharacterTable(const string& P, vector<int>& badCharTable) {
    int m = P.length();
    for (int i = 0; i < m; ++i) {
        badCharTable[P[i]] = i;
    }
}

// BM �㷨�����Ӵ� P ������ S �е�λ��
void searchBM(const string& S, const string& P) {
    int n = S.length();
    int m = P.length();
    vector<int> badCharTable(256, -1); // ��ʼ�����ַ���

    preprocessBadCharacterTable(P, badCharTable);

    int s = 0; // ������ƥ��λ��
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && P[j] == S[s + j]) {
            --j;
            comparisons++; // �Ƚϴ�����1
        }

        if (j < 0) {
            // �ҵ�ƥ��
            cout << "Match found at position " << s << endl;
            return;
        }
        else {
            // ���㻵�ַ�λ��
            int badCharShift = j - badCharTable[S[s + j]];
            s += max(1, badCharShift);
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
    searchBM(S, P);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
