#include<iostream>
#include<stack>
#include<queue>
#include<cctype>
#include<string>
using namespace std;
// 定义表达式树的节点结构
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c) : val(c), left(nullptr), right(nullptr) {}
};
// 判断字符是否为运算符
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
// 创建表达式树
TreeNode* buildExpressionTree(string expression) {
    stack<TreeNode*> st;
    for (char c : expression) {
        // 如果是数字或空格，则继续循环，直到遇到运算符
        if (isdigit(c) || c == ' ') {
            continue;
        }
        else if (isOperator(c)) {
            // 创建当前运算符的节点
            TreeNode* node = new TreeNode(c);
            // 将栈顶的节点作为右子节点
            node->right = st.top();
            st.pop();
            // 将栈顶的节点作为左子节点
            node->left = st.top();
            st.pop();
            // 将新创建的节点压入栈中
            st.push(node);
        }
        else if (c == '(') {
            // 遇到左括号，将字符本身作为节点入栈
            st.push(new TreeNode(c));
        }
        else if (c == ')') {
            // 遇到右括号，开始弹出栈中的节点并构建表达式树
            TreeNode* node = st.top();
            st.pop();
            while (st.top()->val != '(') {
                TreeNode* left = st.top();
                st.pop();
                TreeNode* op = st.top();
                st.pop();
                op->left = left;
                op->right = node;
                node = op;
            }
            // 弹出左括号
            st.pop();
            // 将构建好的子树的根节点放入栈中
            st.push(node);
        }
    }
    // 返回栈顶的节点，即为整棵表达式树的根节点
    return st.top();
}
// 前序遍历
void preorder(TreeNode* root) {
    if (root) {
        cout << root->val << ' ';
        preorder(root->left);
        preorder(root->right);
    }
}
// 中序遍历
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->val << ' ';
        inorder(root->right);
    }
}
// 后序遍历
void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << ' ';
    }
}
// 层次遍历
void levelOrder(TreeNode* root) {
    if (!root) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << ' ';
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
}
// 计算表达式树的值
int evaluateExpressionTree(TreeNode* root) {
    if (!root) {
        return 0;
    }
    if (isdigit(root->val)) {
        return root->val - '0';
    }
    int leftVal = evaluateExpressionTree(root->left);
    int rightVal = evaluateExpressionTree(root->right);
    switch (root->val) {
    case '+': return leftVal + rightVal;
    case '-': return leftVal - rightVal;
    case '*': return leftVal * rightVal;
    case '/': return leftVal / rightVal;
    }
    return 0;
}
int main() {
    string expression;
    cout << "请输入以=结尾的整数算术运算表达式：" << endl;
    getline(cin, expression, '=');

    // 构建表达式树
    TreeNode* root = buildExpressionTree(expression);

    cout << "前序遍历结果：";
    preorder(root);
    cout << "#" << endl;

    cout << "中序遍历结果：";
    inorder(root);
    cout << "#" << endl;

    cout << "后序遍历结果：";
    postorder(root);
    cout << "#" << endl;

    cout << "层次遍历结果：";
    levelOrder(root);
    cout << "#" << endl;

    cout << "计算结果：" << evaluateExpressionTree(root) << endl;

    return 0;
}