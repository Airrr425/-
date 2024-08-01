#include <iostream>
#include <vector>
using namespace std;
void getAncestors(vector<char>& tree, int i) {
    while (i > 1) {
        i = i / 2;  // 计算父节点的索引
        cout << tree[i - 1] << " ";
    }
}
int main() {
    vector<char> tree = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };  // 以顺序存储的二叉树为例
    int i = 6;  // 要输出祖先节点的节点编号
    cout << "节点 " << tree[i - 1] << " 的祖先节点值为：";
    getAncestors(tree, i);
    return 0;
}