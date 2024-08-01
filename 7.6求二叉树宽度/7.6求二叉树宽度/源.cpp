#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};
int getWidth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int maxWidth = 1;  // 记录最大宽度
    while (!q.empty()) {
        int size = q.size();
        maxWidth = max(maxWidth, size);  // 更新最大宽度
        for (int i = 0; i < size; i++) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
    return maxWidth;
}
int main() {
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->right = new TreeNode('C');
    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');
    root->right->left = new TreeNode('F');
    root->right->right = new TreeNode('G');
    int width = getWidth(root);
    cout << "二叉树的宽度为 " << width << endl;
    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}