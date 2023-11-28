//题目描述
//对两个由三元组表示的稀疏矩阵进行乘法运算
//
//输入：
//
//第一行为三个整数row，column，count，用空格分隔，分别表示稀疏矩阵的行数、列数、非零元素的个数。
//
//第二行开始输入该稀疏矩阵的三元组，每行三个整数，空格分隔，分别代表一个非零元素的行标、列标、值，共输入count行。
//
//空一行后开始输入第二个稀疏矩阵的row，column，count，及三元组。
//
//输出：
//
//如果计算结果为零矩阵，输出“The answer is a Zero Matrix”, 如果结果为非零矩阵，输出结果的三元组表示，要求输出三元组有序。如果无法计算矩阵乘法，输出“ERROR”。
//
//
//
//附件
//
//样例输入输出
//样例1
//输入 :
//2 2 2
//1 1 1
//2 2 1
//
//2 2 2
//1 2 2
//2 1 2
//输出:
//1 2 2
//2 1 2
//样例2
//输入 :
//2 2 1
//1 1 5
//
//2 2 1
//2 2 - 5
//输出 :
//	The answer is a Zero Matrix
//	样例3
//	输入 :
//3 3 3
//1 3 1
//2 1 1
//3 2 1
//
//2 2 3
//1 2 1
//2 1 1
//2 2 1
//输出:
//ERROR

#include <iostream>
#include <vector>

using namespace std;

struct Triplet {
    int row;
    int col;
    int value;
    Triplet* next;

    // 默认构造函数
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
            // 如果未找到匹配的节点，则将新节点插入链表
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