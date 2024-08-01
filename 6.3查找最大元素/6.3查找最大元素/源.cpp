#include <iostream>
using namespace std;
int findMaxElement(int arr[], int start, int end) {
    if (start == end) {
        return arr[start];  // 当数组只有一个元素时，返回该元素
    }
    int mid = (start + end) / 2;
    int max1 = findMaxElement(arr, start, mid);  // 递归求解前半部分中的最大元素值
    int max2 = findMaxElement(arr, mid + 1, end);  // 递归求解后半部分中的最大元素值
    return max(max1, max2);  // 返回前半部分和后半部分中的最大元素值
}
int main() {
    int arr[] = { 5, 7, 9, 3, 1, 6, 2, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxElement = findMaxElement(arr, 0, n - 1);
    cout << "最大元素值为：" << maxElement << endl;
    return 0;
}