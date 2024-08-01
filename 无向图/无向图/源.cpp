#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAXV = 100;
const int MAXE = 200;
const int INF = 0x3f3f3f3f;

struct ArcNode			//边结点类型
{
    int adjvex;			//邻接点
    int weight;			//权值
    ArcNode* nextarc;		//指向下一条边的边结点
};

struct HNode			//头结点类型
{
    string info;			//顶点信息
    ArcNode* firstarc;		//指向第一条边的边结点
};

class AdjGraph				//图邻接表类
{
public:
    HNode adjlist[MAXV];			//头结点数组
    int n, e;				//顶点数，边数
    AdjGraph()				//构造函数
    {
        for (int i = 0; i < MAXV; i++)		//头结点的firstarc置为空
            adjlist[i].firstarc = NULL;
    }
    ~AdjGraph()				//析构函数,释放图的邻接表空间
    {
        ArcNode* pre, * p;
        for (int i = 0; i < n; i++)		//遍历所有的头结点
        {
            pre = adjlist[i].firstarc;
            if (pre != NULL)
            {
                p = pre->nextarc;
                while (p != NULL)		//释放adjlist[i]的所有边结点空间
                {
                    delete pre;
                    pre = p; p = p->nextarc; 	//pre和p指针同步后移
                }
                delete pre;
            }
        }
    }
    //图的基本运算算法
    void CreateAdjGraph(int a[][MAXV], int n, int e)
        //通过a、n和e来建立图的邻接表
    {
        ArcNode* p;
        this->n = n; this->e = e;				//置顶点数和边数
        for (int i = 0; i < n; i++)				//检查邻接矩阵中每个元素
            for (int j = n - 1; j >= 0; j--)
                if (a[i][j] != 0 && a[i][j] != INF)		//存在一条边
                {
                    p = new ArcNode();			//创建一个结点p
                    p->adjvex = j;
                    p->weight = a[i][j];
                    p->nextarc = adjlist[i].firstarc;	//采用头插法插入p
                    adjlist[i].firstarc = p;
                }
    }
    void DispAdjGraph()			//输出图的邻接表
    {
        ArcNode* p;
        for (int i = 0; i < n; i++)			//遍历每个头结点
        {
            printf("   [%d]", i);
            p = adjlist[i].firstarc;		//p指向第一个邻接点
            if (p != NULL)  printf("→");
            while (p != NULL)			//遍历第i个单链表
            {
                printf(" (%d,%d)", p->adjvex, p->weight);
                p = p->nextarc;			//p移向下一个邻接点
            }
            printf("\n");
        }
    }


    int visited[MAXV];			//全局数组
    void DFS(AdjGraph& G, int v)		//深度优先遍历(邻接表)
    {
        cout << v << " ";			//访问顶点v
        visited[v] = 1;				//置已访问标记
        ArcNode* p = G.adjlist[v].firstarc;	//p指向顶点v的第一个邻接点
        while (p != NULL)
        {
            int w = p->adjvex;			//邻接点为w
            if (visited[w] == 0) DFS(G, w);	//若w顶点未访问,递归访问它
            p = p->nextarc;			//p置为下一个邻接点
        }
    }

    void BFS(AdjGraph& G, int v)		//广度优先遍历(邻接表)
    {
        int visited[MAXV];
        memset(visited, 0, sizeof(visited));	//初始化visited数组
        queue<int> qu;			//定义一个队列
        cout << v << " ";			//访问顶点v
        visited[v] = 1;				//置已访问标记
        qu.push(v);				//顶点v进队 
        while (!qu.empty())			//队列不空循环
        {
            int u = qu.front(); qu.pop();	//出队顶点u
            ArcNode* p = G.adjlist[u].firstarc;	//找顶点u的第一个邻接点
            while (p != NULL)
            {
                if (visited[p->adjvex] == 0)	//若u的邻接点未访问
                {
                    cout << p->adjvex << " ";	//访问邻接点
                    visited[p->adjvex] = 1;	//置已访问标记
                    qu.push(p->adjvex);		//邻接点进队
                }
                p = p->nextarc;			//找下一个邻接点
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
    cout << "图的邻接表:\n";
    G.DispAdjGraph();
    cout << endl;
    G.DFS(G, n);
    cout << "销毁图\n";
    return 0;
}
