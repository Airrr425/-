#include <iostream>    //�ռ临�Ӷ�ΪO��1����ʱ�临�Ӷ�ΪO(n��
#include <algorithm>
using namespace std;
bool isNumber(char c) {
    return (c >= '0' && c <= '9');
}
bool isAlphabet(char c) {
    return (c >= 'a' && c <= 'z');
}
void separeteCharactors(string& s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right)
    {
        if (isNumber(s[left])) {
            left++;
        }
        else if (isalpha(s[right])) {
            right--;
        }
        else {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
 }
int main() {
    string s = "adwu8813wdadfwa";
    separeteCharactors(s);
    cout << s << endl;
}