#include <iostream>
using namespace std;
int lastMinIndex(int arr[], int n) {
    int minIndex = 0; // �Ƚ���СԪ�ص��±��ʼ��Ϊ 0
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}
int main() {
    int n;
    cout << "����������Ԫ�ظ���n: ";
    cin >> n;
    int* arr = new int[n];
    cout << "����������Ԫ��: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int minIndex = lastMinIndex(arr, n);
    cout << "���һ����СԪ�ص��±�Ϊ: " << minIndex << endl;
    delete[] arr;

    return 0;
}
