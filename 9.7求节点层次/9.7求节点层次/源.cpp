#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int findNodeLevel(TreeNode* root, int k, int level) {
    if (root == nullptr) {
        return 0;
    }

    // �����ǰ�ڵ��ֵ����k�����ص�ǰ���
    if (root->val == k) {
        return level;
    }

    // �ݹ����������
    int leftLevel = findNodeLevel(root->left, k, level + 1);

    // ������������ҵ��˽ڵ㣬ֱ�ӷ��ز��
    if (leftLevel != 0) {
        return leftLevel;
    }

    // �ݹ����������
    int rightLevel = findNodeLevel(root->right, k, level + 1);

    // ������������ҵ��˽ڵ㣬ֱ�ӷ��ز��
    if (rightLevel != 0) {
        return rightLevel;
    }

    // �������������û���ҵ��ڵ㣬����0
    return 0;
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

    int k = 7;
    int level = findNodeLevel(root, k, 1);

    cout << "�ؼ���" << k << "�Ĳ��Ϊ��" << level << endl;

    return 0;
}