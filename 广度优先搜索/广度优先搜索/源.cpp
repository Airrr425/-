#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 图的广度优先遍历算法
void bfs(const vector<vector<int>>& graph, int start) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);  // 记录顶点是否已访问
    queue<int> q;                              // 辅助队列，用于广度优先遍历
    visited[start] = true;  // 标记起始顶点为已访问
    q.push(start);          // 将起始顶点入队
    while (!q.empty()) {
        int currVertex = q.front();  // 取出队列中的当前顶点
        q.pop();                     // 将当前顶点出队
        cout << currVertex << " ";   // 输出当前顶点
        // 遍历当前顶点的邻接顶点
        for (int i = 0; i < numVertices; i++) {
            if (graph[currVertex][i] == 1 && !visited[i]) {
                // 如果邻接顶点未被访问过，则标记为已访问且入队
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main() {
    // 构建图的邻接矩阵存储
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };
    // 调用广度优先遍历算法，从顶点0开始遍历
    bfs(graph, 0);
    return 0;
}