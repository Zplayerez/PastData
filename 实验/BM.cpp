#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

// 计数比较次数
int comparisons = 0;

// 定义子串 P 中每个字符在子串中的最右位置
void preprocessBadCharacterTable(const string& P, vector<int>& badCharTable) {
    int m = P.length();
    for (int i = 0; i < m; ++i) {
        badCharTable[P[i]] = i;
    }
}

// BM 算法查找子串 P 在主串 S 中的位置
void searchBM(const string& S, const string& P) {
    int n = S.length();
    int m = P.length();
    vector<int> badCharTable(256, -1); // 初始化坏字符表

    preprocessBadCharacterTable(P, badCharTable);

    int s = 0; // 主串中匹配位置
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && P[j] == S[s + j]) {
            --j;
            comparisons++; // 比较次数加1
        }

        if (j < 0) {
            // 找到匹配
            cout << "Match found at position " << s << endl;
            return;
        }
        else {
            // 计算坏字符位移
            int badCharShift = j - badCharTable[S[s + j]];
            s += max(1, badCharShift);
        }
    }

    // 未找到匹配
    cout << "no" << endl;
}

int main() {
    string S, P;
    cout << "Enter the main string S: ";
    cin >> S;
    cout << "Enter the substring P: ";
    cin >> P;

    // 计算执行时间
    auto start = chrono::high_resolution_clock::now();
    searchBM(S, P);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
