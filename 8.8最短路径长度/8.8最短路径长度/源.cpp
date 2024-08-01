#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// 找到还未处理的距离最小的顶点
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
// 使用狄克斯特拉算法求最短路径长度
int dijkstra(const vector<vector<int>>& graph, int source, int target) {
    int numVertices = graph.size();
    vector<int> distance(numVertices, INT_MAX);  // 记录源点到各顶点的最短路径长度
    vector<bool> visited(numVertices, false);    // 记录顶点是否被访问过
    distance[source] = 0;   // 源点到自身的距离为0
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
    // 构建带权图的邻接矩阵存储
    vector<vector<int>> graph = {
        {0, 10, 3, 0},
        {0, 0, 1, 2},
        {0, 4, 0, 8},
        {0, 0, 0, 0},
    };
    int source = 0;  // 源点编号
    int target = 3;  // 目标点编号
    int shortestDistance = dijkstra(graph, source, target);
    if (shortestDistance == INT_MAX) {
        cout << "顶点" << source << "到顶点" << target << "没有路径" << endl;
    }
    else {
        cout << "顶点" << source << "和顶点" << target << "之间的最短路径长度为：" << shortestDistance << endl;
    }
    return 0;
}