#include <iostream>
#include <vector>
using namespace std;
// 简单选择排序
void selectSort(vector<int>& R, int m) {
    int n = R.size();
    for (int i = 0; i < m && i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (R[j] < R[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(R[i], R[minIndex]);
        }
    }
}
int main() {
    vector<int> R = { 5, 3, 8, 4, 2, 7, 1, 6 };
    int m = 4;
    cout << "原始顺序表 R: ";
    for (auto num : R) {
        cout << num << " ";
    }
    cout << endl;
    selectSort(R, m);
    cout << "选择排序后的前 " << m << " 个整数: ";
    for (int i = 0; i < m; i++) {
        cout << R[i] << " ";
    }
    cout << endl;
    return 0;
}