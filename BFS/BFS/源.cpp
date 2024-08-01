#include<iostream>
#include<sstream>
#include<vector>
#include <algorithm>
#include <string>
#include<queue>
using namespace std;

//边结点类型
struct ArcNode {
    int adjvex;
    ArcNode* nextarc;
};
//头结点类型
struct HNode {
    int info;
    ArcNode* firstarc;
};

//读数据
vector<int> inputRead() {
    vector<int> nums;
    string str, numStr;
    while (getline(cin, str)) {
        istringstream ss(str);
        while (ss >> numStr) {
            int num = atoi(numStr.c_str());
            nums.push_back(num);
        }
    }
    return nums;

}

//创建邻接表
vector<HNode> createAdjGraph(const vector<int>& nums) {
    int p = 0;
    int n = nums[p];  //输入的第一个数
    int e = nums[++p];   //输入的第二个数
    // 创建头结点数组
    vector<HNode> adjGraph(n);
    for (int i = 0; i < n; i++) {
        adjGraph[i].info = i;
        adjGraph[i].firstarc = NULL;
    }
    //创建邻接表
    for (int i = 0; i < e; i++) {
        int u = nums[++p];   //输入的两个节点
        int v = nums[++p];
        ArcNode* node1 = new ArcNode();
        node1->adjvex = v;
        node1->nextarc = NULL;
        //使邻接表中节点按编号升序排列
        //若邻接表为空，或者第一个节点的编号大于v，直接用头插法
        //否则，找到第一个编号大于v的节点，对它用头插法

        if (adjGraph[u].firstarc == NULL || adjGraph[u].firstarc->adjvex > v) {
            node1->nextarc = adjGraph[u].firstarc;
            adjGraph[u].firstarc = node1;
        }
        else {
            ArcNode* current = adjGraph[u].firstarc;
            while (current->nextarc != NULL && current->nextarc->adjvex < v) {
                current = current->nextarc;
            }
            node1->nextarc = current->nextarc;
            current->nextarc = node1;
        }
        //无向图导致的
        int temp = u;
        u = v;
        v = temp;
        ArcNode* node2 = new ArcNode();
        node2->adjvex = v;
        node2->nextarc = NULL;
        if (adjGraph[u].firstarc == NULL || adjGraph[u].firstarc->adjvex > v) {
            node2->nextarc = adjGraph[u].firstarc;
            adjGraph[u].firstarc = node2;
        }
        else {
            ArcNode* current = adjGraph[u].firstarc;
            while (current->nextarc != NULL && current->nextarc->adjvex < v) {
                current = current->nextarc;
            }
            node2->nextarc = current->nextarc;
            current->nextarc = node2;
        }
    }
    return adjGraph;
}

//DFS
void DFS(const vector<HNode>& adjGraph, vector<bool>& visited, int begin) {
    cout << begin << " ";
    visited[begin] = true;
    ArcNode* arc = adjGraph[begin].firstarc;
    while (arc != NULL) {
        int adjNode = arc->adjvex;
        if (!visited[adjNode]) {
            DFS(adjGraph, visited, adjNode);
        }
        arc = arc->nextarc;
    }
}

//删除一个节点
void deleteNode(int v, vector<HNode>& adjGraph) {
    int n = adjGraph.size();
    // 删除相关边
    while (adjGraph[v].firstarc != NULL) {
        ArcNode* temp = adjGraph[v].firstarc;
        adjGraph[v].firstarc = temp->nextarc;
        delete temp;
    }
    // 更新其他顶点的邻接表
    for (int i = 0; i < n; ++i) {
        if (i != v) {
            ArcNode* prev = NULL;
            ArcNode* curr = adjGraph[i].firstarc;
            while (curr != NULL) {
                if (curr->adjvex == v) {
                    if (prev == NULL) {
                        adjGraph[i].firstarc = curr->nextarc;
                    }
                    else {
                        prev->nextarc = curr->nextarc;
                    }
                    delete curr;
                    break;
                }
                prev = curr;
                curr = curr->nextarc;
            }
        }
    }
}

//BFS
void BFS(const vector<HNode>& adjGraph, vector<bool>& visited, int begin) {
    queue<int> q;
    cout << begin << " ";
    visited[begin] = true;
    q.push(begin);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ArcNode* arc = adjGraph[u].firstarc;
        while (arc != NULL) {
            if (!visited[arc->adjvex]) {
                cout << arc->adjvex << " ";
                visited[arc->adjvex] = true;
                q.push(arc->adjvex);
            }
            arc = arc->nextarc;
        }
    }
}
int main() {
    vector<int> nums = inputRead();
    vector<HNode> adjGraph = createAdjGraph(nums);
    vector<bool> visited1(adjGraph.size(), false);
    vector<bool> visited2(adjGraph.size(), false);
    vector<bool> visited(adjGraph.size(), false);
    DFS(adjGraph, visited1, 0);
    cout << endl;
    int v = nums[nums.size() - 1];
    deleteNode(v, adjGraph);
    BFS(adjGraph, visited2, 0);
    cout << endl;
}