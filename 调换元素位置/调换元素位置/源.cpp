#include <iostream>
#include <vector>
using namespace std;
void adjustArrayOrder(vector<double>& a, const vector<int>& b) {
    int n = a.size();
    double temp;
    vector<double> tempArray(n); // ����һ����ʱ����洢�������Ԫ��˳��
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = a[b[i]];
        a[b[i]] = temp;
    }
    tempArray = a;
}
int main() {
    int n;
    cout << "����������ĳ���n: ";
    cin >> n;

    vector<double> a(n); // ����double������a
    vector<int> b(n); // ������������b

    cout << "����������a��Ԫ�أ�" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "����������b��Ԫ�أ�" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    adjustArrayOrder(a, b); // ���õ�������˳��ĺ���

    cout << "�����������a��Ԫ��˳��Ϊ��" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}