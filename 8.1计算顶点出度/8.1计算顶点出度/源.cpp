#include <iostream>
#include <vector>
using namespace std;
// ����ͼ�Ķ���ṹ
struct Vertex {
    int value;              // �����ֵ
    vector<int> neighbors;  // �洢�ڽӶ��������
};
// ����ͼ��ÿ������ĳ���
void calculateOutDegree(const vector<Vertex>& graph) {
    int numVertices = graph.size();
    for (int i = 0; i < numVertices; i++) {
        int outDegree = graph[i].neighbors.size();
        cout << "���� " << i << " �ĳ���Ϊ��" << outDegree << endl;
    }
}
int main() {
    // ��������ͼ���ڽӱ��ʾ
    vector<Vertex> graph;

    // ��Ӷ���0�����ڽӶ���
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
    // ��Ӷ���2�����ڽӶ���
    Vertex v2;
    v2.value = 2;
    v2.neighbors.push_back(3);
    graph.push_back(v2);
    // ��Ӷ���3�����ڽӶ���
    Vertex v3;
    v3.value = 3;
    v3.neighbors.push_back(0);
    graph.push_back(v3);
    // �����㷨����ÿ������ĳ���
    calculateOutDegree(graph);
    return 0;
}