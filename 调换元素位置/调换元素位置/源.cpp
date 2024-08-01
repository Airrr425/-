#include <iostream>
#include <vector>
using namespace std;
void adjustArrayOrder(vector<double>& a, const vector<int>& b) {
    int n = a.size();
    double temp;
    vector<double> tempArray(n); // 创建一个临时数组存储调整后的元素顺序
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = a[b[i]];
        a[b[i]] = temp;
    }
    tempArray = a;
}
int main() {
    int n;
    cout << "请输入数组的长度n: ";
    cin >> n;

    vector<double> a(n); // 创建double型数组a
    vector<int> b(n); // 创建整数数组b

    cout << "请输入数组a的元素：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "请输入数组b的元素：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    adjustArrayOrder(a, b); // 调用调整数组顺序的函数

    cout << "调整后的数组a的元素顺序为：" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}