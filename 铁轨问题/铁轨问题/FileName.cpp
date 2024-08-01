#include <iostream>
#include <stack>
#include <vector>
#include<string>
using namespace std;
string ans = "";    //输出最后结果
vector<string> railQuestion(vector<int> a) {
    stack<int> stack;   //表示中间的铁轨
    vector<string> op;  //记录操作顺序
    for (int i = 0; i < a.size(); i++) {
        int x = a[i];
        if (x % 2 == 1) {
            stack.push(x);                  //奇数车厢进栈
            op.push_back("push");
        }
        else {                                   
            while (!stack.empty() && stack.top() % 2 == 1) {         //当右侧轨道为偶数车厢时，若栈顶为奇数车厢，则弹出奇数车厢，否则就推入偶数车厢
                int odd = stack.top();
                stack.pop();
                op.push_back("pop");
                ans += to_string(odd) + " ";
            }
            stack.push(x);                   
            op.push_back("push"); 
        }
    }
    while (!stack.empty()) {           //奇数车厢全部出栈后，将偶数车厢推出栈
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
    cout << "操作序列(op): ";
    for (string str : result) {
        cout << str << " ";
    }
    cout << endl;
    cout << "最终结果(ans): " << ans << endl;
    return 0;
}