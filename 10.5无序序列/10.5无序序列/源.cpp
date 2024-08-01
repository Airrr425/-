#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> findTopK(vector<int>& R, int k) {
    // ������R���򣬴Ӵ�С
    sort(R.begin(), R.end(), greater<int>());
    // ����ǰk�����Ԫ��
    vector<int> topK(R.begin(), R.begin() + k);
    return topK;
}
int main() {
    vector<int> R = { 9, 6, 3, 8, 2, 7, 5, 1, 4 };
    int k = 3;
    cout << "ԭʼ���� R: ";
    for (auto num : R) {
        cout << num << " ";
    }
    cout << endl;
    vector<int> topK = findTopK(R, k);
    cout << "��С����˳���ǰ " << k << " �����Ԫ��: ";
    for (auto num : topK) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}