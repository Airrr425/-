#include<iostream>
using namespace std;

typedef struct LNode
{    int data;
struct LNode* next;
} LinkNode;
int search_k(LinkNode* L, int k, int& e) {
    LinkNode* fast = L;     // 快指针，先向前移动k个位置
    LinkNode* slow = L;     // 慢指针，从链表头开始移动
    int count = 0;         // 计数器，用于记录快慢指针之间的位置差

    // 快指针先向前移动k个位置
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) {
            return 0;   // 若链表长度小于k，返回结果0表示查找失败
        }
        fast = fast->next;
    }

    // 快慢指针同时向前移动，直到快指针到达链表末尾
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
        count++;
    }

    // 判断计数器是否等于k，若等于则找到倒数第k个结点
    if (count == k) {
        e = slow->data;
        return 1;     // 返回结果1表示查找成功，同时返回结点的data值
    }
    else {
        return 0;     // 若计数器不等于k，表示链表长度小于k，返回结果0表示查找失败
    }
}
int main() {
    // 创建链表并初始化
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
    // 调用查找函数进行查找
    int result;    // 用于存储查找结果
    int position = 1;   // 要查找的位置
    int searchResult = search_k(head, position, result);
    // 根据查找结果输出相应信息
    if (searchResult == 1) {
        std::cout << "查找成功，第 " << position << " 个位置的节点的值是：" << result << std::endl;
    }
    else {
        std::cout << "查找失败，第 " << position << " 个位置不存在节点！" << std::endl;
    }
    // 释放链表节点的内存
    delete node3;
    delete node2;
    delete node1;
    delete head;
    return 0;
}