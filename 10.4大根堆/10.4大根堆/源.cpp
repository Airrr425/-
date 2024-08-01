#include <iostream>
using namespace std;
bool isMaxHeap(int arr[], int n) {
    // 对于节点i，它的左子节点索引为2*i+1，右子节点索引为2*i+2
    for (int i = 0; i < n / 2; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        // 判断左子节点是否比父节点大
        if (leftChild < n && arr[leftChild] > arr[i]) {
            return false;
        }
        // 判断右子节点是否比父节点大
        if (rightChild < n && arr[rightChild] > arr[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    int arr[] = { 90, 64, 45, 32, 27, 21, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isMaxHeap(arr, n)) {
        cout << "该整数序列构成了一个大根堆" << endl;
    }
    else {
        cout << "该整数序列不构成一个大根堆" << endl;
    }
    return 0;
}