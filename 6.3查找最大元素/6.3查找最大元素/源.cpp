#include <iostream>
using namespace std;
int findMaxElement(int arr[], int start, int end) {
    if (start == end) {
        return arr[start];  // ������ֻ��һ��Ԫ��ʱ�����ظ�Ԫ��
    }
    int mid = (start + end) / 2;
    int max1 = findMaxElement(arr, start, mid);  // �ݹ����ǰ�벿���е����Ԫ��ֵ
    int max2 = findMaxElement(arr, mid + 1, end);  // �ݹ�����벿���е����Ԫ��ֵ
    return max(max1, max2);  // ����ǰ�벿�ֺͺ�벿���е����Ԫ��ֵ
}
int main() {
    int arr[] = { 5, 7, 9, 3, 1, 6, 2, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxElement = findMaxElement(arr, 0, n - 1);
    cout << "���Ԫ��ֵΪ��" << maxElement << endl;
    return 0;
}