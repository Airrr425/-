#include<iostream>
#include<fstream>
using namespace std;

typedef struct Tree {
    char data;
    Tree* lchild;
    Tree* rchild;
    Tree() :lchild(NULL), rchild(NULL) {};
    Tree(char d) {
        data = d;
        lchild = rchild = NULL;
    }
}TreeNode;

// 创建节点
TreeNode* createNode(TreeNode* node, char i) {   //0左子树1右子树
    switch (i) {
    case '0':
        if (node->lchild == NULL) {
            node->lchild = new TreeNode();
        }
        node = node->lchild;
        break;
    case '1':
        if (node->rchild == NULL) {
            node->rchild = new TreeNode();
        }
        node = node->rchild;
        break;
    }
    return node;
}

// 创建树
void createTree(TreeNode* root) {
    int codeNum;
    cin >> codeNum;
    for (int i = 0; i < codeNum; i++) {
        TreeNode* temp = root;
        char c1;
        string str;
        cin >> c1 ;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            temp = createNode(temp, str[j]);
        }
        temp->data = c1;  //叶节点设置值
    }
}
int main() {
    TreeNode* root = new TreeNode();    //创建树的根节点
    createTree(root);
    ifstream file; 
    file.open("in.txt");    //打开文件
    string code;
    while (!file.eof()) {
        file >> code;
    }
    file.close();
    TreeNode* temp = root;     //将temp初始化为根节点构建树
    for (int i = 0; i < code.size(); i++) {
        switch (code[i]) {
        case '0':
            temp = temp->lchild;
            break;      
        case '1':
            temp = temp->rchild;
            break;
        }
        if (temp->data) {
            cout << temp->data;
            temp = root;     //取出值后重置根节点
        }
    }
}