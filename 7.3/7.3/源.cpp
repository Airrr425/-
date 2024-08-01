#include <iostream>
using namespace std;
struct BinaryTreeNode {
    char data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};
void printLeavesInReverseOrder(BinaryTreeNode* root) {
    if (root == nullptr)
        return;
    // ����������
    printLeavesInReverseOrder(root->right);
    // ����������
    printLeavesInReverseOrder(root->left);
    // ���Ҷ�ӽڵ�
    if (root->left == nullptr && root->right == nullptr)
        cout << root->data << " ";
}
int main() {
    BinaryTreeNode* root = new BinaryTreeNode('A');
    root->left = new BinaryTreeNode('B');
    root->right = new BinaryTreeNode('C');
    root->left->left = new BinaryTreeNode('D');
    root->left->right = new BinaryTreeNode('E');
    root->right->left = new BinaryTreeNode('F');
    root->right->right = new BinaryTreeNode('G');
    cout << "������Ҷ�ӽڵ㰴���ҵ���Ĵ��������" << endl;
    printLeavesInReverseOrder(root);
    // �ͷ��ڴ�
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}