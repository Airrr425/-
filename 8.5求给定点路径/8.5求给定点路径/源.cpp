#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
// 定义图的数据结构
class Graph {
private:
    int numVertices;
    vector<list<int>> adjList;
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(numVertices);
    }
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
    vector<int> findPath(int source, int target) {      //给定u，v，寻找路径
        vector<bool> visited(numVertices, false);
        vector<int> parent(numVertices, -1);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            if (current == target) {
                // 找到了目标顶点，构建路径
                vector<int> path;
                int vertex = target;
                while (vertex != -1) {
                    path.insert(path.begin(), vertex);
                    vertex = parent[vertex];
                }
                return path;
            }
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                }
            }
        }
        // 未找到路径，返回空路径
        return {};
    }
    vector<int> findPathWithRequiredNodes(int source, int target, const unordered_set<int>& requiredNodes) {
        vector<bool> visited(numVertices, false);      //寻找需经过的节点
        vector<int> parent(numVertices, -1);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            if (current == target && containsRequiredNodes(parent, requiredNodes)) {
                // 找到了目标顶点并且路径包含了所有必经点，构建路径
                vector<int> path;
                int vertex = target;
                while (vertex != -1) {
                    path.insert(path.begin(), vertex);
                    vertex = parent[vertex];
                }
                return path;
            }
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                }
            }
        }
        // 未找到路径，返回空路径
        return {};
    }
    vector<int> findPathWithAvoidNodes(int source, int target, const unordered_set<int>& avoidNodes) {
        vector<bool> visited(numVertices, false);        //寻找需躲避的节点
        vector<int> parent(numVertices, -1);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            if (current == target && !containsAvoidNodes(parent, avoidNodes)) {
                // 找到了目标顶点并且路径不含有任何必避点，构建路径
                vector<int> path;
                int vertex = target;
                while (vertex != -1) {
                    path.insert(path.begin(), vertex);
                    vertex = parent[vertex];
                }
                return path;
            }
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                }
            }
        }
        // 未找到路径，返回空路径
        return {};
    }
private:
    bool containsRequiredNodes(const vector<int>& parent, const unordered_set<int>& requiredNodes) {
        for (int node : requiredNodes) {
            if (parent[node] == -1) {
                return false;
            }
        }
        return true;
    }
    bool containsAvoidNodes(const vector<int>& parent, const unordered_set<int>& avoidNodes) {
        for (int node : avoidNodes) {
            if (parent[node] != -1) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    Graph graph(15); // 创建一个含有15个顶点的图
    // 添加图的边
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 4);
    graph.addEdge(1, 5);
    graph.addEdge(2, 6);
    graph.addEdge(2, 7);
    graph.addEdge(3, 8);
    graph.addEdge(3, 9);
    graph.addEdge(4, 10);
    graph.addEdge(4, 11);
    graph.addEdge(5, 12);
    graph.addEdge(5, 13);
    graph.addEdge(6, 14);
    int source = 0;
    int target = 8;
    vector<int> path = graph.findPath(source, target);
    if (!path.empty()) {
        cout << "Path from " << source << " to " << target << ": ";
        for (int vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;
    }
    else {
        cout << "No path from " << source << " to " << target << " exists." << endl;
    }
    unordered_set<int> requiredNodes = { 1, 6 };
    vector<int> pathWithRequiredNodes = graph.findPathWithRequiredNodes(source, target, requiredNodes);
    if (!pathWithRequiredNodes.empty()) {
        cout << "Path from " << source << " to " << target << " with required nodes: ";
        for (int vertex : pathWithRequiredNodes) {
            cout << vertex << " ";
        }
        cout << endl;
    }
    else {
        cout << "No path from " << source << " to " << target << " with required nodes exists." << endl;
    }
    unordered_set<int> avoidNodes = { 7, 9 };
    vector<int> pathWithAvoidNodes = graph.findPathWithAvoidNodes(source, target, avoidNodes);
    if (!pathWithAvoidNodes.empty()) {
        cout << "Path from " << source << " to " << target << " avoiding nodes: ";
        for (int vertex : pathWithAvoidNodes) {
            cout << vertex << " ";
        }
        cout << endl;
    }
    else {
        cout << "No path from " << source << " to " << target << " avoiding nodes exists." << endl;
    }
    return 0;
}