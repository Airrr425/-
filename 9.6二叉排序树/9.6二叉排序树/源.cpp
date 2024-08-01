#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void printNodes(TreeNode* root, int k) {
    if (root == nullptr) {
        return;
    }

    // ����������
    printNodes(root->left, k);

    // �����ǰ�ڵ�ֵС�ڵ���k�Ľڵ�ֵ
    if (root->val <= k) {
        cout << root->val << " ";
    }

    // ����������
    printNodes(root->right, k);
}
TreeNode* insertNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insertNode(root->left, val);
    }
    else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }

    return root;
}
int main() {
    TreeNode* root = nullptr;

    // ��������������
    root = insertNode(root, 6);
    insertNode(root, 2);
    insertNode(root, 8);
    insertNode(root, 0);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 9);
    insertNode(root, 3);
    insertNode(root, 5);

    int k = 5;
    cout << "С�ڵ���" << k << "�Ľڵ�����Ϊ��";
    printNodes(root, k);
    cout << endl;

    return 0;
}