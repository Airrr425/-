#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// ͼ��������ȱ����㷨
void dfs(const vector<vector<int>>& graph, int start, vector<bool>& visited) {
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
                stk.push(neighbor);       // �ڽӶ�����ջ
                visited[neighbor] = true; // ����ڽӶ���Ϊ�ѷ���
            }
        }
    }
}
// ����ͼ����ͨ��������
int countConnectedComponents(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);  // ��¼�����Ƿ��ѷ���
    int count = 0;                             // ��ͨ����������
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited); // ��δ���ʹ��Ķ������������ȱ���
            count++;                // ��ͨ����������1
        }
    }
    return count;
}
int main() {
    // ����ͼ���ڽӱ�洢
    vector<vector<int>> graph = {
        {1, 2},          // ����0���ڽӶ���Ϊ1��2
        {0, 3, 4},       // ����1���ڽӶ���Ϊ0��3��4
        {0, 4},          // ����2���ڽӶ���Ϊ0��4
        {1},             // ����3���ڽӶ���Ϊ1
        {1, 2},          // ����4���ڽӶ���Ϊ1��2
        {6},             // ����5���ڽӶ���Ϊ6
        {5},             // ����6���ڽӶ���Ϊ5
        {8, 9},          // ����7���ڽӶ���Ϊ8��9
        {7, 9},          // ����8���ڽӶ���Ϊ7��9
        {7, 8},          // ����9���ڽӶ���Ϊ7��8
    };
    // ���ü�����ͨ�����������㷨
    int numConnectedComponents = countConnectedComponents(graph);
    cout << "��ͨ��������: " << numConnectedComponents << endl;

    return 0;
}