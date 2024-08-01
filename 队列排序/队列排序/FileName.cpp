#include <iostream>
#include <vector>
#include<queue>
using namespace std;
queue<int> q;
vector<int> moveEvenToFront(vector<int>& a) 
{
    vector<int> ans;
    int n = a.size();
    for (int i = 0; i < n ; i++)
    {
        if (i%2==0)             //��ĿǰΪ����λ����Ԫ�����������
        {
            q.push(a[i]);
        }
        if (i % 2 == 1)         //��ĿǰΪ����λ����Ԫ�ش���ans��
        {
            ans.push_back(a[i]);
        }
    }
    while (q.size()!=0)
    {
        int odd = q.front();
        ans.push_back(odd);
        q.pop();
    }
    return ans;
}
int main() {
    vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 8 };
    cout << "��ʼ����: ";
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;
    vector<int> ans = moveEvenToFront(a);
    cout << "�ƶ��������: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}