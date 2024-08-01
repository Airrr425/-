#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 判断有向图是否存在回路
bool hasCycle(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<int> inDegree(numVertices, 0);  // 记录每个顶点的入度
    // 计算每个顶点的入度
    for (int i = 0; i < numVertices; i++) {
        for (int neighbor : graph[i]) {
            inDegree[neighbor]++;
        }
    }
    queue<int> q;
    // 将入度为0的顶点加入队列
    for (int i = 0; i < numVertices; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    int count = 0;  // 记录已访问的顶点数
    // 拓扑排序
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        count++;
        for (int neighbor : graph[current]) {
            // 移除当前顶点的邻接顶点的入度
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return count != numVertices;  // 如果访问的顶点数不等于总数，说明存在回路
}
int main() {
    // 构建有向图的邻接表存储
    vector<vector<int>> graph = {
        {1},    // 顶点0的邻接顶点为1
        {2, 3}, // 顶点1的邻接顶点为2和3
        {3},    // 顶点2的邻接顶点为3
        {},     // 顶点3没有邻接顶点
    };
    bool hasCycleFlag = hasCycle(graph);
    if (hasCycleFlag) {
        cout << "图中存在回路" << endl;
    }
    else {
        cout << "图中不存在回路" << endl;
    }
    return 0;
}