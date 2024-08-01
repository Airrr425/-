#include <iostream>
#include <vector>
using namespace std;
// 定义图的顶点结构
struct Vertex {
    int value;              // 顶点的值
    vector<int> neighbors;  // 存储邻接顶点的索引
};
// 计算图的每个顶点的出度
void calculateOutDegree(const vector<Vertex>& graph) {
    int numVertices = graph.size();
    for (int i = 0; i < numVertices; i++) {
        int outDegree = graph[i].neighbors.size();
        cout << "顶点 " << i << " 的出度为：" << outDegree << endl;
    }
}
int main() {
    // 构建有向图的邻接表表示
    vector<Vertex> graph;

    // 添加顶点0及其邻接顶点
    Vertex v0;
    v0.value = 0;
    v0.neighbors.push_back(1);
    v0.neighbors.push_back(2);
    graph.push_back(v0);
    Vertex v1;
    v1.value = 1;
    v1.neighbors.push_back(2);
    v1.neighbors.push_back(3);
    graph.push_back(v1);
    // 添加顶点2及其邻接顶点
    Vertex v2;
    v2.value = 2;
    v2.neighbors.push_back(3);
    graph.push_back(v2);
    // 添加顶点3及其邻接顶点
    Vertex v3;
    v3.value = 3;
    v3.neighbors.push_back(0);
    graph.push_back(v3);
    // 调用算法计算每个顶点的出度
    calculateOutDegree(graph);
    return 0;
}