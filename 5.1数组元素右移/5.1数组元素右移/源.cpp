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
    m = m % n; // ����m����n���������ֹ�����ѭ��
    if (m == 0) return;

    reverse(arr, 0, n - 1); // �����巴ת����
    reverse(arr, 0, m - 1); // �ٷ�תǰm��Ԫ��
    reverse(arr, m, n - 1); // ���תʣ���Ԫ��
}
int main() {
    int n, m;
    cout << "����������Ԫ�ظ���n: ";
    cin >> n;
    int* arr = new int[n];
    cout << "����������Ԫ��: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "����������λ��m: ";
    cin >> m;

    rotateArray(arr, n, m);

    cout << "���ƺ������: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}