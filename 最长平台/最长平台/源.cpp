#include<iostream>
using namespace std;
struct Node {       
	char data;
	Node* next;
};
int maxLengthOfPlatform(Node* head) {
	if (head == NULL || head->next == NULL) {   //如果只有一个节点或没有节点，长度为零
		return 0;
	}
	Node* p = head->next;  //指向第一个节点
	int maxlength = 0;
	int currentlength = 0;
	while (p->next != NULL) {
		if (p->data == p->next->data) {
			currentlength++;
		}
		else
		{
			currentlength = 1;
		}
		p = p->next;
	}
	maxlength = max(maxlength, currentlength);
	return maxlength;
}
int main() {
	Node* head = new Node();
	Node* p = head;
	string s = "acfafeifhoieoadjiaaa";
	for (char c : s) {
		Node* newNode = new Node();
		newNode->data = c;
		newNode->next = NULL;
		p->next = newNode;
		p = p->next;
	}
	int max = maxLengthOfPlatform(head);
	cout << max << endl;

}