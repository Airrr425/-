#include<iostream>
using namespace std;
string findMaxEqualSubString(string s) {
    string maxSubString = ""; // 存储最大等值子串
    int maxLength = 0; // 等值子串的最大长度
    for (int i = 0; i < s.length(); i++) {
        string subString = ""; // 存储当前等值子串
        subString += s[i];
        int j = i + 1;
        while (j < s.length() && s[j] == s[i]) {
            subString += s[j]; // 将相同的字符追加到等值子串中
            j++;
        }
        if (subString.length() > maxLength) {
            maxSubString = subString; // 更新最大等值子串
            maxLength = subString.length(); // 更新最大长度
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