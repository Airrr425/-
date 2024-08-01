#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// �ҳ�����������ͬ�ڵ�x��y������������ȣ�LCA������
TreeNode* findLCA(TreeNode* root, int x, int y) {
    // ��ǰ�ڵ�Ϊ�ջ�����x��y�ڵ㣬ֱ�ӷ��ص�ǰ�ڵ�
    if (root == nullptr || root->val == x || root->val == y) {
        return root;
    }

    // ���������еݹ����x��y��LCA
    TreeNode* left = findLCA(root->left, x, y);

    // ���������еݹ����x��y��LCA
    TreeNode* right = findLCA(root->right, x, y);

    // ������������Ĳ��ҽ������Ϊ�գ�˵����ǰ�ڵ��������������
    if (left != nullptr && right != nullptr) {
        return root;
    }
    // ���򷵻ز�Ϊ�յ��Ǹ��������x��y�д��ڵĽڵ�
    else if (left != nullptr) {
        return left;
    }
    else {
        return right;
    }
}
// ������������в����½ڵ�ĺ���
TreeNode* insertNode(TreeNode* root, int val) {
    // �����ǰ�ڵ�Ϊ�գ�˵���ҵ��˲���λ�ã������½ڵ㲢����
    if (root == nullptr) {
        return new TreeNode(val);
    }

    // �������ֵС�ڵ�ǰ�ڵ��ֵ���ݹ���뵽��������
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    }
    // ����ݹ���뵽��������
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
    // �ҳ������������
    int x = 2;
    int y = 5;
    TreeNode* lcaNode = findLCA(root, x, y);
    cout << "����������ȵ�ֵΪ��" << lcaNode->val << endl;
    return 0;
}