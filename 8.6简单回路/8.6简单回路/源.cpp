#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 图的深度优先遍历算法
void dfs(const vector<vector<int>>& graph, int start, int v, vector<bool>& visited, stack<int>& path) {
    visited[start] = true;              // 标记起始顶点为已访问
    path.push(start);                    // 将顶点加入当前路径中
    // 遍历当前顶点的邻接顶点
    for (int i = 0; i < graph[start].size(); i++) {
        int neighbor = graph[start][i];
        if (!visited[neighbor]) {
            if (neighbor == v) {          // 找到一个简单回路
                path.push(v);             // 将顶点v加入到路径中
                // 输出简单回路
                cout << "简单回路: ";
                while (!path.empty()) {
                    cout << path.top() << " ";
                    path.pop();
                }
                cout << endl;
                path.push(start);          // 将起始顶点重新加入到路径中，继续寻找其他回路
            }
            else {
                dfs(graph, neighbor, v, visited, path);  // 继续深度优先遍历
            }
        }
    }
    visited[start] = false;              // 恢复起始顶点的未访问状态
    path.pop();                          // 移除当前顶点
}
// 输出所有存在经过顶点v的简单回路
void printAllSimpleCycles(const vector<vector<int>>& graph, int v) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);  // 记录顶点是否已访问
    stack<int> path;                           // 保存当前路径
    dfs(graph, v, v, visited, path);            // 从顶点v开始深度优先遍历
}
int main() {
    // 构建图的邻接表存储
    vector<vector<int>> graph = {
        {1, 2},          // 顶点0的邻接顶点为1和2
        {0, 2, 3},       // 顶点1的邻接顶点为0、2和3
        {0, 1, 3},       // 顶点2的邻接顶点为0、1和3
        {1, 2},          // 顶点3的邻接顶点为1和2
    };
    int v = 0;           // 输出所有经过顶点v的简单回路
    printAllSimpleCycles(graph, v);
    return 0;
}