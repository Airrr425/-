#include <iostream>
#include <cmath>
using namespace std;
int getNodeLevel(int i) {
    // ����ڵ����ڲ��
    return static_cast<int>(log2(i)) + 1;
}
int main() {
    int i = 6;  // Ҫ���εĽڵ���
    int level = getNodeLevel(i);

    cout << "�ڵ� " << i << " �Ĳ��Ϊ��" << level << endl;

    return 0;
}