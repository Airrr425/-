#include <iostream>
using namespace std;
struct BinaryTreeNode {
    char data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};
bool isSymmetric(BinaryTreeNode* root1, BinaryTreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr)    // �ݹ���ֹ����
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    // �ݹ��ж����������������������������������������������������������������Ƿ�Գ�
    return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
}
bool isTreeSymmetric(BinaryTreeNode* root) {
    if (root == nullptr)
        return true;
    // ����isSymmetric�����ж����������������Ƿ�Գ�
    return isSymmetric(root->left, root->right);
}
int main() {
    BinaryTreeNode* root = new BinaryTreeNode{ 'A' };
    root->left = new BinaryTreeNode{ 'B' };
    root->right = new BinaryTreeNode{ 'C' };
    root->left->left = new BinaryTreeNode{ 'D' };
    root->left->right = new BinaryTreeNode{ 'E' };
    root->right->left = new BinaryTreeNode{ 'F' };
    root->right->right = new BinaryTreeNode{'G'};
    if (isTreeSymmetric(root))
        cout << "�������ǶԳƵ�" << endl;
    else
        cout << "���������ǶԳƵ�" << endl;
    // �ͷ��ڴ�
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    //delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}