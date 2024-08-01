#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAXV = 100;
const int MAXE = 200;
const int INF = 0x3f3f3f3f;

struct ArcNode			//�߽������
{
    int adjvex;			//�ڽӵ�
    int weight;			//Ȩֵ
    ArcNode* nextarc;		//ָ����һ���ߵı߽��
};

struct HNode			//ͷ�������
{
    string info;			//������Ϣ
    ArcNode* firstarc;		//ָ���һ���ߵı߽��
};

class AdjGraph				//ͼ�ڽӱ���
{
public:
    HNode adjlist[MAXV];			//ͷ�������
    int n, e;				//������������
    AdjGraph()				//���캯��
    {
        for (int i = 0; i < MAXV; i++)		//ͷ����firstarc��Ϊ��
            adjlist[i].firstarc = NULL;
    }
    ~AdjGraph()				//��������,�ͷ�ͼ���ڽӱ�ռ�
    {
        ArcNode* pre, * p;
        for (int i = 0; i < n; i++)		//�������е�ͷ���
        {
            pre = adjlist[i].firstarc;
            if (pre != NULL)
            {
                p = pre->nextarc;
                while (p != NULL)		//�ͷ�adjlist[i]�����б߽��ռ�
                {
                    delete pre;
                    pre = p; p = p->nextarc; 	//pre��pָ��ͬ������
                }
                delete pre;
            }
        }
    }
    //ͼ�Ļ��������㷨
    void CreateAdjGraph(int a[][MAXV], int n, int e)
        //ͨ��a��n��e������ͼ���ڽӱ�
    {
        ArcNode* p;
        this->n = n; this->e = e;				//�ö������ͱ���
        for (int i = 0; i < n; i++)				//����ڽӾ�����ÿ��Ԫ��
            for (int j = n - 1; j >= 0; j--)
                if (a[i][j] != 0 && a[i][j] != INF)		//����һ����
                {
                    p = new ArcNode();			//����һ�����p
                    p->adjvex = j;
                    p->weight = a[i][j];
                    p->nextarc = adjlist[i].firstarc;	//����ͷ�巨����p
                    adjlist[i].firstarc = p;
                }
    }
    void DispAdjGraph()			//���ͼ���ڽӱ�
    {
        ArcNode* p;
        for (int i = 0; i < n; i++)			//����ÿ��ͷ���
        {
            printf("   [%d]", i);
            p = adjlist[i].firstarc;		//pָ���һ���ڽӵ�
            if (p != NULL)  printf("��");
            while (p != NULL)			//������i��������
            {
                printf(" (%d,%d)", p->adjvex, p->weight);
                p = p->nextarc;			//p������һ���ڽӵ�
            }
            printf("\n");
        }
    }


    int visited[MAXV];			//ȫ������
    void DFS(AdjGraph& G, int v)		//������ȱ���(�ڽӱ�)
    {
        cout << v << " ";			//���ʶ���v
        visited[v] = 1;				//���ѷ��ʱ��
        ArcNode* p = G.adjlist[v].firstarc;	//pָ�򶥵�v�ĵ�һ���ڽӵ�
        while (p != NULL)
        {
            int w = p->adjvex;			//�ڽӵ�Ϊw
            if (visited[w] == 0) DFS(G, w);	//��w����δ����,�ݹ������
            p = p->nextarc;			//p��Ϊ��һ���ڽӵ�
        }
    }

    void BFS(AdjGraph& G, int v)		//������ȱ���(�ڽӱ�)
    {
        int visited[MAXV];
        memset(visited, 0, sizeof(visited));	//��ʼ��visited����
        queue<int> qu;			//����һ������
        cout << v << " ";			//���ʶ���v
        visited[v] = 1;				//���ѷ��ʱ��
        qu.push(v);				//����v���� 
        while (!qu.empty())			//���в���ѭ��
        {
            int u = qu.front(); qu.pop();	//���Ӷ���u
            ArcNode* p = G.adjlist[u].firstarc;	//�Ҷ���u�ĵ�һ���ڽӵ�
            while (p != NULL)
            {
                if (visited[p->adjvex] == 0)	//��u���ڽӵ�δ����
                {
                    cout << p->adjvex << " ";	//�����ڽӵ�
                    visited[p->adjvex] = 1;	//���ѷ��ʱ��
                    qu.push(p->adjvex);		//�ڽӵ����
                }
                p = p->nextarc;			//����һ���ڽӵ�
            }
        }
    }
};

int main() {
    AdjGraph G;
    int n, e;
    cin >> n >> e;
    cout << endl;
    int A[MAXV][MAXV] = { { 0, 8, INF, 5, INF }, { INF, 0, 3, INF, INF }, { INF, INF, 0, INF, 6 }, { INF, INF, 9, 0, INF }, { INF, INF, INF, INF, 0 } };
    G.CreateAdjGraph(A, n, e);
    cout << "ͼ���ڽӱ�:\n";
    G.DispAdjGraph();
    cout << endl;
    G.DFS(G, n);
    cout << "����ͼ\n";
    return 0;
}
