#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 图的深度优先遍历算法
void dfs(const vector<vector<int>>& graph, int start, vector<bool>& visited) {
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
                stk.push(neighbor);       // 邻接顶点入栈
                visited[neighbor] = true; // 标记邻接顶点为已访问
            }
        }
    }
}
// 计算图的连通分量个数
int countConnectedComponents(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);  // 记录顶点是否已访问
    int count = 0;                             // 连通分量计数器
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited); // 对未访问过的顶点进行深度优先遍历
            count++;                // 连通分量个数加1
        }
    }
    return count;
}
int main() {
    // 构建图的邻接表存储
    vector<vector<int>> graph = {
        {1, 2},          // 顶点0的邻接顶点为1和2
        {0, 3, 4},       // 顶点1的邻接顶点为0、3和4
        {0, 4},          // 顶点2的邻接顶点为0和4
        {1},             // 顶点3的邻接顶点为1
        {1, 2},          // 顶点4的邻接顶点为1和2
        {6},             // 顶点5的邻接顶点为6
        {5},             // 顶点6的邻接顶点为5
        {8, 9},          // 顶点7的邻接顶点为8和9
        {7, 9},          // 顶点8的邻接顶点为7和9
        {7, 8},          // 顶点9的邻接顶点为7和8
    };
    // 调用计算连通分量个数的算法
    int numConnectedComponents = countConnectedComponents(graph);
    cout << "连通分量个数: " << numConnectedComponents << endl;

    return 0;
}