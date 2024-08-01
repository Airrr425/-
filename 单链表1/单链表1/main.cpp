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

	void printLinkNode() {     //�������ӡ
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
		LinkNode* p = head->next;     //pָ������ĵ�һ���ڵ�
		LinkNode* pa = A.head;
		LinkNode* pb = B.head;
		while (p != NULL) {      
			if (p->data % 2 == 0) {
				pa->next = p;          //���ڵ��е�����Ϊż��ʱ����pָ��ڵ㸴�Ƶ�A��
				pa = pa->next;
			}
			else {
				pb->next = p;          //������Ϊ����ʱ�����Ƶ�B��
				pb = pb->next;
			}
			p = p->next;
		}
		pa->next = NULL;               //��pָ��β�ڵ�ʱ��ֹͣ����
		pb->next = NULL;
	}
	void SortList() {
		LinkNode* prev = NULL;
		LinkNode* curr = head->next;   //���ڱ�ʾ��ǰԪ��
		while (curr != NULL) {
			if (curr->data < 0) {
				if (prev != NULL) {
					prev->next = curr->next;     //����ǰ�ڵ�С����ʱ������һ���ڵ�����һ���ڵ�����
					curr->next = head->next;     //����ǰС����Ľڵ���ͷ�ڵ��һ���ڵ�����
					head->next = curr;           //����ǰС����Ľڵ�������ͷ�ڵ��
					curr = prev->next;           //��ָ��ָ����һ���ڵ�
				}
				else {
					curr = curr->next;
					continue;
				}
			}
			else {
				prev = curr;           //��ǰ�ڵ������ʱ��currָ���ƶ�����һ���ڵ㣬prevָ����һ���ڵ�
				curr = curr->next;
			}
		}
	}
	int FindMaxNode() {
		LinkNode* p = head->next;
		int maxData = INT_MIN;
		int count = 0;        //��ס���
		int maxIndex = -1;
		while (p != NULL) {
			count++;
			if (p->data >= maxData) {
				maxData = p->data;         //����ǰ�ڵ����maxʱ����ֵ����max
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
			curr->next = prev;      //�ı�ָ��ָ��
			prev = curr;           //��˳����ǰ����
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
					cur->next = L1;    //��L1�е�ֵ������ǰ��չ�Ľڵ�
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

		if (L1 != NULL) {        //��L1��L2��ֵΪ��ʱ�������ϲ�
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
	mergedList.CreatListF(NULL, 0);  // ����һ��������
	mergedList.head->next = mergedList.mergeLists(L1.head->next, L2.head->next);  // ���ϲ��������ֵ��mergedList
	cout << "Merged List: ";
	mergedList.printLinkNode();
	return 0;
}