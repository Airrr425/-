#include <iostream>
#include <stack>
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
    stack<pair<int, int>> st;
    st.push(make_pair(low, high));
    while (!st.empty()) {
        int start = st.top().first;
        int end = st.top().second;
        st.pop();
        int pivot = partition(nums, start, end);  // ��������
        // ����벿����ջ
        if (pivot - 1 > start) {
            st.push(make_pair(start, pivot - 1));
        }
        // ���Ұ벿����ջ
        if (pivot + 1 < end) {
            st.push(make_pair(pivot + 1, end));
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