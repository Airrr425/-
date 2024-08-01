#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;
// 图的顶点结构体
struct Vertex {
    int val;
    bool visited;
    vector<int> neighbors;
    Vertex(int v) : val(v), visited(false) {}
};
// 图的类
class Graph {
private:
    vector<Vertex> vertices;  // 存储图的顶点
public:
    Graph(int n) {
        vertices.resize(n);
        for (int i = 0; i < n; i++) {
            vertices[i] = Vertex(i);
        }
    }
    // 添加边
    void addEdge(int u, int v) {
        vertices[u].neighbors.push_back(v);
        vertices[v].neighbors.push_back(u);
    }
    // 深度优先遍历
    void dfsTraversal(int start, vector<int>& result) {
        result.push_back(start);
        vertices[start].visited = true;
        for (int neighbor : vertices[start].neighbors) {
            if (!vertices[neighbor].visited) {
                dfsTraversal(neighbor, result);
            }
        }
    }
    // 广度优先遍历
    void bfsTraversal(int start, vector<int>& result) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            result.push_back(current);
            for (int neighbor : vertices[current].neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
    // 删除顶点并更新图的信息
    void removeVertex(int v) {
        vertices[v].visited = true;
        for (int neighbor : vertices[v].neighbors) {
            vertices[neighbor].neighbors.erase(
                remove(vertices[neighbor].neighbors.begin(),
                    vertices[neighbor].neighbors.end(), v),
                vertices[neighbor].neighbors.end());
            if (!vertices[neighbor].visited) {
                removeVertex(neighbor);
            }
        }
    }
};
int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    Graph graph(numVertices);
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    int removeVertex;
    cin >> removeVertex;
    vector<int> dfsResult;
    graph.dfsTraversal(0, dfsResult);
    vector<int> bfsResult;
    graph.removeVertex(removeVertex);
    graph.bfsTraversal(0, bfsResult);
    // 输出深度优先遍历的顶点序列
    for (int vertex : dfsResult) {
        cout << vertex << " ";
    }
    cout << endl;
    // 输出广度优先遍历的顶点序列
    for (int vertex : bfsResult) {
        cout << vertex << " ";
    }
    cout << endl;
    return 0;
}