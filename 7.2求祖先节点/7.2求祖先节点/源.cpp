#include <iostream>
#include <vector>
using namespace std;
void getAncestors(vector<char>& tree, int i) {
    while (i > 1) {
        i = i / 2;  // ���㸸�ڵ������
        cout << tree[i - 1] << " ";
    }
}
int main() {
    vector<char> tree = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };  // ��˳��洢�Ķ�����Ϊ��
    int i = 6;  // Ҫ������Ƚڵ�Ľڵ���
    cout << "�ڵ� " << tree[i - 1] << " �����Ƚڵ�ֵΪ��";
    getAncestors(tree, i);
    return 0;
}