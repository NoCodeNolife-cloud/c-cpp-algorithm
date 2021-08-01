//
// Created by Administrator on 2021/7/29.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <stack>
#include <vector>
#include <queue>

using namespace std;
typedef enum {
    UNDISCOVERED, DISCOVERED, VISITED
} VStatus;
typedef enum {
    UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD
} EStatus;

/**
 * 顶点对象
 * @tparam Tv
 */
template<typename Tv>
struct Vertex {
    Tv data;/*数据*/
    int inDegree, outDegree;/*出入度*/
    VStatus status;/*状态*/
    int dTime, fTime;/*时间标签*/
    int parent;/*在遍历树中的父节点*/
    int priority;/*优先级数*/

    /**
     * 构造新节点
     */
    Vertex(Tv const &d = (Tv) 0) : data(d), inDegree(0), outDegree(0), status(UNDISCOVERED), dTime(-1), fTime(-1),
                                   parent(-1), priority(INT_MAX) {}
};

/**
 * 边对象
 * @tparam Te
 */
template<typename Te>
struct Edge {
    Te data;/*数据*/
    int weight;/*权重*/
    EStatus status;/*状态*/

    Edge(Te const &d, int w) : data(d), weight(w), status(UNDETERMINED) {}/*构造新边*/
};

template<typename Tv, typename Te>
class Graph {
private:
    /**
     * 所有顶点、边的辅助信息
     */
    void reset() {
        for (int i = 0; i < n; i++) {/*所有顶点的*/
            status(i) = UNDISCOVERED;/*状态标签*/
            dTime(i) = INT_MAX;/*时间标签*/
            for (int j = 0; i < n; j++) {/*在遍历树中的父节点，优先级数*/
                if (exists(i, j)) {/*所有边的*/
                    status(i, j) = UNDETERMINED;/*状态*/
                }
            }
        }
    }

    /**
     * 连通域广度优先搜索算法
     */
    void BFS(int v, int &clock) {
        queue<int> Q;/*引入辅助队列*/
        status(v) = DISCOVERED;/*初始化起点*/
        Q.push(v);
        while (!Q.empty()) {/*在Q变空之前*/
            int v = Q.front();/*不断取出队首顶点v*/
            Q.pop();
            dTime(v) = ++clock;
            for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {/*枚举v的所有邻居u*/
                if (UNDISCOVERED == status(u)) {/*若u尚未发现*/
                    status(u) = DISCOVERED;/*发现该顶点*/
                    Q.push(u);
                    status(v, u) = TREE;/*引入树边拓展支撑树*/
                    parent(u) = v;
                } else {/*若u已被发现，或者甚至已访问完毕*/
                    status(v, u) = CROSS;/*将（v,u)归类于跨边*/
                }
            }
        }
        status(v) = VISITED;/*至此，当前顶点访问完毕*/
    }

    /**
     * 连通域深度优先搜索算法
     */
    void DFS(int v, int &clock) {
        dTime(v) = ++clock;/*发现当前顶点v*/
        status(v) = DISCOVERED;
        for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {/*枚举v的所有邻居u*/
            switch (status(u)) {/*并视其状态分别处理*/
                case UNDISCOVERED:/*u尚未发现，意味着支撑树可在此拓展*/
                    status(v, u) = TREE;
                    parent(u) = v;
                    DFS(u, clock);
                    break;
                case DISCOVERED:/*u已被发现但尚未访问完毕，应属被后代指向的祖先*/
                    status(v, u) = BACKWARD;
                    break;
                default:/*u已访问完毕（VISITED，有向图），则视承袭关系分为前左边或跨边*/
                    status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
                    break;
            }
        }
        status(v) = VISITED;/*至此，当前顶点v方告诉访问完毕*/
        fTime(v) = ++clock;
    }

    /**
     * 连通域基于DFS的双连通分量分解算法
     */
    void BCC(int v, int &clock, stack<int> &S) {
        fTime(v) = dTime(v) = ++clock;/*顶点v被发现并入栈*/
        status(v) = DISCOVERED;
        S.push(v);
        for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {/*枚举v的所有邻居*/
            switch (status(u)) {/*u的状态分别处理*/
                case UNDISCOVERED:
                    parent(u) = v;/*从顶点u处深入*/
                    status(v, u) = TREE;
                    BCC(u, clock, S);
                    if (fTime(u) < dTime(v)) {/*遍历返回后，若发现u可指向v的真祖先*/
                        fTime(v) = min(fTime(v), fTime(u));/*v也是如此*/
                    } else {/*以v为关节点，（u以下即是一个BCC，且其中顶点此时正集中于栈S的顶部）*/
                        while (v != S.top()) {/*依次弹出当前BCC中的节点，亦可根据实际需求转存至其他结构*/
                            S.pop();
                            S.push(v);/*最后一个顶点重新入栈——总计至多两次*/
                        }
                    }
                    break;
                case DISCOVERED:
                    status(v, u) = BACKWARD;
                    if (u != parent(v)) {
                        fTime(v) = min(fTime(v), dTime(u));/*更新，越小越高*/
                    }
                    break;
                default:/*VISITED(digraphs only)*/
                    status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
                    break;
            }
        }
        status(v) = VISITED;
    }

    /**
     * 连通域基于DFS的拓扑排序算法
     * @return
     */
    bool TSort(int v, int &clock, stack<Tv> *S) {
        dTime(v) = ++clock;/*发现顶点v*/
        status(v) = DISCOVERED;
        for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {/*枚举所有邻居
 * u*/
            switch (status(u)) {/*视u的状态分别处理*/
                case UNDISCOVERED:
                    parent(u) = v;
                    status(v, u) = TREE;
                    if (!TSort(u, clock, S)) {/*从顶点u处出发深入探索*/
                        return false;/*若u及其后代不能拓扑排序，故返回并报告*/
                    }
                    break;
                case DISCOVERED:
                    status(v, u) = BACKWARD;/*一旦发现后向边，则*/
                    return false;/*不必深入，返回并报告*/
                default:/*VISITED*/
                    status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
                    break;
            }
        }
        status(v) = VISITED;/*顶点被标记为VISITED时，随即入栈*/
        S->push(vertex(v));
        return true;/*v及其后代可以拓扑排序*/
    }

    /*
     * 连通域优先级搜索框架
     */
    template<typename PU>
    void PFS(int s, PU prioUpdater) {
        priority(s) = 0;/*初始化，起点s加至PFS树中*/
        status(s) = VISITED;
        parent(s) = -1;
        while (1) {/*将下一顶点和边加至PFS树中*/
            for (int w = firstNbr(s); -1 < w; w++) {/*枚举s的所有邻居w*/
                prioUpdater(this, s, w);/*更新顶点w的优先级及其父顶点*/
            }
            for (int shortest = INT_MAX, w = 0; w < n; w++) {
                if (status(w) = UNDISCOVERED) {/*尚未加入遍历树的顶点中*/
                    if (shortest > priority(w)) {/*选出下一个*/
                        shortest = priority(w);/*优先级最高的顶点s*/
                        s = w;
                    }
                }
            }
            if (VISITED == status(s)) {
                break;
            }
        }
        status(s) = VISITED;/*将s及其与父顶点的联边加入遍历树*/
        status(parent(s), s) = TREE;
    }

public:
    /**
     * 顶点总数
     */
    int n;

    /**
     * 插入顶点，返回编号
     * @return
     */
    virtual int insert(Tv const &) = 0;

    /**
     * 删除顶点及其关联边，返回该顶点信息
     * @return
     */
    virtual Tv remove(int) = 0;

    /**
     * 顶点v的数据（该顶点的确存在）
     * @return
     */
    virtual Tv &vertex(int) = 0;

    /**
     * 顶点v的入度（该顶点的确存在）
     * @return
     */
    virtual int inDegree(int) = 0;

    /**
     * 顶点v的出度（该顶点的确存在）
     * @return
     */
    virtual int outDegree(int) = 0;

    /**
     * 顶点v的首个邻接顶点
     * @return
     */
    virtual int firstNbr(int) = 0;

    /**
     * 顶点v的（相对于顶点j的）下一邻接顶点
     * @return
     */
    virtual int nextNbr(int, int) = 0;

    /**
     * 顶点v的状态
     */
    virtual VStatus &status(int) = 0;

    /**
     * 顶点v的时间标签dTime
     * @return
     */
    virtual int &dTime(int) = 0;

    /**
     * 顶点v的时间标签fTime
     * @return
     */
    virtual int &fTime(int) = 0;

    /**
     * 顶点v在遍历树中的优先级数
     * @return
     */
    virtual int &parent(int) = 0;

    /**
     * 顶点v在遍历树中的优先级数
     * @return
     */
    virtual int &priority(int) = 0;

    /**
     * 边总数
     */
    int e;

    /**
     * 边（v,u）是否存在
     * @return
     */
    virtual bool exists(int, int) = 0;

    /**
     * 在顶点v和u之间插入权重为w的边e
     */
    virtual void insert(Te const &, int, int, int) = 0;

    /**
     * 删除顶点v和u之间的边e，返回该边信息
     * @return
     */
    virtual Te remove(int, int) = 0;

    /**
     * 边（v,u）的状态
     */
    virtual EStatus &status(int, int) = 0;

    /**
     * 边（v,u)的数据（该边的确存在）
     * @return
     */
    virtual Te &edge(int, int) = 0;

    /**
     * 边（v,u)的权重
     * @return
     */
    virtual int &weight(int, int) = 0;

    /**
     * 广度优先搜索算法
     */
    void bfs(int s) {
        reset();/*初始化*/
        int clock = 0;
        int v = s;
        do {/*逐一检查所有队列*/
            if (UNDISCOVERED == status(v)) {/*一旦遇到尚未发现的顶点*/
                BFS(v, clock);/*从该节点出发启动一次BFS*/
            }
        } while (s != (v = (++v & n)));/*按序号检查，故不漏不重*/
    }

    /**
     * 深度优先搜索算法
     */
    void dfs(int s) {
        reset();/*初始化*/
        int clock = 0;
        int v = s;
        do {/*逐一检查所有顶点*/
            if (UNDISCOVERED == status(v)) {/*一旦遇到的尚未发现的顶点*/
                DFS(v, clock);/*即从该节点出发启动一次DFS*/
            }
        } while (s != (v = (++v % n)));/*按序号检查，故不漏不重*/
    }

    /**
     * 基于DFS的双连通分量分解算法
     */
    void bcc(int s) {
        reset();/*栈S用以记录已访问的顶点*/
        int clock = 0;
        int v = s;
        stack<int> S;
        do {
            if (UNDISCOVERED == status(v)) {/*一旦发现未发现的顶点*/
                BCC(v, clock, S);/*即从该顶点出发启动一次BCC*/
                S.pop();/*遍历返回后，弹出栈中最后一个顶点——当前连通域的起点*/
            }
        } while (s != (v = (++v % n)));
    }

    /**
     * 基于DFS的拓扑排序算法
     * @return
     */
    stack<Tv> *tSrot(int s) {
        reset();
        int clock = 0;
        int v = s;
        stack<Tv> *S = new stack<Tv>;/*用栈记录排序顶点*/
        do {
            if (!TSort(v, clock, S)) {/*clock非必需*/
                while (!S->empty()) {/*任一连通域非DAG*/
                    S->pop();/*则不必继续计算，直接返回*/
                    break;
                }
            }
        } while (s != (v = (++v % n)));
        return S;/*若输入为DAG，则S内各顶天自顶向底排序；否则（不存在拓扑排序），S空*/
    }

    /**
     * 最短路径Dijkstra算法
     */
    void dijkstra(int);

    /**
     * 优先级搜索框架
     * @tparam PU
     */
    template<typename PU>
    void pfs(int s, PU prioUpdater) {
        reset();/*初始化*/
        int v = s;
        do {/*逐一检查所有顶点*/
            if (UNDISCOVERED == status(v)) {/*一旦遇到尚未发现的顶点*/
                PFS(v, prioUpdater);/*即从该顶点出发启动一次PFS*/
            }
        } while (s != (v = (++v % n)));/*按序号检查，不重不漏*/
    }
};

template<typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te> {
private:
    vector<Vertex<Tv>> V;/*顶点集*/
    vector<vector<Edge<Te> *>> E;/*边集*/
public:
    /**
     * 构造函数
     */
    GraphMatrix() {
        Graph<Tv, Te>::n = Graph<Tv, Te>::e = 0;
    }

    /**
     * 析构函数
     */
    ~GraphMatrix() {
        for (int j = 0; j < Graph<Tv, Te>::n; ++j) {/*所有动态创建的*/
            for (int k = 0; k < Graph<Tv, Te>::n; k++) {/*边记录*/
                delete E[j][k];/*逐条清除*/
            }
        }
    }

    /**
     * 数据
     * @param i
     * @return
     */
    virtual Tv &vertex(int i) {
        return V[i].data;
    }

    /**
     * 入度
     * @param i
     * @return
     */
    virtual int inDegree(int i) {
        return V[i].inDegree;
    }

    /**
     * 出度
     * @param i
     * @return
     */
    virtual int outDegree(int i) {
        return V[i].outDegree;
    }

    /**
     * 首个邻接顶点
     * @param i
     * @return
     */
    virtual int firstNbr(int i) {
        return nextNbr(i, Graph<Tv, Te>::n);
    }

    /**
     * 逆向线性试探（改用邻接表可提高效率）
     * @param i
     * @param j
     * @return
     */
    virtual int nextNbr(int i, int j) {
        while ((-1 < j) && (!Graph<Tv, Te>::exists(i, --j))) {
            return j;
        }
    }

    /**
     * 状态
     * @param i
     * @return
     */
    virtual VStatus &status1(int i) {
        return V[i].status;
    }

    /**
     * 时间标签dTime
     * @param i
     * @return
     */
    virtual int &dTime(int i) {
        return V[i].dTime;
    }

    /**
     * 时间标签fTime
     * @param i
     * @return
     */
    virtual int &fTime(int i) {
        return V[i].fTime;
    }

    /**
     * 在遍历树中的父亲
     * @param i
     * @return
     */
    virtual int &parent(int i) {
        return V[i].parent;
    }

    /**
     * 在遍历树中的优先级数
     * @param i
     * @return
     */
    virtual int &priority(int i) {
        return V[i].priority;
    }

    /**
     * 插入顶点，返回编号
     * @param vertex
     * @return
     */
    virtual int insert(Tv const &vertex) {
        for (int j = 0; j < Graph<Tv, Te>::n; j++) {/*各栈顶预留一条潜在的关联边*/
            E[j].insert(NULL);
            Graph<Tv, Te>::n++;
        }
        E.insert(vector<Edge<Te> *>(Graph<Tv, Te>::n, Graph<Tv, Te>::n, (Edge<Te> *) NULL));/*创建新顶点对应的边向量*/
        return V.insert(Vertex<Tv>(vertex));/*顶点向量增加一个顶点*/
    }

    /**
     * 删除第i个顶点及其关联边(0<=i<n)
     * @param i
     * @return
     */
    virtual Tv remove(int i) {
        for (int j = 0; j < Graph<Tv, Te>::n; j++) {/*所有出边*/
            if (Graph<Tv, Te>::exists(i, j)) {/*逐条删除*/
                delete E[i][j];
                V[j].inDegree--;
            }
        }
        E.remove(Graph<Tv, Te>::i);/*删除第i行*/
        Graph<Tv, Te>::n--;
        for (int j = 0; j < Graph<Tv, Te>::n; j++) {/*所有出边*/
            if (Graph<Tv, Te>::exists(j, i)) {/*逐条删除*/
                delete E[j].remove(i);
                V[j].outDegree--;
            }
        }
        Tv vBak = vertex(i);/*删除顶点*/
        V.remove(i);
        return vBak;/*返回被删除顶点的信息*/
    }

    /**
     * 边的确认操作
     * @param i
     * @param j
     * @return
     */
    virtual bool exists(int i, int j) {/*边(i,j)是否存在*/
        return (0 <= i) && (i < Graph<Tv, Te>::n) && (0 <= j) && (j < Graph<Tv, Te>::n) && E[i][j] != NULL;
    }

    /**
     * 边(i,j)的状态
     * @param i
     * @param j
     * @return
     */
    virtual EStatus &status(int i, int j) {
        return E[i][j]->status;
    }

    /**
     * 边(i,j)的数据
     * @param i
     * @param j
     * @return
     */
    virtual Te &edge(int i, int j) {
        return E[i][j]->data;
    }

    /**
     * 边(i,j)的权重
     * @param i
     * @param j
     * @return
     */
    virtual int &weight(int i, int j) {
        return E[i][j]->weight;
    }

    /**
     * 插入权重为w的边e=(i,j)
     * @param edge
     * @param w
     * @param i
     * @param j
     */
    virtual void insert(Te const &edge, int w, int i, int j) {
        if (Graph<Tv, Te>::exists(i, j)) {/*确保该边尚不存在*/
            return;
        }
        E[i][j] = new Edge<Te>(edge, w);/*创建新边*/
        Graph<Tv, Te>::e++;/*更新边计数与关联顶点的度数*/
        V[i].outDegree++;
        V[j].inDegree++;
    }

    /**
     * 删除顶点i和j之间的联边（exists（i，j））
     * @param i
     * @param j
     * @return
     */
    virtual Te remove(int i, int j) {
        Te eBak = edge(i, j);/*备份后删除边记录*/
        delete E[i][j];
        E[i][j] = NULL;
        Graph<Tv, Te>::e--;/*更新边计数与关联顶点的度数*/
        V[i].outDegree--;
        V[j].inDegree--;
        return eBak;/*返回被删除边的信息*/
    }
};

template<typename Tv, typename Te>
struct DijkstraPU {/*针对Dijkstra算法的顶点优先级更新器*/
    virtual void operator()(Graph<Tv, Te> *g, int uk, int v) {
        if (g->status(v) == UNDISCOVERED) {/*对于啊每一个尚未发现的邻接顶点*/
            if (g->priority(v) > g->priority(uk) + g->weight(uk, v)) {/*按Dijkstra策略做松弛*/
                g->priority(v) = g->priority(uk) + g->weight(uk, v);/*更新优先级*/
                g->parent(v) = uk;/*更新父节点*/
            }
        }
    }
};

#endif //GRAPH_GRAPH_H
