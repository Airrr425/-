#include<iostream>
#include<stack>
#include<queue>
#include<cctype>
#include<string>
using namespace std;
// ������ʽ���Ľڵ�ṹ
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c) : val(c), left(nullptr), right(nullptr) {}
};
// �ж��ַ��Ƿ�Ϊ�����
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
// �������ʽ��
TreeNode* buildExpressionTree(string expression) {
    stack<TreeNode*> st;
    for (char c : expression) {
        // ��������ֻ�ո������ѭ����ֱ�����������
        if (isdigit(c) || c == ' ') {
            continue;
        }
        else if (isOperator(c)) {
            // ������ǰ������Ľڵ�
            TreeNode* node = new TreeNode(c);
            // ��ջ���Ľڵ���Ϊ���ӽڵ�
            node->right = st.top();
            st.pop();
            // ��ջ���Ľڵ���Ϊ���ӽڵ�
            node->left = st.top();
            st.pop();
            // ���´����Ľڵ�ѹ��ջ��
            st.push(node);
        }
        else if (c == '(') {
            // ���������ţ����ַ�������Ϊ�ڵ���ջ
            st.push(new TreeNode(c));
        }
        else if (c == ')') {
            // ���������ţ���ʼ����ջ�еĽڵ㲢�������ʽ��
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
            // ����������
            st.pop();
            // �������õ������ĸ��ڵ����ջ��
            st.push(node);
        }
    }
    // ����ջ���Ľڵ㣬��Ϊ���ñ��ʽ���ĸ��ڵ�
    return st.top();
}
// ǰ�����
void preorder(TreeNode* root) {
    if (root) {
        cout << root->val << ' ';
        preorder(root->left);
        preorder(root->right);
    }
}
// �������
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->val << ' ';
        inorder(root->right);
    }
}
// �������
void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << ' ';
    }
}
// ��α���
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
// ������ʽ����ֵ
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
    cout << "��������=��β����������������ʽ��" << endl;
    getline(cin, expression, '=');

    // �������ʽ��
    TreeNode* root = buildExpressionTree(expression);

    cout << "ǰ����������";
    preorder(root);
    cout << "#" << endl;

    cout << "������������";
    inorder(root);
    cout << "#" << endl;

    cout << "������������";
    postorder(root);
    cout << "#" << endl;

    cout << "��α��������";
    levelOrder(root);
    cout << "#" << endl;

    cout << "��������" << evaluateExpressionTree(root) << endl;

    return 0;
}