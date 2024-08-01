#include <iostream>
using namespace std;
bool transposeMatrix(int** arr, int m, int n) {
    if (m != n) {
        return false; // ���m������n������false
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            // ����arr[i][j]��arr[j][i]
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    return true;
}
int main() {
    int m, n;
    cout << "�������ά���������m: ";
    cin >> m;
    cout << "�������ά���������n: ";
    cin >> n;

    int** arr = new int* [m]; // ������ά����
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
    }

    cout << "�������ά�����Ԫ�أ�" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    bool isSuccess = transposeMatrix(arr, m, n);

    if (isSuccess) {
        cout << "ת�ú�Ķ�ά���飺" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "m������n���޷�����ת�á�" << endl;
    }

    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}