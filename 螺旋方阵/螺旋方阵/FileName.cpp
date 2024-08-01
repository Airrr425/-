#include <iostream>
using namespace std;

void generateSpiralMatrix(int n) {
    int matrix[10][10];
    int num = 1;
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = n - 1;

    while (rowStart <= rowEnd && colStart <= colEnd) {
        for (int i = colStart; i <= colEnd; i++) {
            matrix[rowStart][i] = num++;
        }
        rowStart++;

        for (int i = rowStart; i <= rowEnd; i++) {
            matrix[i][colEnd] = num++;
        }
        colEnd--;

        if (rowStart <= rowEnd) {
            for (int i = colEnd; i >= colStart; i--) {
                matrix[rowEnd][i] = num++;
            }
            rowEnd--;
        }

        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                matrix[i][colStart] = num++;
            }
            colStart++;
        }
    }

    // 输出螺旋矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    if (n <= 0 || n > 10) {
        cout << "n的取值范围不合法。" << endl;
    }
    else {
        generateSpiralMatrix(n);
    }

    return 0;
}
