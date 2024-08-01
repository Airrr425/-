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
//检测字符串是否为数字
bool isNumber(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
//构建后缀表达式
string createPostfix(string str) {
    string postfix;   //存放后缀表达式
    stack<char> op;  //存放操作符
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
    // 构建表达式树
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
                    d = 10 * d + (c - '0');  //转化为整数
                    c = postfix[++i];
                }
                stack.push(new Tree(to_string(d)));  //将整数转化为字符串压入栈中
            }
            else {
                Tree* right = stack.top();
                stack.pop();
                Tree* left = stack.top();
                stack.pop();
                Tree* node = new Tree(string(1, c));   //创建一个表达式树的节点
                node->lchild = left;
                node->rchild = right;
                stack.push(node);
            }
            i++;
        }
        root = stack.top();  //最后压入栈中的节点作为根节点
    }
    // 前序遍历
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
    //中序遍历
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
    //后序遍历
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
    //层次遍历
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
    //计算表达式值
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
    //构建后缀表达式
    string str;
    getline(cin, str);
    string postfix = createPostfix(str);
    //构建二叉树
    ExpressionTree tree;
    tree.buildTree(postfix);
    //前序遍历
    tree.preOrder(tree.root);
    cout << endl;
    //中序遍历
    tree.inOrder(tree.root);
    cout << endl;
    //后序遍历
    tree.postOrder(tree.root);
    cout << endl;
    //层次遍历
    tree.levelOrder(tree.root);
    cout << endl;
    cout << tree.caculate(tree.root);
}
