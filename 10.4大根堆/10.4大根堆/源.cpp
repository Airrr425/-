#include <iostream>
using namespace std;
bool isMaxHeap(int arr[], int n) {
    // ���ڽڵ�i���������ӽڵ�����Ϊ2*i+1�����ӽڵ�����Ϊ2*i+2
    for (int i = 0; i < n / 2; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        // �ж����ӽڵ��Ƿ�ȸ��ڵ��
        if (leftChild < n && arr[leftChild] > arr[i]) {
            return false;
        }
        // �ж����ӽڵ��Ƿ�ȸ��ڵ��
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
        cout << "���������й�����һ�������" << endl;
    }
    else {
        cout << "���������в�����һ�������" << endl;
    }
    return 0;
}