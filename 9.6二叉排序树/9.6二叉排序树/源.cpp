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

    // 遍历左子树
    printNodes(root->left, k);

    // 输出当前节点值小于等于k的节点值
    if (root->val <= k) {
        cout << root->val << " ";
    }

    // 遍历右子树
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

    int k = 5;
    cout << "小于等于" << k << "的节点序列为：";
    printNodes(root, k);
    cout << endl;

    return 0;
}