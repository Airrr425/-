#include <iostream>
using namespace std;
bool transposeMatrix(int** arr, int m, int n) {
    if (m != n) {
        return false; // 如果m不等于n，返回false
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            // 交换arr[i][j]和arr[j][i]
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    return true;
}
int main() {
    int m, n;
    cout << "请输入二维数组的行数m: ";
    cin >> m;
    cout << "请输入二维数组的列数n: ";
    cin >> n;

    int** arr = new int* [m]; // 创建二维数组
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
    }

    cout << "请输入二维数组的元素：" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    bool isSuccess = transposeMatrix(arr, m, n);

    if (isSuccess) {
        cout << "转置后的二维数组：" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "m不等于n，无法进行转置。" << endl;
    }

    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}