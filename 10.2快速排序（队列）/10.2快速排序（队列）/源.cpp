#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 交换两个元素
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// 划分函数，选取枢纽元并调整其他元素的位置
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];  // 选取最后一个元素为枢纽元
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
// 非递归快速排序算法
void quickSort(vector<int>& nums, int low, int high) {
    queue<pair<int, int>> q;
    q.push(make_pair(low, high));
    while (!q.empty()) {
        int start = q.front().first;
        int end = q.front().second;
        q.pop();
        int pivot = partition(nums, start, end);  // 划分数组
        // 将左半部分入队列
        if (pivot - 1 > start) {
            q.push(make_pair(start, pivot - 1));
        }
        // 将右半部分入队列
        if (pivot + 1 < end) {
            q.push(make_pair(pivot + 1, end));
        }
    }
}
int main() {
    vector<int> nums = { 5, 3, 8, 4, 2, 7, 1, 6 };
    int n = nums.size();
    cout << "原始数组: ";
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    quickSort(nums, 0, n - 1);
    cout << "排序后的数组: ";
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}