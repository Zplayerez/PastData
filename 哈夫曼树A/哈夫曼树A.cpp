//题目描述
//合并两个水晶碎块需要的能量是两个水晶碎块的能量和。假设只可以两两合并，请求出一堆水晶碎块合并成一整块水晶需要的最小能量。
//
//题目输入：
//
//第一行输入水晶碎块的个数n(1 <= n < 100)，随后输入n个整数
//
//	题目输出：
//
//	合并最小能量（取值在long范围内）
//
//
//
//	提示：注意题目标题。
//
//
//
//	附件
//
//	样例输入输出
//	样例1
//	输入 :
//6
//8282
//165
//5
//7431
//9137
//3
//输出:
//48694

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 使用优先队列存储水晶碎块的能量，按照能量从小到大排序
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    // 输入水晶碎块的能量
    for (int i = 0; i < n; ++i) {
        long long energy;
        cin >> energy;
        pq.push(energy);
    }

    long long total_energy = 0;

    // 通过不断合并两个能量最小的水晶碎块，直到只剩下一个整块水晶
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
