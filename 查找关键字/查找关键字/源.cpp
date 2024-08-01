#include <iostream>
#include <vector>
using namespace std;
int findFirstOccurrence(vector<int>& R2, int k) {
    int left = 0;
    int right = R2.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (R2[mid] == k) {
            // ����ҵ��ؼ���Ϊk��Ԫ�أ�������ҵ�һ�����ֵ�λ��
            while (mid > 0 && R2[mid - 1] == k) {
                mid--;
            }
            return mid;
        }
        else if (R2[mid] < k) {
            // �ؼ���k���Ұ벿��
            left = mid + 1;
        }
        else {
            // �ؼ���k����벿��
            right = mid - 1;
        }
    }
    return -1; // ���û���ҵ��ؼ���Ϊk��Ԫ�أ��򷵻�-1��ʾδ�ҵ�
}
int main() {
    vector<int> R2 = { 1, 2, 3, 3, 4, 5, 5, 5, 6, 7 };
    int k = 5;
    int position = findFirstOccurrence(R2, k);
    if (position != -1) {
        cout << "R2�е�һ���ؼ���Ϊ" << k << "��Ԫ��λ��Ϊ��" << position << endl;
    }
    else {
        cout << "R2��δ�ҵ��ؼ���Ϊ" << k << "��Ԫ��" << endl;
    }
    return 0;
}