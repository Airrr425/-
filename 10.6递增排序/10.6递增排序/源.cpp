#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Student {
    string name;
    int classNumber;
};
void sortStudentsByClass(vector<Student>& R) {
    int count[6] = { 0 };  // 班号统计数组，下标表示班号，值表示该班号出现的次数

    for (const auto& student : R) {
        count[student.classNumber]++;
    }
    int index = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            R[index].classNumber = i;
            index++;
        }
    }
}
int main() {
    vector<Student> R = {
        {"Alice", 2},
        {"Bob", 4},
        {"Charlie", 1},
        {"David", 3},
        {"Eve", 2},
        {"Frank", 0},
        {"Grace", 5},
        {"Hannah", 5},
    };
    cout << "排序前的顺序表R：" << endl;
    for (const auto& student : R) {
        cout << student.name << " - " << student.classNumber << endl;
    }
    sortStudentsByClass(R);
    cout << "排序后的顺序表R：" << endl;
    for (const auto& student : R) {
        cout << student.name << " - " << student.classNumber << endl;
    }
    return 0;
}