#include<iostream>
using namespace std;
struct LinkNode
{
	int data;
	LinkNode* next;
	LinkNode* head;
	LinkNode() :next(NULL) {}
	LinkNode(int d) : data(d),next(NULL) {};
};
class LinkList
{
public:
	LinkNode* head;
	LinkList() {
		head = new LinkNode();
	}
	void CreatListF(int a[], int n) {
		LinkNode* s, * r;
		r = head;
		for (int i = 0; i < n; i++)
		{
			s = new LinkNode(a[i]);
			r->next = s;
			r = s;
		}
		r->next = NULL;
	}

	void printLinkNode() {     //将链表打印
		LinkNode* p;
		p = head->next;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

	void splitList(LinkList& A, LinkList& B) {
		LinkNode* p = head->next;     //p指向单链表的第一个节点
		LinkNode* pa = A.head;
		LinkNode* pb = B.head;
		while (p != NULL) {      
			if (p->data % 2 == 0) {
				pa->next = p;          //当节点中的数据为偶数时，将p指向节点复制到A中
				pa = pa->next;
			}
			else {
				pb->next = p;          //当数据为奇数时，复制到B中
				pb = pb->next;
			}
			p = p->next;
		}
		pa->next = NULL;               //当p指导尾节点时，停止复制
		pb->next = NULL;
	}
	void SortList() {
		LinkNode* prev = NULL;
		LinkNode* curr = head->next;   //用于表示当前元素
		while (curr != NULL) {
			if (curr->data < 0) {
				if (prev != NULL) {
					prev->next = curr->next;     //当当前节点小于零时，将下一个节点与上一个节点相连
					curr->next = head->next;     //将当前小于零的节点与头节点后一个节点相连
					head->next = curr;           //将当前小于零的节点连接在头节点后
					curr = prev->next;           //将指针指向下一个节点
				}
				else {
					curr = curr->next;
					continue;
				}
			}
			else {
				prev = curr;           //当前节点大于零时，curr指针移动到下一个节点，prev指向上一个节点
				curr = curr->next;
			}
		}
	}
	int FindMaxNode() {
		LinkNode* p = head->next;
		int maxData = INT_MIN;
		int count = 0;        //记住序号
		int maxIndex = -1;
		while (p != NULL) {
			count++;
			if (p->data >= maxData) {
				maxData = p->data;         //当当前节点大于max时，将值赋给max
				maxIndex = count;
			}
			p = p->next;
		}
		return maxIndex;
	}
	void ReverseList() {
		if (head == NULL || head->next == NULL) {
			return;
		}
		LinkNode* prev = NULL;
		LinkNode* curr = head->next;
		LinkNode* next = NULL;
		while (curr != NULL) {
			next = curr->next;
			curr->next = prev;      //改变指针指向
			prev = curr;           //按顺序往前遍历
			curr = next;
		}
		head->next = prev;
	}
	LinkNode* mergeLists(LinkNode* L1, LinkNode* L2) {
		if (L1 == NULL) return L2;
		if (L2 == NULL) return L1;

		LinkNode* mergedList = NULL;
		LinkNode* cur = NULL;

		while (L1 != NULL && L2 != NULL) {
			if (L1->data <= L2->data) {
				if (mergedList == NULL) {
					mergedList = L1;        
					cur = L1;
				}
				else {
					cur->next = L1;    //将L1中的值赋给当前扩展的节点
					cur = cur->next;
				}
				L1 = L1->next;
			}
			else {
				if (mergedList == NULL) {
					mergedList = L2;
					cur = L2;
				}
				else {
					cur->next = L2;
					cur = cur->next;
				}
				L2 = L2->next;
			}
		}

		if (L1 != NULL) {        //当L1，L2的值为空时，结束合并
			cur->next = L1;
		}
		if (L2 != NULL) {
			cur->next = L2;
		}

		return mergedList;
	}
};


int main() {
	int n = 6;
	int a[] = { 1,3,6,9 };
	int b[] = { 2,4,7,8 };
	LinkList L1,L2,L;
	L1.CreatListF(a, 4);
	L2.CreatListF(b, 4);
	L1.printLinkNode();
	L2.printLinkNode();
	LinkList mergedList;
	mergedList.CreatListF(NULL, 0);  // 创建一个空链表
	mergedList.head->next = mergedList.mergeLists(L1.head->next, L2.head->next);  // 将合并后的链表赋值给mergedList
	cout << "Merged List: ";
	mergedList.printLinkNode();
	return 0;
}