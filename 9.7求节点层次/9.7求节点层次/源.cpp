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

    // 如果当前节点的值等于k，返回当前层次
    if (root->val == k) {
        return level;
    }

    // 递归查找左子树
    int leftLevel = findNodeLevel(root->left, k, level + 1);

    // 如果左子树中找到了节点，直接返回层次
    if (leftLevel != 0) {
        return leftLevel;
    }

    // 递归查找右子树
    int rightLevel = findNodeLevel(root->right, k, level + 1);

    // 如果右子树中找到了节点，直接返回层次
    if (rightLevel != 0) {
        return rightLevel;
    }

    // 如果左右子树都没有找到节点，返回0
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

    // 构建二叉排序树
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

    cout << "关键字" << k << "的层次为：" << level << endl;

    return 0;
}