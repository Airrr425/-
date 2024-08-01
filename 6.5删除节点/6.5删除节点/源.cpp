#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
void delx(ListNode*& p, int x) {
    if (p == NULL) {
        return;
    }
    if (p->val == x) {
        ListNode* temp = p;
        p = p->next;
        delete temp;
        return;
    }
    delx(p->next, x);
}
void printList(ListNode* p) {
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
int main() {
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    cout << "Before deletion: ";
    printList(head);
    int x = 3;
    delx(head, x);
    cout << "After deletion: ";
    printList(head);
    return 0;
}