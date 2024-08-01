#include <iostream>
#include <vector>
using namespace std;
// 基于二分查找的算法来找到两个序列的中位数
double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    // 确保nums1是较短的序列
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }
    // 初始化二分查找的边界
    int left = 0;
    int right = m;
    int halfLen = (m + n + 1) / 2;
    while (left <= right) {
        int i = (left + right) / 2;
        int j = halfLen - i;
        // i划分的位置过大，调整右边界
        if (i < m && nums2[j - 1] > nums1[i]) {
            left = i + 1;
        }
        // i划分的位置过小，调整左边界
        else if (i > 0 && nums1[i - 1] > nums2[j]) {
            right = i - 1;
        }
        // i划分的位置正确
        else {
            int maxLeft;
            if (i == 0) {
                maxLeft = nums2[j - 1];
            }
            else if (j == 0) {
                maxLeft = nums1[i - 1];
            }
            else {
                maxLeft = max(nums1[i - 1], nums2[j - 1]);
            }
            // 如果序列总长度为奇数，直接返回左半部分的最大值
            if ((m + n) % 2 == 1) {
                return maxLeft;
            }
            int minRight;
            if (i == m) {
                minRight = nums2[j];
            }
            else if (j == n) {
                minRight = nums1[i];
            }
            else {
                minRight = min(nums1[i], nums2[j]);
            }
            // 如果序列总长度为偶数，返回左半部分最大值和右半部分最小值的平均值
            return (maxLeft + minRight) / 2.0;
        }
    }
    // 输入的序列非升序序列，返回错误值
    return 0.0;
}
int main() {
    vector<int> nums1 = { 11, 13, 15, 17, 19 };
    vector<int> nums2 = { 2, 4, 6, 8, 20 };
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "中位数是：" << median << endl;
    return 0;
}