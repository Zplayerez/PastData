//题目描述
//给出一棵完全二叉树的先序遍历，输出其后序遍历。结点均为不重复的单个英文字母，区分大小写。结点总数小于52。
//
//Input Format
//
//输入先序字符串
//
//Output Format
//后序遍历字符串
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
//样例输入输出
//样例1
//输入 :
//ABDGHCEIF
//输出 :
//GHDCBIFEA
//样例2
//输入 :
//a
//输出 :
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
    TreeNode* tree = new TreeNode[preorder.size() + 1];  // 索引0没有使用，从1开始。

    int n = 1;
    int m = 1;
    // 计算s为满二叉树时的元素个数m。 
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
