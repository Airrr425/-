#include <iostream>
#include <vector>
using namespace std;
bool calculateDiagonalSums(const vector<vector<int>>& arr, int m, int n, int& diagonalSum1, int& diagonalSum2) {
    if (m != n) {
        return false; // 如果m不等于n，返回false
    }

    diagonalSum1 = 0; // 左上角-右下角对角线的和
    diagonalSum2 = 0; // 右上角-左下角对角线的和

    for (int i = 0; i < m; i++) {
        diagonalSum1 += arr[i][i]; // 左上角-右下角对角线的元素
        diagonalSum2 += arr[i][n - i - 1]; // 右上角-左下角对角线的元素
    }

    return true;
}
int main() {
    int m, n;
    cout << "请输入二维数组的行数m: ";
    cin >> m;
    cout << "请输入二维数组的列数n: ";
    cin >> n;

    vector<vector<int>> arr(m, vector<int>(n)); // 创建二维数组
    cout << "请输入二维数组的元素：" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int diagonalSum1, diagonalSum2;

    bool isSuccess = calculateDiagonalSums(arr, m, n, diagonalSum1, diagonalSum2);
    if (isSuccess) {
        cout << "左上角-右下角对角线的和为: " << diagonalSum1 << endl;
        cout << "右上角-左下角对角线的和为: " << diagonalSum2 << endl;
    }
    else {
        cout << "m不等于n，无法计算对角线元素之和。" << endl;
    }

    return 0;
}