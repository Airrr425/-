#include<iostream>
using namespace std;
struct HNode {
	int key;
	int value;
	HNode* next;
	HNode(){}
	HNode(int k, int v) {
		key = k;
		value = v;
		next = NULL;
	}
};
#define MAXM 100
class HashTable2 {
	int n; int m;
	HNode* ha[MAXM];
public:
	HashTable2(int m) {
		this->m = m;
		for (int i = 0; i < m; i++) {
			ha[i] = NULL;
		}
		n = 0;
	}
	~HashTable2() {
		HNode* pre, * p;
		for (int i = 0; i < m; i++) {
			pre = ha[i];
			if (pre != NULL) {
				p = pre->next;
				while (p != NULL) {
					delete pre;
					pre = p; p = p->next;
				}
				delete pre;
			}
		}
		delete[] ha;
	}
	void insert(int k, int v) {
		int d = k % m;
		HNode* p;
		p = new HNode(k, v);
		p->next = ha[d];
		ha[d] = p;
		n++;
	}
	void remove(int k) {
		int d = k % m;
		HNode* pre = nullptr;
		HNode* p = ha[d];

		while (p != nullptr) {
			if (p->key == k) {
				if (pre == nullptr) {
					ha[d] = p->next;
				}
				else {
					pre->next = p->next;
				}
				delete p;
				n--;
				return;
			}

			pre = p;
			p = p->next;
		}

		cout << "关键字" << k << "不存在" << endl;
	}
};
int main() {
	HashTable2 hashtable(5);

	hashtable.insert(10, 100);
	hashtable.insert(15, 150);
	hashtable.insert(20, 200);

	hashtable.remove(15);
	hashtable.remove(25); // 不存在的关键字，会输出提示信息

	return 0;
}