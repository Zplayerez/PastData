//题目描述
//给定一个主串S和子串P，使用KMP算法查找子串P在主串S中存在的位置，若子串P在主串S中存在，则输出与子串P中第一字符相等的字符在主串S中的序号；若不存在则输出“no”
//
//程序输入格式：主串S 子串P；
//
//程序输出格式：输出与子串P中第一字符相等的字符在主串S中的序号；
//
//输入样例：ababcabcacbab abcac
//
//输出样例：5
//
//
//
//附件
//
//样例输入输出
//样例1
//输入 :
//ababcabcacbab abcac
//输出 :
//5
//样例2
//输入 :
//ABCDABCDABDE DBAEA
//输出 :
//no

#include <iostream>
#include <vector>

void computeLPSArray(const std::string& pattern, std::vector<int>& lps) {
    int length = 0; // Length of the previous longest prefix suffix

    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        }
        else {
            if (length != 0) {
                length = lps[length - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(const std::string& text, const std::string& pattern) {
    int m = pattern.length();
    int n = text.length();

    std::vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            // Pattern found, return the starting position
            return i - j;
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    // Pattern not found
    return -1;
}

int main() {
    std::string text, pattern;
    std::cin >> text >> pattern;

    int result = KMPSearch(text, pattern);

    if (result != -1) {
        std::cout << result << std::endl;
    }
    else {
        std::cout << "no" << std::endl;
    }

    return 0;
}
