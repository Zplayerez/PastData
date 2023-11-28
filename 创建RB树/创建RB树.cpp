//��Ŀ����
//RB����ڣ���������һ������������֮�⣬�������������
//1��ÿ�����Ҫô�Ǻ�ģ�Ҫô�Ǻڵġ�
//
//2��������Ǻڵġ�
//
//3��ÿ��Ҷ��㣬���ս���Ǻڵġ�
//
//4�����һ������Ǻ�ģ���ô�����������Ӷ��Ǻڵġ�
//
//5����ÿ����㣬�Ӹý�㵽�������������·���ϰ�����ͬ��Ŀ�ĺڽ�㡣
//
//�ڸ����������е�����£�����RB������������ֵ����Сֵ��
//�����ʽ��
//
//����ÿ���������һ�а���һ��������N(<= 20)�����ΪN����ͬ������ֵ��ÿ������ֵ�Կո������
//
//�ڶ���ΪҪɾ���Ľڵ����M�����ΪM����ͬ������ֵ���Կո������
//
//�����ʽ��
//
//��һ��ΪRB����ǰ��������У��Կո���������нڵ�ֵ��ʹ��(B)��(R)��ʾ�ڵ����ɫ��
//
//�ڶ���ΪRB�������ֵ����Сֵ���Կո������
//
//������Ϊɾ��M���ڵ�֮���RB����ǰ��������У��Կո����������Ϊ�գ������Null��
//
//��������1��
//
//
//13 1 45 34 98 9 4 35 23 36 37 90 85 80
//3 85 27 9
//
//�������1��
//
//34(B)4(B)1(B)9(B)23(R)45(B)36(B)35(R)37(R)90(R)85(B)80(R)98(B)
//1 98
//34(B)4(B)1(B)23(B)45(B)36(B)35(R)37(R)90(R)80(B)98(B)
//
//��������2��
//
//
//3 18 2 7
//0
//
//�������2��
//
//7(B)2(R)18(R)
//2 18
//7(B)2(R)18(R)
//
//
//
//ע�⣺����������һ������пո�ɾ������˫�ӽ��ʱ����ֱ�Ӻ�̡�
//
//
//
//�����������
//����1
//���� :
//13 1 45 34 98 9 4 35 23 36 37 90 85 80
//3 85 27 9
//��� :
//    34(B)4(B)1(B)9(B)23(R)45(B)36(B)35(R)37(R)90(R)85(B)80(R)98(B)
//    1 98
//    34(B)4(B)1(B)23(B)45(B)36(B)35(R)37(R)90(R)80(B)98(B)
//    ����2
//    ���� :
//3 18 2 7
//0
//��� :
//    7(B)2(R)18(R)
//    2 18
//    7(B)2(R)18(R)

#include<iostream>

using namespace std;

enum Color {
	RED, BLACK
};

class Node
{
public:
	Node(int value) :value(value), left(nullptr), right(nullptr), parent(nullptr), color(RED) {};

	bool isLeftChild() {
		return parent != nullptr && parent->left == this;
	}

	Node* uncle() {
		if (parent == nullptr && parent->parent == nullptr) {
			return nullptr;
		}
		if (parent->isLeftChild()) {
			return parent->parent->right;
		}
		else{
			return parent->parent->left;
		}
	}

	Node* sibling() {
		if (parent == nullptr) {
			return nullptr;
		}
		if (this->isLeftChild()){
			return parent->right;
		}
		else {
			return parent->left;
		}
	}

public:
	/*int key;*/
	int value;
	Node* left;
	Node* right;
	Node* parent;
	Color color;
};

class RedBlackTree
{
public:
	RedBlackTree() :root(nullptr) {};

	bool isRed(Node* node) {
		return node != nullptr && node->color == RED;
	}

	bool isBlack(Node* node) {
		return node == nullptr || node->color == BLACK;
	}

	void rightRotate(Node* pink) {
		Node* parent = pink->parent;
		Node* yellow = pink->left;
		Node* green = yellow->right;
		if (green != nullptr) {
			green->parent = pink;
		}
		yellow->right = pink;
		yellow->parent = parent;
		pink->left = green;
		pink->parent = yellow;
		if (parent == nullptr) {
			root = yellow;
		}
		if (parent->left == pink) {
			parent->left = yellow;
		}
		else{
			parent->right = yellow;
		}
	}

	void leftRotate(Node* pink) {
		Node* parent = pink->parent;
		Node* yellow = pink->right;
		Node* green = yellow->left;
		if (green != nullptr) {
			green->parent = pink;
		}
		yellow->left = pink;
		yellow->parent = parent;
		pink->right = green;
		pink->parent = yellow;
		if (parent == nullptr) {
			root = yellow;
		}
		else if (parent->left == pink) {
			parent->left = yellow;
		}
		else {
			parent->right = yellow;
		}
	}

	void put(int value) {
		Node* p = root;
		Node* parent = nullptr;
		while (p != nullptr) {
			parent = p;
			if (value < p->value) {
				p = p->left;
			}
			else if (value > p->value) {
				p = p->right;
			}
			else {
				p->value = value;
				return;
			}
		}
		Node* inserted = new Node(value);
		if (parent == nullptr) {
			root = inserted;
		}
		else if (value < parent->value) {
			parent->left = inserted;
			inserted->parent = parent;
		}
		else {
			parent->right = inserted;
		}
	}

	void fixRedRed(Node* x) {
		if (x == root) {
			x->color = BLACK;
			return;
		}
		if (isBlack(x)) {
			return;
		}

		Node* parent = x->parent;
		Node* uncle = x->uncle();
		Node* grandparent = parent->parent;
		if (isRed(uncle)) {
			parent->color = BLACK;
			uncle->color = BLACK;
			grandparent->color = RED;
			fixRedRed(grandparent);
		}

		if (parent->isLeftChild() && x->isLeftChild()) {
			parent->color = BLACK;
			grandparent->color = RED;
			rightRotate(grandparent);
		}
		else if (parent->isLeftChild() /*&& !x->isLeftChild()*/) {
			leftRotate(parent);
			x->color = BLACK;
			grandparent->color = RED;
			rightRotate(grandparent);
		}
		else if (/*!parent->isLeftChild() &&*/ !x->isLeftChild()) {
			parent->color = BLACK;
			leftRotate(grandparent);
		}
		else {
			rightRotate(parent);
			x->color = BLACK;
			grandparent->color = RED;
			leftRotate(grandparent);
		}
	}

	void remove(int value) {
		Node* deleted = find(value);
		if (deleted == nullptr) {
			return;
		}
		doRemove(deleted);
	}

	void fixDoubleBlack(Node* x) {
		if (x == root) {
			return;
		}
		Node* parent = x->parent;
		Node* sibling = x->sibling();
		if (isRed(sibling)) {
			if (x->isLeftChild()) {
				leftRotate(parent);
			}
			else {
				rightRotate(parent);
			}
			parent->color = RED;
			sibling->color = BLACK;
			fixDoubleBlack(x);
			return;
		}
		if (sibling != nullptr) {
			if (isBlack(sibling->left) && isBlack(sibling->right)) {
				sibling->color = RED;
				if (isRed(parent)) {
					parent->color = BLACK;
				}
				else {
					fixDoubleBlack(parent);
				}
			}
			else {
				if (sibling->isLeftChild() && isRed(sibling->left)) {
					rightRotate(parent);
					sibling->left->color = BLACK;
					sibling->color = parent->color;
				}
				else if (sibling->isLeftChild() && isRed(sibling->right)) {
					sibling->right->color = parent->color;
					leftRotate(sibling);
					rightRotate(parent);
				}
				else if (!sibling->isLeftChild() && isRed(sibling->left)) {
					sibling->left->color = parent->color;
					rightRotate(sibling);
					leftRotate(parent);
				}
				else {
					leftRotate(parent);
					sibling->right->color = BLACK;
					sibling->color = parent->color;
				}
				parent->color = BLACK;
			}
		}
		else {
			fixDoubleBlack(parent);
		}
	}

	void doRemove(Node* deleted) {
		Node* replaced = findReplace(deleted);
		Node* parent = deleted->parent;
		if (replaced == nullptr) {
			if (deleted == root) {
				root = nullptr;
			}
			else {
				if (isBlack(deleted)) {
					fixDoubleBlack(deleted);
				}
				else {
					//��ɫҶ�ӣ������κδ���
				}
				if (deleted->isLeftChild()) {
					parent->left = nullptr;
				}
				else {
					parent->right = nullptr;
				}
				deleted->parent = nullptr;
			}
			return;
		}
		if (deleted->left == nullptr || deleted->right == nullptr) {
			if (deleted == root) {
				root->value = replaced->value;
				root->left = root->right = nullptr;
			}
			else {
				if (deleted->isLeftChild()) {
					parent->left = replaced;
				}
				else {
					parent->right = replaced;
				}
				replaced->parent = parent;
				deleted->parent = nullptr;
				deleted->left = deleted->right = nullptr;
				if (isBlack(deleted) && isBlack(replaced)) {
					fixDoubleBlack(replaced);
				}
				else {
					replaced->color = BLACK;
				}
			}
			return;
		}
		int t = deleted->value;
		deleted->value = replaced->value;
		replaced->value = deleted->value;
		doRemove(replaced);
	}

	Node* find(int value) {
		Node* p = root;
		while (p != nullptr) {
			if (value < p->value) {
				p = p->left;
			}
			else if (value > p->value) {
				p = p->right;
			}
			else {
				return p;
			}
		}
		return nullptr;
	}

	Node* findReplace(Node* deleted) {
		if (deleted->left == nullptr && deleted->right == nullptr) {
			return nullptr;
		}
		if (deleted->left == nullptr) {
			return deleted->right;
		}
		if (deleted->right == nullptr) {
			return deleted->left;
		}
		Node* s = deleted->right;
		while (s->left != nullptr) {
			s = s->left;
		}
		return s;
	}

	void preOrderPrint(Node* root) {
		if (root == nullptr) {
			return;
		}
		if (root->color == RED) {

		}
	}

private:
	Node* root;
};

int main() {
	RedBlackTree tree;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		tree.put(t);
	}

	return 0;
}
