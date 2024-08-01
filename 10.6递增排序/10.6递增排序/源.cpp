#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Student {
    string name;
    int classNumber;
};
void sortStudentsByClass(vector<Student>& R) {
    int count[6] = { 0 };  // ���ͳ�����飬�±��ʾ��ţ�ֵ��ʾ�ð�ų��ֵĴ���

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
    cout << "����ǰ��˳���R��" << endl;
    for (const auto& student : R) {
        cout << student.name << " - " << student.classNumber << endl;
    }
    sortStudentsByClass(R);
    cout << "������˳���R��" << endl;
    for (const auto& student : R) {
        cout << student.name << " - " << student.classNumber << endl;
    }
    return 0;
}