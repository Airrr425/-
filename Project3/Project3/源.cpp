#include<iostream>
using namespace std;

typedef struct LNode
{    int data;
struct LNode* next;
} LinkNode;
int search_k(LinkNode* L, int k, int& e) {
    LinkNode* fast = L;     // ��ָ�룬����ǰ�ƶ�k��λ��
    LinkNode* slow = L;     // ��ָ�룬������ͷ��ʼ�ƶ�
    int count = 0;         // �����������ڼ�¼����ָ��֮���λ�ò�

    // ��ָ������ǰ�ƶ�k��λ��
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) {
            return 0;   // ��������С��k�����ؽ��0��ʾ����ʧ��
        }
        fast = fast->next;
    }

    // ����ָ��ͬʱ��ǰ�ƶ���ֱ����ָ�뵽������ĩβ
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
        count++;
    }

    // �жϼ������Ƿ����k�����������ҵ�������k�����
    if (count == k) {
        e = slow->data;
        return 1;     // ���ؽ��1��ʾ���ҳɹ���ͬʱ���ؽ���dataֵ
    }
    else {
        return 0;     // ��������������k����ʾ������С��k�����ؽ��0��ʾ����ʧ��
    }
}
int main() {
    // ����������ʼ��
    LinkNode* head = new LinkNode;
    LinkNode* node1 = new LinkNode;
    LinkNode* node2 = new LinkNode;
    LinkNode* node3 = new LinkNode;
    head->data = 10;
    head->next = node1;
    node1->data = 20;
    node1->next = node2;
    node2->data = 30;
    node2->next = node3;
    node3->data = 40;
    node3->next = nullptr;
    // ���ò��Һ������в���
    int result;    // ���ڴ洢���ҽ��
    int position = 1;   // Ҫ���ҵ�λ��
    int searchResult = search_k(head, position, result);
    // ���ݲ��ҽ�������Ӧ��Ϣ
    if (searchResult == 1) {
        std::cout << "���ҳɹ����� " << position << " ��λ�õĽڵ��ֵ�ǣ�" << result << std::endl;
    }
    else {
        std::cout << "����ʧ�ܣ��� " << position << " ��λ�ò����ڽڵ㣡" << std::endl;
    }
    // �ͷ�����ڵ���ڴ�
    delete node3;
    delete node2;
    delete node1;
    delete head;
    return 0;
}