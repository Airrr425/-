#include <iostream>
#include <stack>
#include <vector>
#include<string>
using namespace std;
string ans = "";    //��������
vector<string> railQuestion(vector<int> a) {
    stack<int> stack;   //��ʾ�м������
    vector<string> op;  //��¼����˳��
    for (int i = 0; i < a.size(); i++) {
        int x = a[i];
        if (x % 2 == 1) {
            stack.push(x);                  //���������ջ
            op.push_back("push");
        }
        else {                                   
            while (!stack.empty() && stack.top() % 2 == 1) {         //���Ҳ���Ϊż������ʱ����ջ��Ϊ�������ᣬ�򵯳��������ᣬ���������ż������
                int odd = stack.top();
                stack.pop();
                op.push_back("pop");
                ans += to_string(odd) + " ";
            }
            stack.push(x);                   
            op.push_back("push"); 
        }
    }
    while (!stack.empty()) {           //��������ȫ����ջ�󣬽�ż�������Ƴ�ջ
        int even = stack.top();
        stack.pop();
        op.push_back("pop");
        ans += to_string(even) + " ";
    }
    return   op;
}

int main() {
    vector<int> a = { 1, 2, 3, 4 };
    vector<string> result = railQuestion(a);
    cout << "��������(op): ";
    for (string str : result) {
        cout << str << " ";
    }
    cout << endl;
    cout << "���ս��(ans): " << ans << endl;
    return 0;
}