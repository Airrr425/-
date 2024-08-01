#include <iostream>
#include <string>
using namespace std;
int findLastCharacter(const string& str, char c, int index) {
    if (index < 0) {
        return -1;  // 找到字符串的开头仍然没有找到字符c，返回-1
    }

    if (str[index] == c) {
        return index;  // 找到字符c，返回当前位置
    }

    return findLastCharacter(str, c, index - 1); // 递归查找前一个位置
}
int main() {
    string s = "abcdefg";
    char c = 'd';
    int lastIndex = findLastCharacter(s, c, s.length() - 1);

    if (lastIndex == -1) {
        cout << "字符 " << c << " 在字符串中未找到" << endl;
    }
    else {
        cout << "字符 " << c << " 的最后一个位置是 " << lastIndex << endl;
    }

    return 0;
}