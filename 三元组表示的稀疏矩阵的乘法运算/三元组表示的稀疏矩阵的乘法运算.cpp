//��Ŀ����
//����������Ԫ���ʾ��ϡ�������г˷�����
//
//���룺
//
//��һ��Ϊ��������row��column��count���ÿո�ָ����ֱ��ʾϡ����������������������Ԫ�صĸ�����
//
//�ڶ��п�ʼ�����ϡ��������Ԫ�飬ÿ�������������ո�ָ����ֱ����һ������Ԫ�ص��бꡢ�бꡢֵ��������count�С�
//
//��һ�к�ʼ����ڶ���ϡ������row��column��count������Ԫ�顣
//
//�����
//
//���������Ϊ����������The answer is a Zero Matrix��, ������Ϊ�����������������Ԫ���ʾ��Ҫ�������Ԫ����������޷��������˷��������ERROR����
//
//
//
//����
//
//�����������
//����1
//���� :
//2 2 2
//1 1 1
//2 2 1
//
//2 2 2
//1 2 2
//2 1 2
//���:
//1 2 2
//2 1 2
//����2
//���� :
//2 2 1
//1 1 5
//
//2 2 1
//2 2 - 5
//��� :
//	The answer is a Zero Matrix
//	����3
//	���� :
//3 3 3
//1 3 1
//2 1 1
//3 2 1
//
//2 2 3
//1 2 1
//2 1 1
//2 2 1
//���:
//ERROR

#include <iostream>
#include <vector>

using namespace std;

struct Triplet {
    int row;
    int col;
    int value;
    Triplet* next;

    // Ĭ�Ϲ��캯��
    Triplet() : row(0), col(0), value(0), next(nullptr) {}

    Triplet(int row, int col, int value) : row(row), col(col), value(value), next(nullptr) {}
};


typedef struct TripletNode {
    Triplet* head;
    int count;

    TripletNode() : head(nullptr), count(0) {}
} tripletLink;

void storeValue(int row, int col, int value, tripletLink& result) {
    Triplet* newTriplet = new Triplet(row, col, value);
    bool find = false;

    if (result.head == NULL) {
        result.head = newTriplet;
        result.count++;
    }
    else {
        Triplet* current = result.head;
        Triplet* prev = nullptr;

        while (current) {
            if (current->row == row && current->col == col) {
                current->value += value;
                find = true;
                break;
            }
            prev = current;
            current = current->next;
        }

        if (!find) {
            // ���δ�ҵ�ƥ��Ľڵ㣬���½ڵ��������
            prev->next = newTriplet;
            newTriplet->next = nullptr;
            result.count++;
        }
    }
}


int main() {
    int row1, col1, count1, row2, col2, count2;
    cin >> row1 >> col1 >> count1;

    vector<Triplet> matrix1(count1);

    for (int i = 0; i < count1; i++) {
        cin >> matrix1[i].row >> matrix1[i].col >> matrix1[i].value;
    }

    cin >> row2 >> col2 >> count2;

    vector<Triplet> matrix2(count2);

    for (int i = 0; i < count2; i++) {
        cin >> matrix2[i].row >> matrix2[i].col >> matrix2[i].value;
    }

    if (col1 != row2) {
        cout << "ERROR" << endl;
        return 0;
    }

    tripletLink result;

    for (int i = 0; i < count1; i++)
    {
        for (int j = 0; j < count2; j++)
        {
            if (matrix1[i].col==matrix2[j].row)
            {
                storeValue(matrix1[i].row, matrix2[j].col, matrix1[i].value * matrix2[j].value, result);
            }
        }
    }

    bool empty = true;
    Triplet* current = result.head;
    while (current)
    {
        if (current->value != 0)
        {
            empty = false;
        }
        current = current->next;
    }

    if (empty)
    {
        cout << "The answer is a Zero Matrix" << endl;
        return 0;
    }
    else {
        current = result.head;
        while (current)
        {
            cout << current->row << " " << current->col << " " << current->value << endl;
            current = current->next;
        }
    }

    /*vector<Triplet> result;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            int val = 0;
            for (int k = 0; k < count1; k++) {
                for (int l = 0; l < count2; l++) {
                    if (matrix1[k].col == matrix2[l].row && matrix1[k].row == i + 1 && matrix2[l].col == j + 1) {
                        val += matrix1[k].value * matrix2[l].value;
                    }
                }
            }
            if (val != 0) {
                Triplet entry;
                entry.row = i + 1;
                entry.col = j + 1;
                entry.value = val;
                result.push_back(entry);
            }
        }
    }

    if (result.empty()) {
        cout << "The answer is a Zero Matrix" << endl;
    }
    else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i].row << " " << result[i].col << " " << result[i].value << endl;
        }
    }*/

    return 0;
}