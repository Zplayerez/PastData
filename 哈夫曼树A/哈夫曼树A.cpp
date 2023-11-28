//��Ŀ����
//�ϲ�����ˮ�������Ҫ������������ˮ�����������͡�����ֻ���������ϲ��������һ��ˮ�����ϲ���һ����ˮ����Ҫ����С������
//
//��Ŀ���룺
//
//��һ������ˮ�����ĸ���n(1 <= n < 100)���������n������
//
//	��Ŀ�����
//
//	�ϲ���С������ȡֵ��long��Χ�ڣ�
//
//
//
//	��ʾ��ע����Ŀ���⡣
//
//
//
//	����
//
//	�����������
//	����1
//	���� :
//6
//8282
//165
//5
//7431
//9137
//3
//���:
//48694

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // ʹ�����ȶ��д洢ˮ����������������������С��������
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    // ����ˮ����������
    for (int i = 0; i < n; ++i) {
        long long energy;
        cin >> energy;
        pq.push(energy);
    }

    long long total_energy = 0;

    // ͨ�����Ϻϲ�����������С��ˮ����飬ֱ��ֻʣ��һ������ˮ��
    while (pq.size() > 1) {
        long long energy1 = pq.top();
        pq.pop();
        long long energy2 = pq.top();
        pq.pop();

        long long merged_energy = energy1 + energy2;
        total_energy += merged_energy;

        pq.push(merged_energy);
    }

    cout << total_energy << endl;

    return 0;
}
