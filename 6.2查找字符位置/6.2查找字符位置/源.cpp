#include <iostream>
#include <string>
using namespace std;
int findLastCharacter(const string& str, char c, int index) {
    if (index < 0) {
        return -1;  // �ҵ��ַ����Ŀ�ͷ��Ȼû���ҵ��ַ�c������-1
    }

    if (str[index] == c) {
        return index;  // �ҵ��ַ�c�����ص�ǰλ��
    }

    return findLastCharacter(str, c, index - 1); // �ݹ����ǰһ��λ��
}
int main() {
    string s = "abcdefg";
    char c = 'd';
    int lastIndex = findLastCharacter(s, c, s.length() - 1);

    if (lastIndex == -1) {
        cout << "�ַ� " << c << " ���ַ�����δ�ҵ�" << endl;
    }
    else {
        cout << "�ַ� " << c << " �����һ��λ���� " << lastIndex << endl;
    }

    return 0;
}