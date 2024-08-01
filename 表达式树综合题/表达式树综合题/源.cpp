#include<iostream>
#include<stack>;
#include<queue>;
#include <string>
using namespace std;

struct Tree {
    string data;
    Tree* lchild;
    Tree* rchild;
    Tree() :lchild(NULL), rchild(NULL) {};
    Tree(string d) {
        data = d;
        lchild = rchild = NULL;
    }
};
//����ַ����Ƿ�Ϊ����
bool isNumber(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
//������׺���ʽ
string createPostfix(string str) {
    string postfix;   //��ź�׺���ʽ
    stack<char> op;  //��Ų�����
    char c;
    int strLength = str.length();
    for (int i = 0; i < strLength; i++) {
        c = str[i];
        if (c == '=') {
            break;
        }
        else if (c == '(') {
            op.push(c);
        }
        else if (c == ')') {
            while (!op.empty() && op.top() != '(') {
                postfix += op.top();
                op.pop();
            }
            op.pop();
        }
        else if (c == '+' || c == '-') {
            while (!op.empty() && op.top() != '(') {
                postfix += op.top();
                op.pop();
            }
            op.push(c);
        }
        else if (c == '*' || c == '/') {
            while (!op.empty() && op.top() != '(' && (op.top() == '*' || op.top() == '/')) {
                postfix += op.top();
                op.pop();
            }
            op.push(c);
        }
        else {
            while (c >= '0' && c <= '9') {
                postfix += c;
                c = str[++i];
            }
            i--;
            postfix += '#';
        }
    }
    while (!op.empty()) {
        postfix += op.top();
        op.pop();
    }
    return postfix;
}
class ExpressionTree {
public:
    Tree* root;
    ExpressionTree() {
        root = NULL;
    }
    // �������ʽ��
    void buildTree(string postfix) {
        int i = 0;
        char c;
        stack<Tree*> stack;
        int postfixLength = postfix.length();
        while (i < postfixLength) {
            c = postfix[i];
            if (isdigit(c)) {
                int d = 0;
                while (c >= '0' && c <= '9') {
                    d = 10 * d + (c - '0');  //ת��Ϊ����
                    c = postfix[++i];
                }
                stack.push(new Tree(to_string(d)));  //������ת��Ϊ�ַ���ѹ��ջ��
            }
            else {
                Tree* right = stack.top();
                stack.pop();
                Tree* left = stack.top();
                stack.pop();
                Tree* node = new Tree(string(1, c));   //����һ�����ʽ���Ľڵ�
                node->lchild = left;
                node->rchild = right;
                stack.push(node);
            }
            i++;
        }
        root = stack.top();  //���ѹ��ջ�еĽڵ���Ϊ���ڵ�
    }
    // ǰ�����
    void preOrder(Tree* node) {
        if (node != NULL) {
            cout << node->data;
            if (isNumber(node->data)) {
                cout << "#";
            }
            preOrder(node->lchild);
            preOrder(node->rchild);
        }
    }
    //�������
    void inOrder(Tree* node) {
        if (node != NULL) {
            inOrder(node->lchild);
            cout << node->data;
            if (isNumber(node->data)) {
                cout << "#";
            }
            inOrder(node->rchild);
        }
    }
    //�������
    void postOrder(Tree* node) {
        if (node != NULL) {
            postOrder(node->lchild);
            postOrder(node->rchild);
            cout << node->data;
            if (isNumber(node->data)) {
                cout << "#";
            }
        }
    }
    //��α���
    void levelOrder(Tree* root) {
        if (root == NULL) {
            return;
        }
        queue<Tree*> q;
        q.push(root);
        while (!q.empty()) {
            Tree* node = q.front();
            q.pop();
            cout << node->data;
            if (isNumber(node->data)) {
                cout << "#";
            }
            if (node->lchild != NULL) {
                q.push(node->lchild);
            }
            if (node->rchild != NULL) {
                q.push(node->rchild);
            }
        }
    }
    //������ʽֵ
    int caculate(Tree* root) {
        if (root == NULL) {
            return 0;
        }
        if (isNumber(root->data)) {
            return stoi(root->data);
        }
        int left = caculate(root->lchild);
        int right = caculate(root->rchild);
        if (root->data == "+") {
            return left + right;
        }
        else if (root->data == "-") {
            return left - right;
        }
        else if (root->data == "*") {
            return left * right;
        }
        else if (root->data == "/") {
            if (right != 0) {
                return left / right;
            }

        }
        return 0;
    }
};
int main() {
    //������׺���ʽ
    string str;
    getline(cin, str);
    string postfix = createPostfix(str);
    //����������
    ExpressionTree tree;
    tree.buildTree(postfix);
    //ǰ�����
    tree.preOrder(tree.root);
    cout << endl;
    //�������
    tree.inOrder(tree.root);
    cout << endl;
    //�������
    tree.postOrder(tree.root);
    cout << endl;
    //��α���
    tree.levelOrder(tree.root);
    cout << endl;
    cout << tree.caculate(tree.root);
}
