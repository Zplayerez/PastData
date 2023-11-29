//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <chrono>
//
//using namespace std;
//
//// 计数比较次数
//int comparisons = 0;
//
//// 定义子串 P 中每个字符在子串中的最右位置
//void preprocessBadCharacterTable(const string& P, vector<int>& badCharTable) {
//    int m = P.length();
//    for (int i = 0; i < m; ++i) {
//        badCharTable[P[i]] = i;
//    }
//}
//
//// BM 算法查找子串 P 在主串 S 中的位置
//void searchBM(const string& S, const string& P) {
//    int n = S.length();
//    int m = P.length();
//    vector<int> badCharTable(256, -1); // 初始化坏字符表
//
//    preprocessBadCharacterTable(P, badCharTable);
//
//    int s = 0; // 主串中匹配位置
//    while (s <= n - m) {
//        int j = m - 1;
//
//        while (j >= 0 && P[j] == S[s + j]) {
//            --j;
//            comparisons++; // 比较次数加1
//        }
//
//        if (j < 0) {
//            // 找到匹配
//            cout << "Match found at position " << s << endl;
//            return;
//        }
//        else {
//            // 计算坏字符位移
//            int badCharShift = j - badCharTable[S[s + j]];
//            s += max(1, badCharShift);
//        }
//    }
//
//    // 未找到匹配
//    cout << "no" << endl;
//}
//
//int main() {
//    string S, P;
//    cout << "Enter the main string S: ";
//    cin >> S;
//    cout << "Enter the substring P: ";
//    cin >> P;
//
//    // 计算执行时间
//    auto start = chrono::high_resolution_clock::now();
//    searchBM(S, P);
//    auto end = chrono::high_resolution_clock::now();
//    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
//
//    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
//    cout << "Number of comparisons: " << comparisons << endl;
//
//    return 0;
//}
#include<iostream>
using namespace std;
struct rbtree
{
	int val;
	rbtree* left;
	rbtree* right;
	rbtree* parent;
	int bf = 0;
	int color = 0;
};
rbtree* head = new rbtree;
rbtree* cur;
rbtree* right_rotate(rbtree* node) {
	rbtree* left_node = node->left;
	node->left = left_node->right;
	if (left_node->right) {
		left_node->right->parent = node;
	}
	left_node->parent = node->parent;
	if (head == node) {
		head = left_node;
	}
	else if (node == node->parent->left)
		node->parent->left = left_node;
	else
		node->parent->right = left_node;
	left_node->right = node;
	node->parent = left_node;
	return left_node;
}
rbtree* left_rotate(rbtree* node) {
	rbtree* right_node = node->right;
	node->right = right_node->left;
	if (right_node->left) {
		right_node->left->parent = node;
	}
	right_node->parent = node->parent;
	if (head == node) {
		head = right_node;
	}
	else if (node == node->parent->left) {
		node->parent->left = right_node;
	}
	else
		node->parent->right = right_node;
	right_node->left = node;
	node->parent = right_node;
	return right_node;
}
rbtree* tree_insert(rbtree* node) {
	while (node->parent && node->parent->color == 0) {
		if (node->parent == node->parent->parent->left) {
			rbtree* uncle = node->parent->parent->right;
			if (uncle && uncle->color == 0) {
				node->parent->color = 1;
				uncle->color = 1;
				node->parent->parent->color = 0;
				node = node->parent->parent;
			}
			else {
				if (node == node->parent->right) {
					node = node->parent;
					left_rotate(node);
				}
				node->parent->color = 1;
				node->parent->parent->color = 0;
				right_rotate(node->parent->parent);
			}
		}
		else {
			if (node->parent == node->parent->parent->right) {
				rbtree* uncle = node->parent->parent->left;
				if (uncle != NULL && uncle->color == 0) {
					node->parent->color = 1;
					uncle->color = 1;
					node->parent->parent->color = 0;
					node = node->parent->parent;
				}
				else {
					if (node == node->parent->left) {
						node = node->parent;
						right_rotate(node);
					}
					node->parent->color = 1;
					node->parent->parent->color = 0;
					left_rotate(node->parent->parent);
				}
			}
		}
		head->color = 1;
	}
	return node;
}
rbtree* insert(rbtree* node, int m, rbtree* pa) {
	if (node == NULL) {
		node = new rbtree;
		node->val = m;
		node->left = NULL;
		node->right = NULL;
		node->parent = pa;
		cur = node;
		return node;
	}
	else {
		if (m > node->val) {
			node->right = insert(node->right, m, node);
		}
		else if (m < node->val) {
			node->left = insert(node->left, m, node);
		}
	}
	return node;
}
void tree_balance(rbtree* node) {
	if (node == NULL) {
		return;
	}
	rbtree* parent = node->parent;
	if (node->left == NULL) {
		if (node->color == 0) {
			if (node == parent->left)
				parent->left = NULL;
			else
				parent->right = NULL;
			delete node;
			return;
		}
		else {
			if (node->right) {
				node->val = node->right->val;
				delete node->right;
				node->right = NULL;
				return;
			}
		}
	}
	else if (node->right == NULL) {
		node->val = node->left->val;
		delete node->left;
		node->left = NULL;
		return;
	}
	else {
		parent = node;
		rbtree* replace = node->right;
		while (replace->left) {
			parent = replace;
			replace = replace->left;
		}
		node->val = replace->val;
		node = replace;
		if (node->color == 0) {
			if (node == parent->left) {
				parent->left = NULL;
			}
			else
				parent->right = NULL;
			delete node;
			return;
		}
		else {
			if (node->right) {
				node->val = node->right->val;
				delete node->right;
				node->right = NULL;
				return;
			}
		}
	}
	if (parent == NULL) {
		delete node;
		head = NULL;
		return;
	}
	while (parent) {
		rbtree* brother = NULL;
		if (node == parent->left) {
			brother = parent->right;
		}
		else
			brother = parent->left;
		if (brother->color == 1) {
			if (brother == parent->right) {
				if (brother->right && brother->right->color == 0) {
					rbtree* broright = brother->right;
					left_rotate(parent);
					brother->color = parent->color;
					parent->color = 1;
					broright->color = 1;
					if (node->left == NULL && node->right == NULL)
					{
						delete node;
						parent->left = NULL;
					}
					break;
				}
				else if (brother->left && brother->left->color == 0) {
					rbtree* broleft = brother->left;
					right_rotate(brother);
					left_rotate(parent);
					broleft->color = parent->color;
					parent->color = 1;
					brother->color = 1;
					if (node->left == NULL && node->right == NULL) {
						delete node;
						parent->left = NULL;
					}
					break;
				}
				else if (parent->color == 0) {
					parent->color = 1;
					brother->color = 0;
					if (node->left == NULL && node->right == NULL) {
						delete node;
						parent->left = NULL;
					}
					break;
				}
				else {
					brother->color = 0;
					if (node->left == NULL && node->right == NULL) {
						delete node;
						parent->left = NULL;
					}
					node = parent;
					parent = node->parent;
				}
			}
			else {
				if (brother->left && brother->left->color == 0) {
					rbtree* broleft = brother->left;
					right_rotate(parent);
					brother->color = parent->color;
					parent->color = 1;
					broleft->color = 1;
					if (node->left == NULL && node->right == NULL) {
						delete node;
						parent->right = NULL;
					}
					break;
				}
				else if (brother->right && brother->right->color == 0) {
					rbtree* broright = brother->right;
					left_rotate(brother);
					right_rotate(parent);
					broright->color = parent->color;
					parent->color = 1;
					brother->color = 1;
					if (node->left == NULL && node->right == NULL) {
						delete node;
						parent->right = NULL;
					}
					break;
				}
				else if (parent->color == 0) {
					parent->color = 1;
					brother->color = 0;
					if (node->left == NULL && node->right == NULL) {
						delete node;
						parent->right = NULL;
					}
					break;
				}
				else {
					brother->color = 0;
					if (node->right == NULL && node->left == NULL) {
						delete node;
						parent->right = NULL;
					}
					node = parent;
					parent = node->parent;
				}
			}
		}
		else {
			if (node == parent->left) {
				left_rotate(parent);
				brother->color = 1;
				parent->color = 0;
			}
			else {
				right_rotate(parent);
				brother->color = 1;
				parent->color = 0;
			}
		}
	}
	return;
}
void del(rbtree* node, int m) {
	if (m == node->val) {
		tree_balance(node);
	}
	else {
		if (m > node->val && node->right) {
			del(node->right, m);
		}
		else if (m < node->val && node->left) {
			del(node->left, m);
		}
	}
}
char getcolor(int m) {
	char a;
	m == 1 ? a = 'B' : a = 'R';
	return a;
}
void tree_print(rbtree* node) {
	if (node == NULL) {
		cout << "Null";
	}
	else {
		cout << node->val << "(" << getcolor(node->color) << ")" << " ";
		if (node->left != NULL) {
			tree_print(node->left);
		}
		if (node->right != NULL) {
			tree_print(node->right);
		}
	}
}
int main() {
	int n;
	cin >> n;
	head = NULL;
	if (n > 0) {
		head = new rbtree;
		cin >> head->val;
		head->left = NULL;
		head->right = NULL;
		head->parent = NULL;
		head->color = 1;
	}
	for (int i = 1; i < n; i++) {
		int t;
		cin >> t;
		insert(head, t, NULL);
		tree_insert(cur);
	}
	tree_print(head);
	cout << endl;
	int min, max;
	if (head) {
		min = head->val; max = head->val;
		rbtree* pointer = head;
		while (pointer->left) {
			pointer = pointer->left;
			min = pointer->val;
		}
		pointer = head;
		while (pointer->right) {
			pointer = pointer->right;
			max = pointer->val;
		}
		cout << min << " " << max << endl;
	}
	else cout << 0 << " " << 0 << endl;
	int m;
	cin >> m;
	int* b = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		del(head, b[i]);
	}
	tree_print(head);
	return 0;
}