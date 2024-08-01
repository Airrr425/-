#include <iostream>
using namespace std;
struct ListNode {
    char val;
    ListNode* next;
    ListNode(char x) : val(x), next(NULL) {}
};
int getLength(ListNode* head) {
    int count = 0;
    ListNode* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}
ListNode* findCommonSuffixStart(ListNode* str1, ListNode* str2) {
    int len1 = getLength(str1);
    int len2 = getLength(str2);
    ListNode* p1 = str1;
    ListNode* p2 = str2;
    if (len1 > len2) {            //计算两个单词相差长度，将后缀对齐
        int diff = len1 - len2;
        while (diff > 0) {
            p1 = p1->next;
            diff--;
        }
    }
    else if (len2 > len1) {
        int diff = len2 - len1;
        while (diff > 0) {
            p2 = p2->next;
            diff--;
        }
    }
    while (p1 != NULL && p2 != NULL) {
        if (p1 == p2) {         //寻找共同后缀
            return p1;      
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL;  // 没有共同后缀
}
int main() {
    ListNode* str1 = new ListNode('l');
    str1->next = new ListNode('o');
    str1->next->next = new ListNode('a');
    str1->next->next->next = new ListNode('d');
    str1->next->next->next->next = new ListNode('i');
    str1->next->next->next->next->next = new ListNode('n');
    str1->next->next->next->next->next->next = new ListNode('g');

    ListNode* str2 = new ListNode('b');
    str2->next = new ListNode('e');
    str2->next->next = new ListNode('i');
    str2->next->next->next = new ListNode('n');
    str2->next->next->next->next = new ListNode('g');

    ListNode* commonSuffixStart = findCommonSuffixStart(str1, str2);

    while (commonSuffixStart != NULL) {
        cout << commonSuffixStart->val << " ";
        commonSuffixStart = commonSuffixStart->next;
    }

    return 0;
}