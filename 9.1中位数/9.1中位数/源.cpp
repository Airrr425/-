#include <iostream>
#include <vector>
using namespace std;
// ���ڶ��ֲ��ҵ��㷨���ҵ��������е���λ��
double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    // ȷ��nums1�ǽ϶̵�����
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }
    // ��ʼ�����ֲ��ҵı߽�
    int left = 0;
    int right = m;
    int halfLen = (m + n + 1) / 2;
    while (left <= right) {
        int i = (left + right) / 2;
        int j = halfLen - i;
        // i���ֵ�λ�ù��󣬵����ұ߽�
        if (i < m && nums2[j - 1] > nums1[i]) {
            left = i + 1;
        }
        // i���ֵ�λ�ù�С��������߽�
        else if (i > 0 && nums1[i - 1] > nums2[j]) {
            right = i - 1;
        }
        // i���ֵ�λ����ȷ
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
            // ��������ܳ���Ϊ������ֱ�ӷ�����벿�ֵ����ֵ
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
            // ��������ܳ���Ϊż����������벿�����ֵ���Ұ벿����Сֵ��ƽ��ֵ
            return (maxLeft + minRight) / 2.0;
        }
    }
    // ��������з��������У����ش���ֵ
    return 0.0;
}
int main() {
    vector<int> nums1 = { 11, 13, 15, 17, 19 };
    vector<int> nums2 = { 2, 4, 6, 8, 20 };
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "��λ���ǣ�" << median << endl;
    return 0;
}