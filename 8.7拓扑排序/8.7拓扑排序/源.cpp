#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// �ж�����ͼ�Ƿ���ڻ�·
bool hasCycle(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<int> inDegree(numVertices, 0);  // ��¼ÿ����������
    // ����ÿ����������
    for (int i = 0; i < numVertices; i++) {
        for (int neighbor : graph[i]) {
            inDegree[neighbor]++;
        }
    }
    queue<int> q;
    // �����Ϊ0�Ķ���������
    for (int i = 0; i < numVertices; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    int count = 0;  // ��¼�ѷ��ʵĶ�����
    // ��������
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        count++;
        for (int neighbor : graph[current]) {
            // �Ƴ���ǰ������ڽӶ�������
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return count != numVertices;  // ������ʵĶ�����������������˵�����ڻ�·
}
int main() {
    // ��������ͼ���ڽӱ�洢
    vector<vector<int>> graph = {
        {1},    // ����0���ڽӶ���Ϊ1
        {2, 3}, // ����1���ڽӶ���Ϊ2��3
        {3},    // ����2���ڽӶ���Ϊ3
        {},     // ����3û���ڽӶ���
    };
    bool hasCycleFlag = hasCycle(graph);
    if (hasCycleFlag) {
        cout << "ͼ�д��ڻ�·" << endl;
    }
    else {
        cout << "ͼ�в����ڻ�·" << endl;
    }
    return 0;
}