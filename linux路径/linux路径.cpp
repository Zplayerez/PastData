//��Ŀ����
//����һ��������Linux�ļ�����·���������Ϊ��׼��Linux�ļ�����·����
//
//��Linux�ļ�·���У�һ��Ӣ�ľ��.��ʾ��ǰĿ¼������������Ӣ�ľ�� ..��ʾ���ص���һ��Ŀ¼��
//
//��׼��Linux�ļ�����·�����������ص�
//
//��һ���ַ�Ϊб�� /
//
//����Ŀ¼����ֱ�����ҽ���һ��б�� /
//
//����Ŀ¼�⣬·����β����Ϊб�� /
//
//�������һ��Ӣ�ľ��.��������������Ӣ�ľ�� ..
//
//Input Format
//������һ���ַ�����ɣ�Ϊ������Linux�ļ�����·����
//
//Output Format
//���һ�У�Ϊ��򻯵�Linux�ļ�����·����
//
//Example
//Input
/// aaa / .. / .. / bbb / ccc / ..///./..
//
//Output
///
//
//˵��
//·���Ӹ�Ŀ¼��ʼ�������ҽ��н���
//
//aaa ��ʾ�����Ŀ¼�� aaa Ŀ¼
//
//..��ʾ������һ��Ŀ¼�������ظ�Ŀ¼
//
//..��ʾ������һ��Ŀ¼������ǰĿ¼Ϊ��Ŀ¼������һ��Ŀ¼�����Դ��ڸ�Ŀ¼��
//
//bbb ��ʾ�����Ŀ¼�� bbb Ŀ¼
//
//ccc ��ʾ���� bbb Ŀ¼�� ccc Ŀ¼
//
//..��ʾ������һ��Ŀ¼�������� bbb Ŀ¼
//
//�������ɸ�������б�� / ��û��Ŀ¼���ƣ�ֱ��ɾ��
//
//.��ʾ�����ļ��У����Դ��� bbb Ŀ¼
//
//..��ʾ������һ��Ŀ¼�������ظ�Ŀ¼
//
//��Ŀ¼��б�� / ��ʾ�������б�� /
//
//
//
//�����������
//����1
//���� :
/// aaa / .. / .. / bbb / ccc / ..///./..
//��� :
//	/
//	����2
//	���� :
/// home /
//��� :
//	/ home

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

string simplifyPath(string path) {
    stack<string> components;
    stringstream ss(path);
    string component;

    // ʹ�� '/' ��Ϊ�ָ�����·����ֳ����
    while (getline(ss, component, '/')) {
        if (component == "..") {
            // ������Ϊ ".."����ʾ������һ��Ŀ¼������ջ��Ŀ¼
            if (!components.empty()) {
                components.pop();
            }
        }
        else if (component != "." && !component.empty()) {
            // ���� "." �Ϳ����������ЧĿ¼������ջ
            components.push(component);
        }
    }

    // �����򻯺��·��
    vector<string> simplifiedComponents;
    while (!components.empty()) {
        simplifiedComponents.push_back(components.top());
        components.pop();
    }

    // ��ջ��ȡ����Ŀ¼�Ǵ�������ģ���Ҫ���򹹽�·��
    string simplifiedPath = "/";
    for (int i = simplifiedComponents.size() - 1; i >= 0; --i) {
        simplifiedPath += simplifiedComponents[i];
        if (i > 0) {
            simplifiedPath += "/";
        }
    }

    return simplifiedPath;
}

int main() {
    string input;
    cin >> input;

    string simplified = simplifyPath(input);
    cout << simplified << endl;

    return 0;
}
