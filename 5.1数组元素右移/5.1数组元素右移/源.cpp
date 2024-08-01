#include <iostream>
using namespace std;
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotateArray(int arr[], int n, int m) {
    m = m % n; // 处理m大于n的情况，防止多余的循环
    if (m == 0) return;

    reverse(arr, 0, n - 1); // 先整体反转数组
    reverse(arr, 0, m - 1); // 再反转前m个元素
    reverse(arr, m, n - 1); // 最后反转剩余的元素
}
int main() {
    int n, m;
    cout << "请输入数组元素个数n: ";
    cin >> n;
    int* arr = new int[n];
    cout << "请输入数组元素: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "请输入右移位数m: ";
    cin >> m;

    rotateArray(arr, n, m);

    cout << "右移后的数组: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}