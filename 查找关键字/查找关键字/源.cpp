#include <iostream>
#include <vector>
using namespace std;
int findFirstOccurrence(vector<int>& R2, int k) {
    int left = 0;
    int right = R2.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (R2[mid] == k) {
            // 如果找到关键字为k的元素，向左查找第一个出现的位置
            while (mid > 0 && R2[mid - 1] == k) {
                mid--;
            }
            return mid;
        }
        else if (R2[mid] < k) {
            // 关键字k在右半部分
            left = mid + 1;
        }
        else {
            // 关键字k在左半部分
            right = mid - 1;
        }
    }
    return -1; // 如果没有找到关键字为k的元素，则返回-1表示未找到
}
int main() {
    vector<int> R2 = { 1, 2, 3, 3, 4, 5, 5, 5, 6, 7 };
    int k = 5;
    int position = findFirstOccurrence(R2, k);
    if (position != -1) {
        cout << "R2中第一个关键字为" << k << "的元素位置为：" << position << endl;
    }
    else {
        cout << "R2中未找到关键字为" << k << "的元素" << endl;
    }
    return 0;
}