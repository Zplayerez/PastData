//��Ŀ����
//����һ������S���Ӵ�P��ʹ��KMP�㷨�����Ӵ�P������S�д��ڵ�λ�ã����Ӵ�P������S�д��ڣ���������Ӵ�P�е�һ�ַ���ȵ��ַ�������S�е���ţ����������������no��
//
//���������ʽ������S �Ӵ�P��
//
//���������ʽ��������Ӵ�P�е�һ�ַ���ȵ��ַ�������S�е���ţ�
//
//����������ababcabcacbab abcac
//
//���������5
//
//
//
//����
//
//�����������
//����1
//���� :
//ababcabcacbab abcac
//��� :
//5
//����2
//���� :
//ABCDABCDABDE DBAEA
//��� :
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
