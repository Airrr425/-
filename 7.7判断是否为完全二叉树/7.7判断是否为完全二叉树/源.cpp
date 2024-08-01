#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};
bool isCompleteTree(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    queue<TreeNode*> q;
    q.push(root);
    bool flag = false;  // 标记是否遇到非满结点
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (current == nullptr) {
            flag = true;
        }
        else {
            if (flag) {  // 如果已遇到非满结点，但当前节点不为空
                return false;
            }
            q.push(current->left);  // 左子节点入队
            q.push(current->right);  // 右子节点入队
        }
    }
    return true;
}
int main() {
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    //root->right = new TreeNode('C');
    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');
    //root->right->left = new TreeNode('F');
    //root->right->right = new TreeNode('G');
    bool isComplete = isCompleteTree(root);
    if (isComplete) {
        cout << "是完全二叉树" << endl;
    }
    else {
        cout << "不是完全二叉树" << endl;
    }
    // 释放内存
    delete root->left->left;
    delete root->left->right;
    //delete root->right->left;
//    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}