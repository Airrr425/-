#include <iostream>
#include <string>
using namespace std;
int countNonOverlappingOccurrences(const string& s, const string& t, int sIndex, int tIndex) {
    int sLen = s.length();
    int tLen = t.length();
    if (sIndex >= sLen || tIndex >= tLen) {         // �ݹ����ֹ����
        return 0;
    }
    if (s[sIndex] == t[tIndex]) {        // ��ǰλ�õ��ַ�ƥ��ɹ�
        if (tIndex == tLen - 1) {        // ����Ѿ�ƥ�䵽��t�����һ���ַ������ʾ�ҵ���һ�������Ĳ��ص�����
            return 1;
        }
        // ����ƥ��t����һ���ַ���ͬʱ�����ƶ�����
        return countNonOverlappingOccurrences(s, t, sIndex + 1, tIndex + 1);
    }
    // ��ǰλ�õ��ַ�ƥ��ʧ�ܣ�������s���������
    return countNonOverlappingOccurrences(s, t, sIndex + 1, 0);
}
int main() {
    string s = "aababad";
    string t = "aba";
    int totalCount = countNonOverlappingOccurrences(s, t, 0, 0);
    cout << "t��s�в��ص����ֵĴ���Ϊ��" << totalCount << endl;
    return 0;
}