#include<iostream>
using namespace std;
struct Child {
	int no;
	Child* next;
	Child(int d):no(d),next(NULL){}
};
class Joseph
{
	int n, m;
	Child* first;
public:
	Joseph(int n1,int m1):n(n1),m(m1){}
	void CreateList()
	{
		first = new Child(1);
		Child* r = first, * p;
		for (int i = 2; i <= n; i++)
		{
			p = new Child(i);
			r->next = p;
			r = p;
		}
		r->next = first;
	}
	void Jsequence()
	{
		Child* p, * q;
		for (int i = 1; i <= n ; i++)
		{
			p = first;
			int j = 1;
			while (j != m)
			{
				j++; 
				p = p->next;
			}
			cout << p->no << " ";
			q = p->next;
			p->no = q->no;
			p->next = q->next;
			delete q;
			first = p;
		}
		cout << endl;
	}

};

int main() {
	int n = 6, m = 3;
	Joseph L(n, m);
	L.CreateList();
	L.Jsequence();
	return 0;
}