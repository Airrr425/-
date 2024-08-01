#include <iostream>
using namespace std;
int lastMinIndex(int arr[], int n) {
    int minIndex = 0; // 先将最小元素的下标初始化为 0
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}
int main() {
    int n;
    cout << "请输入数组元素个数n: ";
    cin >> n;
    int* arr = new int[n];
    cout << "请输入数组元素: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int minIndex = lastMinIndex(arr, n);
    cout << "最后一个最小元素的下标为: " << minIndex << endl;
    delete[] arr;

    return 0;
}
