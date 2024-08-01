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
    TreeNode* root = new TreeNode(level[0]);  // level���еĵ�һ���ַ�Ϊ���ڵ�
    int rootIndex = -1;  // ���ڵ���in�����е�����
    for (int i = 0; i < inSize; i++) {
        if (in[i] == level[0]) {
            rootIndex = i;
            break;
        }
    }
    if (rootIndex == -1) {
        return nullptr;
    }
    int leftSize = rootIndex;  // �������Ľ������
    int rightSize = inSize - rootIndex - 1;  // �������Ľ������
    char* leftLevel = new char[leftSize];  // ��������level����
    char* leftIn = new char[leftSize];  // ��������in����
    char* rightLevel = new char[rightSize];  // ��������level����
    char* rightIn = new char[rightSize];  // ��������in����
    int leftIndex = 0;  // ������������
    int rightIndex = 0;  // ������������
    for (int i = 1; i < levelSize; i++) {
        int inIndex = -1;  // ��ǰ�ַ���in�����е�����
        for (int j = 0; j < inSize; j++) {
            if (in[j] == level[i]) {
                inIndex = j;
                break;
            }
        }
        if (inIndex != -1 && inIndex < rootIndex) {  // ����������
            leftLevel[leftIndex] = level[i];
            leftIn[leftIndex] = in[inIndex];
            leftIndex++;
        }
        if (inIndex != -1 && inIndex > rootIndex) {  // ����������
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
    // �ͷ��ڴ�
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}