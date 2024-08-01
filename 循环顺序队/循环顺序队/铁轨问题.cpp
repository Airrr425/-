#include <iostream>
#include <stack>
#include <vector>
#include<string>
using namespace std;
vector<string> railroadReorganize(vector<int> a) {
    stack<int> stack;
    vector<string> op;
    string ans = "";
    for (int i = 0; i < a.size(); i++) {
        int x = a[i];
        if (x % 2 == 1) {
            stack.push(x);                  //奇数车厢进栈
            op.push_back("push");           
        }
        else {
            while (!stack.empty() && stack.top() % 2 == 1) {
                int odd = stack.top();
                stack.pop();
                op.push_back("pop");
                ans += std::to_string(odd) + " ";
            }
            stack.push(x);
            op.push_back("push");
        }
    }
    while (!stack.empty()) {
        int odd = stack.top();
        stack.pop();
        op.push_back("pop");
        ans += to_string(odd) + " ";
    }
    return  op ;
}
int main() {
    vector<int> a = { 1, 2, 3, 4 };
    vector<string> result = railroadReorganize(a);
    cout << "操作序列(op): ";
    for (string str : result) {
        cout << str << " ";
    }
    cout << endl;
    cout << "最终结果(ans): " << result[1] << endl;
    return 0;
}