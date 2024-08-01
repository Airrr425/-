#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;
// ͼ�Ķ���ṹ��
struct Vertex {
    int val;
    bool visited;
    vector<int> neighbors;
    Vertex(int v) : val(v), visited(false) {}
};
// ͼ����
class Graph {
private:
    vector<Vertex> vertices;  // �洢ͼ�Ķ���
public:
    Graph(int n) {
        vertices.resize(n);
        for (int i = 0; i < n; i++) {
            vertices[i] = Vertex(i);
        }
    }
    // ��ӱ�
    void addEdge(int u, int v) {
        vertices[u].neighbors.push_back(v);
        vertices[v].neighbors.push_back(u);
    }
    // ������ȱ���
    void dfsTraversal(int start, vector<int>& result) {
        result.push_back(start);
        vertices[start].visited = true;
        for (int neighbor : vertices[start].neighbors) {
            if (!vertices[neighbor].visited) {
                dfsTraversal(neighbor, result);
            }
        }
    }
    // ������ȱ���
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
    // ɾ�����㲢����ͼ����Ϣ
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
    // ���������ȱ����Ķ�������
    for (int vertex : dfsResult) {
        cout << vertex << " ";
    }
    cout << endl;
    // ���������ȱ����Ķ�������
    for (int vertex : bfsResult) {
        cout << vertex << " ";
    }
    cout << endl;
    return 0;
}