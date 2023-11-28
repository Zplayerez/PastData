#include<iostream>

using namespace std;


class TreeNode {
public:
	char arr;
	TreeNode* leftChild;
	TreeNode* rightChild;

	TreeNode(char arr) :arr(arr), leftChild(nullptr), rightChild(nullptr) {}
};

void initpreorder(TreeNode*& root, int& count, int& size, bool& isfull) {
	if (count < size)
	{
		if (root == nullptr)
		{
			root = new TreeNode('#');
			count++;
			return;
		}
		initpreorder(root->leftChild, count, size, isfull);
		initpreorder(root->rightChild, count, size, isfull);
		return;
	}
	isfull = true;
	return;
}

void preorderInsert(TreeNode* root, char arr, bool& used) {
	if (root != nullptr) {
		if (root->arr == '#' && !used) {
			root->arr = arr;
			used = true;
			return;
		}
		// µÝ¹é±éÀú×ó×ÓÊ÷
		preorderInsert(root->leftChild, arr, used);
		// µÝ¹é±éÀúÓÒ×ÓÊ÷
		preorderInsert(root->rightChild, arr, used);
	}
}

void preoderprint(TreeNode* root) {
	if (root != nullptr)
	{
		preoderprint(root->leftChild);
		preoderprint(root->rightChild);
		cout << root->arr;
	}
}

int main() {
	string preorder;
	cin >> preorder;

	TreeNode* root = nullptr;
	int count = 0;
	int size = preorder.size();
	bool isfull = false;

	while (!isfull)
	{
		initpreorder(root, count, size, isfull);
	}

	for (char arr : preorder)
	{
		bool used = false;
		preorderInsert(root, arr, used);
	}

	preoderprint(root);

	return 0;
}