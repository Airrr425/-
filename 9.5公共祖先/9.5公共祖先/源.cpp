#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 找出任意两个不同节点x和y的最近公共祖先（LCA）函数
TreeNode* findLCA(TreeNode* root, int x, int y) {
    // 当前节点为空或者是x或y节点，直接返回当前节点
    if (root == nullptr || root->val == x || root->val == y) {
        return root;
    }

    // 在左子树中递归查找x和y的LCA
    TreeNode* left = findLCA(root->left, x, y);

    // 在右子树中递归查找x和y的LCA
    TreeNode* right = findLCA(root->right, x, y);

    // 如果左右子树的查找结果都不为空，说明当前节点是最近公共祖先
    if (left != nullptr && right != nullptr) {
        return root;
    }
    // 否则返回不为空的那个结果，即x和y中存在的节点
    else if (left != nullptr) {
        return left;
    }
    else {
        return right;
    }
}
// 向二叉排序树中插入新节点的函数
TreeNode* insertNode(TreeNode* root, int val) {
    // 如果当前节点为空，说明找到了插入位置，创建新节点并返回
    if (root == nullptr) {
        return new TreeNode(val);
    }

    // 如果插入值小于当前节点的值，递归插入到左子树中
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    }
    // 否则递归插入到右子树中
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
    // 找出最近公共祖先
    int x = 2;
    int y = 5;
    TreeNode* lcaNode = findLCA(root, x, y);
    cout << "最近公共祖先的值为：" << lcaNode->val << endl;
    return 0;
}