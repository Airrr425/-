#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// ��������Ԫ��
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// ���ֺ�����ѡȡ��ŦԪ����������Ԫ�ص�λ��
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];  // ѡȡ���һ��Ԫ��Ϊ��ŦԪ
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (nums[j] < pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}
// �ǵݹ���������㷨
void quickSort(vector<int>& nums, int low, int high) {
    queue<pair<int, int>> q;
    q.push(make_pair(low, high));
    while (!q.empty()) {
        int start = q.front().first;
        int end = q.front().second;
        q.pop();
        int pivot = partition(nums, start, end);  // ��������
        // ����벿�������
        if (pivot - 1 > start) {
            q.push(make_pair(start, pivot - 1));
        }
        // ���Ұ벿�������
        if (pivot + 1 < end) {
            q.push(make_pair(pivot + 1, end));
        }
    }
}
int main() {
    vector<int> nums = { 5, 3, 8, 4, 2, 7, 1, 6 };
    int n = nums.size();
    cout << "ԭʼ����: ";
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    quickSort(nums, 0, n - 1);
    cout << "����������: ";
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}