#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int>& arr, int k, vector<int>& searchSequence) {
    int left = 0;
    int right = arr.size() - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        searchSequence.push_back(mid);
        if (arr[mid] == k) {
            return mid;
        }
        else if (arr[mid] < k) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int k = 6;
    vector<int> searchSequence;
    int position = binarySearch(arr, k, searchSequence);
    if (position != -1) {
        cout << "关键字" << k << "在有序表中的位置为：" << position << endl;
        cout << "查找序列：";
        for (int i : searchSequence) {
            cout << i << " ";
        }
        cout << endl;
    }
    else {
        cout << "关键字" << k << "未找到" << endl;
    }
    return 0;
}