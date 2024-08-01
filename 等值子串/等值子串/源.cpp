#include<iostream>
using namespace std;
string findMaxEqualSubString(string s) {
    string maxSubString = ""; // �洢����ֵ�Ӵ�
    int maxLength = 0; // ��ֵ�Ӵ�����󳤶�
    for (int i = 0; i < s.length(); i++) {
        string subString = ""; // �洢��ǰ��ֵ�Ӵ�
        subString += s[i];
        int j = i + 1;
        while (j < s.length() && s[j] == s[i]) {
            subString += s[j]; // ����ͬ���ַ�׷�ӵ���ֵ�Ӵ���
            j++;
        }
        if (subString.length() > maxLength) {
            maxSubString = subString; // ��������ֵ�Ӵ�
            maxLength = subString.length(); // ������󳤶�
        }
    }
    return maxSubString;
}
int main() {
    string s = "dawdjawaafaffhhhh";
    string maxEqualSubString = findMaxEqualSubString(s);
    cout << maxEqualSubString;
    return 0;
}