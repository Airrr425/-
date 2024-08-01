#include <iostream>
#include <cmath>
using namespace std;
int getNodeLevel(int i) {
    // 计算节点所在层次
    return static_cast<int>(log2(i)) + 1;
}
int main() {
    int i = 6;  // 要求层次的节点编号
    int level = getNodeLevel(i);

    cout << "节点 " << i << " 的层次为：" << level << endl;

    return 0;
}