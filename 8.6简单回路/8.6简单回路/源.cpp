#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// ͼ��������ȱ����㷨
void dfs(const vector<vector<int>>& graph, int start, int v, vector<bool>& visited, stack<int>& path) {
    visited[start] = true;              // �����ʼ����Ϊ�ѷ���
    path.push(start);                    // ��������뵱ǰ·����
    // ������ǰ������ڽӶ���
    for (int i = 0; i < graph[start].size(); i++) {
        int neighbor = graph[start][i];
        if (!visited[neighbor]) {
            if (neighbor == v) {          // �ҵ�һ���򵥻�·
                path.push(v);             // ������v���뵽·����
                // ����򵥻�·
                cout << "�򵥻�·: ";
                while (!path.empty()) {
                    cout << path.top() << " ";
                    path.pop();
                }
                cout << endl;
                path.push(start);          // ����ʼ�������¼��뵽·���У�����Ѱ��������·
            }
            else {
                dfs(graph, neighbor, v, visited, path);  // ����������ȱ���
            }
        }
    }
    visited[start] = false;              // �ָ���ʼ�����δ����״̬
    path.pop();                          // �Ƴ���ǰ����
}
// ������д��ھ�������v�ļ򵥻�·
void printAllSimpleCycles(const vector<vector<int>>& graph, int v) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);  // ��¼�����Ƿ��ѷ���
    stack<int> path;                           // ���浱ǰ·��
    dfs(graph, v, v, visited, path);            // �Ӷ���v��ʼ������ȱ���
}
int main() {
    // ����ͼ���ڽӱ�洢
    vector<vector<int>> graph = {
        {1, 2},          // ����0���ڽӶ���Ϊ1��2
        {0, 2, 3},       // ����1���ڽӶ���Ϊ0��2��3
        {0, 1, 3},       // ����2���ڽӶ���Ϊ0��1��3
        {1, 2},          // ����3���ڽӶ���Ϊ1��2
    };
    int v = 0;           // ������о�������v�ļ򵥻�·
    printAllSimpleCycles(graph, v);
    return 0;
}