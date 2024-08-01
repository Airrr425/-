#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};
int getMinDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
        depth++;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left == nullptr && current->right == nullptr) {
                return depth;  // 找到最近叶子节点，返回深度
            }
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
    return depth;
}
int main() {
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->right = new TreeNode('C');
    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');
    root->left->left->left = new TreeNode('F');
    int minDepth = getMinDepth(root);
    cout << "The minimum depth of the binary tree is: " << minDepth << endl;
    // 释放内存
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}