#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};
TreeNode* buildTree(char level[], char in[], int levelSize, int inSize) {
    if (levelSize == 0 || inSize == 0 || levelSize != inSize) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(level[0]);  // level序列的第一个字符为根节点
    int rootIndex = -1;  // 根节点在in序列中的索引
    for (int i = 0; i < inSize; i++) {
        if (in[i] == level[0]) {
            rootIndex = i;
            break;
        }
    }
    if (rootIndex == -1) {
        return nullptr;
    }
    int leftSize = rootIndex;  // 左子树的结点数量
    int rightSize = inSize - rootIndex - 1;  // 右子树的结点数量
    char* leftLevel = new char[leftSize];  // 左子树的level序列
    char* leftIn = new char[leftSize];  // 左子树的in序列
    char* rightLevel = new char[rightSize];  // 右子树的level序列
    char* rightIn = new char[rightSize];  // 右子树的in序列
    int leftIndex = 0;  // 左子树的索引
    int rightIndex = 0;  // 右子树的索引
    for (int i = 1; i < levelSize; i++) {
        int inIndex = -1;  // 当前字符在in序列中的索引
        for (int j = 0; j < inSize; j++) {
            if (in[j] == level[i]) {
                inIndex = j;
                break;
            }
        }
        if (inIndex != -1 && inIndex < rootIndex) {  // 在左子树中
            leftLevel[leftIndex] = level[i];
            leftIn[leftIndex] = in[inIndex];
            leftIndex++;
        }
        if (inIndex != -1 && inIndex > rootIndex) {  // 在右子树中
            rightLevel[rightIndex] = level[i];
            rightIn[rightIndex] = in[inIndex];
            rightIndex++;
        }
    }
    root->left = buildTree(leftLevel, leftIn, leftIndex, leftIndex);
    root->right = buildTree(rightLevel, rightIn, rightIndex, rightIndex);
    delete[] leftLevel;
    delete[] leftIn;
    delete[] rightLevel;
    delete[] rightIn;
    return root;
}
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int main() {
    char level[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C', 'G' };
    int levelSize = sizeof(level) / sizeof(level[0]);
    int inSize = sizeof(in) / sizeof(in[0]);
    TreeNode* root = buildTree(level, in, levelSize, inSize);
    cout << "Inorder traversal of the constructed binary tree: ";
    inorderTraversal(root);
    cout << endl;
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