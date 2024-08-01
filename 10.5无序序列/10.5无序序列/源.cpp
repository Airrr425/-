#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> findTopK(vector<int>& R, int k) {
    // 将序列R排序，从大到小
    sort(R.begin(), R.end(), greater<int>());
    // 返回前k个最大元素
    vector<int> topK(R.begin(), R.begin() + k);
    return topK;
}
int main() {
    vector<int> R = { 9, 6, 3, 8, 2, 7, 5, 1, 4 };
    int k = 3;
    cout << "原始序列 R: ";
    for (auto num : R) {
        cout << num << " ";
    }
    cout << endl;
    vector<int> topK = findTopK(R, k);
    cout << "从小到大顺序的前 " << k << " 个最大元素: ";
    for (auto num : topK) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}