#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 图的深度优先遍历算法
bool dfs(const vector<vector<int>>& graph, int start, int v, vector<bool>& visited) {
    stack<int> stk;
    stk.push(start);                      // 将起始顶点入栈
    visited[start] = true;                // 标记起始顶点为已访问
    while (!stk.empty()) {
        int currVertex = stk.top();       // 取出栈顶元素
        stk.pop();                        // 将栈顶元素出栈
        // 遍历当前顶点的邻接顶点
        for (int i = 0; i < graph[currVertex].size(); i++) {
            int neighbor = graph[currVertex][i];
            if (!visited[neighbor]) {
                if (neighbor == v) {
                    return true;           // 顶点v为回路的一部分，返回true
                }
                stk.push(neighbor);       // 邻接顶点入栈
                visited[neighbor] = true; // 标记邻接顶点为已访问
            }
        }
    }
    return false;                          // 未找到回路，返回false
}
// 判断图中是否存在经过顶点v的回路
bool hasCycle(const vector<vector<int>>& graph, int v) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);  // 记录顶点是否已访问
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, v, visited)) {
                return true;    // 存在经过顶点v的回路，返回true
            }
        }
    }
    return false;           // 不存在经过顶点v的回路，返回false
}
int main() {
    vector<vector<int>> graph = {
        {1, 2},          // 顶点0的邻接顶点为1和2
        {0, 2, 3},       // 顶点1的邻接顶点为0、2和3
        {0, 1},          // 顶点2的邻接顶点为0和1
        {1},             // 顶点3的邻接顶点为1
    };
    int v = 0;           // 判断是否存在经过顶点v的回路
    bool hasCycleV = hasCycle(graph, v);
    if (hasCycleV) {
        cout << "图中存在经过顶点" << v << "的回路" << endl;
    }
    else {
        cout << "图中不存在经过顶点" << v << "的回路" << endl;
    }
    return 0;
}