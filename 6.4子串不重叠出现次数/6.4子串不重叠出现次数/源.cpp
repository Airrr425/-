#include <iostream>
#include <string>
using namespace std;
int countNonOverlappingOccurrences(const string& s, const string& t, int sIndex, int tIndex) {
    int sLen = s.length();
    int tLen = t.length();
    if (sIndex >= sLen || tIndex >= tLen) {         // 递归的终止条件
        return 0;
    }
    if (s[sIndex] == t[tIndex]) {        // 当前位置的字符匹配成功
        if (tIndex == tLen - 1) {        // 如果已经匹配到了t的最后一个字符，则表示找到了一个完整的不重叠出现
            return 1;
        }
        // 继续匹配t的下一个字符，同时往后移动索引
        return countNonOverlappingOccurrences(s, t, sIndex + 1, tIndex + 1);
    }
    // 当前位置的字符匹配失败，继续在s中往后查找
    return countNonOverlappingOccurrences(s, t, sIndex + 1, 0);
}
int main() {
    string s = "aababad";
    string t = "aba";
    int totalCount = countNonOverlappingOccurrences(s, t, 0, 0);
    cout << "t在s中不重叠出现的次数为：" << totalCount << endl;
    return 0;
}