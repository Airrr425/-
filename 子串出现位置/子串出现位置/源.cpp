#include <iostream>
#include <vector>
using namespace std;
vector<int> buildKMPTable(string pattern) {           //构建KMP中的匹配表
    vector<int> table(pattern.size(), 0);
    int j = 0;
    for (int i = 1; i < pattern.size(); i++) {
        if (pattern[i] == pattern[j]) {
            j++;
            table[i] = j;
        }
        else {
            if (j > 0) {
                j = table[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                j++;
                table[i] = j;
            }
        }
    }
    return table;
}
int findLastOccurrence(string text, string pattern) {
    if (pattern.size() == 0) {
        return -1;
    }
    vector<int> table = buildKMPTable(pattern);
    int i = 0, j = 0;
    int lastMatch = -1;            //没有该子串时返回-1
    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == pattern.size()) {         //匹配成功时i-j即为所求值
                lastMatch = i - j;
                j = table[j - 1];
            }
        }
        else {
            if (j != 0) {                      //匹配失败
                j = table[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return lastMatch;
}
int main() {
    string s1 = "abcdabcd";
    string t1 = "abc";
    cout << findLastOccurrence(s1, t1) << endl; 
    string s2 = "aaaaa";
    string t2 = "aaa";
    cout << findLastOccurrence(s2, t2) << endl;  
    return 0;
}