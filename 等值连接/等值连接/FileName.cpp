#include <iostream>
#include <fstream>
#include <list>
#include <vector>
using namespace std;
struct Row {
    vector<int> data;
};
int main() {
    ifstream inputFile("in.txt");
    ofstream outputFile("abc.out");
    int m1, n1, m2, n2;
    inputFile >> m1 >> n1;
    list<Row> tableR;
    for (int i = 0; i < m1; i++) {
        Row row;
        for (int j = 0; j < n1; j++) {
            int value;
            inputFile >> value;
            row.data.push_back(value);
        }
        tableR.push_back(row);
    }
    inputFile >> m2 >> n2;
    list<Row> tableS;
    for (int i = 0; i < m2; i++) {
        Row row;
        for (int j = 0; j < n2; j++) {
            int value;
            inputFile >> value;
            row.data.push_back(value);
        }
        tableS.push_back(row);
    }
    int a1, a2;
    inputFile >> a1 >> a2;
    list<Row> result;
    // 等值联接运算
    for (const Row& r : tableR) {
        for (const Row& s : tableS) {
            if (r.data[a1 - 1] == s.data[a2 - 1]) {
                Row row;
                row.data = r.data;
                row.data.insert(row.data.end(), s.data.begin(), s.data.end());
                result.push_back(row);
            }
        }
    }
    // 将结果写入输出文件
    for (const Row& row : result) {
        for (int value : row.data) {
            outputFile << value << " ";
        }
        outputFile << endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
