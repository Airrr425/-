#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// ͼ��������ȱ����㷨
bool dfs(const vector<vector<int>>& graph, int start, int v, vector<bool>& visited) {
    stack<int> stk;
    stk.push(start);                      // ����ʼ������ջ
    visited[start] = true;                // �����ʼ����Ϊ�ѷ���
    while (!stk.empty()) {
        int currVertex = stk.top();       // ȡ��ջ��Ԫ��
        stk.pop();                        // ��ջ��Ԫ�س�ջ
        // ������ǰ������ڽӶ���
        for (int i = 0; i < graph[currVertex].size(); i++) {
            int neighbor = graph[currVertex][i];
            if (!visited[neighbor]) {
                if (neighbor == v) {
                    return true;           // ����vΪ��·��һ���֣�����true
                }
                stk.push(neighbor);       // �ڽӶ�����ջ
                visited[neighbor] = true; // ����ڽӶ���Ϊ�ѷ���
            }
        }
    }
    return false;                          // δ�ҵ���·������false
}
// �ж�ͼ���Ƿ���ھ�������v�Ļ�·
bool hasCycle(const vector<vector<int>>& graph, int v) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);  // ��¼�����Ƿ��ѷ���
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, v, visited)) {
                return true;    // ���ھ�������v�Ļ�·������true
            }
        }
    }
    return false;           // �����ھ�������v�Ļ�·������false
}
int main() {
    vector<vector<int>> graph = {
        {1, 2},          // ����0���ڽӶ���Ϊ1��2
        {0, 2, 3},       // ����1���ڽӶ���Ϊ0��2��3
        {0, 1},          // ����2���ڽӶ���Ϊ0��1
        {1},             // ����3���ڽӶ���Ϊ1
    };
    int v = 0;           // �ж��Ƿ���ھ�������v�Ļ�·
    bool hasCycleV = hasCycle(graph, v);
    if (hasCycleV) {
        cout << "ͼ�д��ھ�������" << v << "�Ļ�·" << endl;
    }
    else {
        cout << "ͼ�в����ھ�������" << v << "�Ļ�·" << endl;
    }
    return 0;
}