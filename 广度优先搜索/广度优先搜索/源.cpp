#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// ͼ�Ĺ�����ȱ����㷨
void bfs(const vector<vector<int>>& graph, int start) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);  // ��¼�����Ƿ��ѷ���
    queue<int> q;                              // �������У����ڹ�����ȱ���
    visited[start] = true;  // �����ʼ����Ϊ�ѷ���
    q.push(start);          // ����ʼ�������
    while (!q.empty()) {
        int currVertex = q.front();  // ȡ�������еĵ�ǰ����
        q.pop();                     // ����ǰ�������
        cout << currVertex << " ";   // �����ǰ����
        // ������ǰ������ڽӶ���
        for (int i = 0; i < numVertices; i++) {
            if (graph[currVertex][i] == 1 && !visited[i]) {
                // ����ڽӶ���δ�����ʹ�������Ϊ�ѷ��������
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main() {
    // ����ͼ���ڽӾ���洢
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };
    // ���ù�����ȱ����㷨���Ӷ���0��ʼ����
    bfs(graph, 0);
    return 0;
}