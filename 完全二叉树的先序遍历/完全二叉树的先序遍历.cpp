//��Ŀ����
//����һ����ȫ����������������������������������Ϊ���ظ��ĵ���Ӣ����ĸ�����ִ�Сд���������С��52��
//
//Input Format
//
//���������ַ���
//
//Output Format
//��������ַ���
//
//Example
//Input
//ABDGHCEIF
//
//Output
//GHDCBIFEA
//
//
//
//�����������
//����1
//���� :
//ABDGHCEIF
//��� :
//GHDCBIFEA
//����2
//���� :
//a
//��� :
//a

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class TreeNode
{
public:
    TreeNode* leftChild;
    TreeNode* rightChild;
    char value;
    TreeNode(char val = NULL, TreeNode* left = NULL, TreeNode* right = NULL)
    {
        value = val;
        leftChild = left;
        rightChild = right;
    }
};

void postorderTraversal(TreeNode* tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        postorderTraversal(tree->leftChild);
        postorderTraversal(tree->rightChild);
        cout << tree->value;
    }
}

int main()
{
    string preorder;
    cin >> preorder;
    TreeNode* tree = new TreeNode[preorder.size() + 1];  // ����0û��ʹ�ã���1��ʼ��

    int n = 1;
    int m = 1;
    // ����sΪ��������ʱ��Ԫ�ظ���m�� 
    while ((int)preorder.size() > m)
    {
        double u = (double)n;
        m += pow(2, u);
        n++;
    }

    for (int q = 1; q <= preorder.size(); q++)
    {
        if (2 * q <= (int)preorder.size()) {
            tree[q].leftChild = &tree[2 * q];
        }
        if (2 * q + 1 <= (int)preorder.size()) {
            tree[q].rightChild = &tree[2 * q + 1];
        }
    }

    tree[1].value = preorder[0];

    for (int i = 1, j = 1; i < (int)preorder.size();)
    {
        while (tree[j].value != NULL && tree[j].leftChild != NULL && i < (int)preorder.size())
        {
            j = 2 * j;
            tree[j].value = preorder[i++];
        }

        if (tree[j / 2].rightChild != NULL && tree[j / 2].rightChild->value == NULL)
        {
            j = j + 1;
            tree[j].value = preorder[i++];
        }
        else if (tree[j / 2].rightChild != NULL && tree[j / 2].rightChild->value != NULL)
        {
            j = j / 2;
            while (j > 1 && tree[j / 2].rightChild != NULL && tree[j / 2].rightChild->value != NULL) {
                j = j / 2;
            }
            j = j + 1;
            tree[j].value = preorder[i++];
        }
        else if (tree[j / 2].rightChild == NULL)
        {
            j = j / 2;
            while (j > 1 && tree[j / 2].rightChild != NULL && tree[j / 2].rightChild->value != NULL) {
                j = j / 2;
            }
            j = j + 1;
            tree[j].value = preorder[i++];
        }
    }

    postorderTraversal(&tree[1]);
    delete[] tree;
    return 0;
}
