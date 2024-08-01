#include <iostream>
#include <vector>
using namespace std;
bool calculateDiagonalSums(const vector<vector<int>>& arr, int m, int n, int& diagonalSum1, int& diagonalSum2) {
    if (m != n) {
        return false; // ���m������n������false
    }

    diagonalSum1 = 0; // ���Ͻ�-���½ǶԽ��ߵĺ�
    diagonalSum2 = 0; // ���Ͻ�-���½ǶԽ��ߵĺ�

    for (int i = 0; i < m; i++) {
        diagonalSum1 += arr[i][i]; // ���Ͻ�-���½ǶԽ��ߵ�Ԫ��
        diagonalSum2 += arr[i][n - i - 1]; // ���Ͻ�-���½ǶԽ��ߵ�Ԫ��
    }

    return true;
}
int main() {
    int m, n;
    cout << "�������ά���������m: ";
    cin >> m;
    cout << "�������ά���������n: ";
    cin >> n;

    vector<vector<int>> arr(m, vector<int>(n)); // ������ά����
    cout << "�������ά�����Ԫ�أ�" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int diagonalSum1, diagonalSum2;

    bool isSuccess = calculateDiagonalSums(arr, m, n, diagonalSum1, diagonalSum2);
    if (isSuccess) {
        cout << "���Ͻ�-���½ǶԽ��ߵĺ�Ϊ: " << diagonalSum1 << endl;
        cout << "���Ͻ�-���½ǶԽ��ߵĺ�Ϊ: " << diagonalSum2 << endl;
    }
    else {
        cout << "m������n���޷�����Խ���Ԫ��֮�͡�" << endl;
    }

    return 0;
}