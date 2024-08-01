#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// �ҵ���δ����ľ�����С�Ķ���
int findMinDistance(const vector<int>& distance, const vector<bool>& visited) {
    int minDistance = INT_MAX;
    int minIndex = -1;
    int numVertices = distance.size();
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && distance[i] < minDistance) {
            minDistance = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}
// ʹ�õҿ�˹�����㷨�����·������
int dijkstra(const vector<vector<int>>& graph, int source, int target) {
    int numVertices = graph.size();
    vector<int> distance(numVertices, INT_MAX);  // ��¼Դ�㵽����������·������
    vector<bool> visited(numVertices, false);    // ��¼�����Ƿ񱻷��ʹ�
    distance[source] = 0;   // Դ�㵽����ľ���Ϊ0
    for (int i = 0; i < numVertices - 1; i++) {
        int u = findMinDistance(distance, visited);
        visited[u] = true;
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && graph[u][v] != 0 && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
    return distance[target];
}
int main() {
    // ������Ȩͼ���ڽӾ���洢
    vector<vector<int>> graph = {
        {0, 10, 3, 0},
        {0, 0, 1, 2},
        {0, 4, 0, 8},
        {0, 0, 0, 0},
    };
    int source = 0;  // Դ����
    int target = 3;  // Ŀ�����
    int shortestDistance = dijkstra(graph, source, target);
    if (shortestDistance == INT_MAX) {
        cout << "����" << source << "������" << target << "û��·��" << endl;
    }
    else {
        cout << "����" << source << "�Ͷ���" << target << "֮������·������Ϊ��" << shortestDistance << endl;
    }
    return 0;
}