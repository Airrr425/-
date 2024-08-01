#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// ��������������ȼ�
int getPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// ����׺���ʽת��Ϊ�沨�����ʽ
vector<string> infixToPostfix(const string& infix) {
    vector<string> postfix;
    stack<char> operators;  

    for (size_t i = 0; i < infix.length(); i++) {
        if (isdigit(infix[i])) {
            string num;
            while (i < infix.length() && (isdigit(infix[i]) || infix[i] == ' ')) {
                if (infix[i] != ' ') {
                    num += infix[i];
                }
                i++;
            }
            postfix.push_back(num);
            i--;
        }
        else if (infix[i] == '(') {
            operators.push('(');
        }
        else if (infix[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.pop(); // ����������
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!operators.empty() && operators.top() != '(' && getPriority(operators.top()) >= getPriority(infix[i])) {
                postfix.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.push(infix[i]);
        }
    }

    while (!operators.empty()) {
        postfix.push_back(string(1, operators.top()));
        operators.pop();
    }

    return postfix;
}

// �����沨�����ʽ
int evaluatePostfix(const vector<string>& postfix) {
    stack<int> operands;

    for (const string& token : postfix) {
        if (isdigit(token[0])) {
            operands.push(stoi(token));
        }
        else {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            if (token == "+") {
                operands.push(a + b);
            }
            else if (token == "-") {
                operands.push(a - b);
            }
            else if (token == "*") {
                operands.push(a * b);
            }
            else if (token == "/") {
                operands.push(a / b);
            }
        }
    }

    return operands.top();
}

int main() {
    string infix;
    getline(cin, infix, '=');
    vector<string> postfix = infixToPostfix(infix);
    int result = evaluatePostfix(postfix);
    cout << postfix[1] << postfix[4] << endl;
    cout << result << endl;
    return 0;
}