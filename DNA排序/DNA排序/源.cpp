#include<iostream>
#include<vector>
#include<sstream>
#include <algorithm>
#include<string>
using namespace std;


//sort()将比较键值对中的int类型来排序
bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}
//求单个字符串的逆序对个数
int ROP(string str, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (str[i] > str[j]) {
                count++;
            }
        }
    }
    return count;
}
//读数据
vector<pair<string, int>> ReadAndOperate(int& length, int& num) {
    vector<pair<string, int>> strs;
    string str, numStr;
    //储存第一行的字符串长度与字符串个数
    getline(cin, str);
    istringstream ss(str);
    ss >> numStr;
    length = atoi(numStr.c_str());
    ss >> numStr;
    num = atoi(numStr.c_str());
    //储存后续字符串
    while (getline(cin, str)) {
        //获取每个字符串的逆序对个数
        int numOfROP = ROP(str, length);
        //将字符串与逆序对个数组成键值对存入strs
        strs.push_back(make_pair(str, numOfROP));
    }
    return strs;
}
int main() {
    int length, num;
    vector<pair<string, int>> strs = ReadAndOperate(length, num);
    //对 逆序对个数升序排列 就是按 排序最多到最小 排列
    sort(strs.begin(), strs.end(), compare);
    //输出string部分
    for (int i = 0; i < num; i++) {
        cout << strs[i].first << endl;
    }
}