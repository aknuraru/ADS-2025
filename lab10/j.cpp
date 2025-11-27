#include <iostream>
using namespace std;

#define MAXN 100000
#define MAXM 200000

struct Edge {
    int to, next;
};

struct Queue{
    int q[MAXN];
    int ql;
    int qr;

    Queue(){
        ql = 0;
        qr = 0;
    }
    void init() { 
        ql = 0;
        qr = 0;
    }

    void push(int node){
        q[qr++] = node;
    }

    int front(){
        return q[ql];
    }

    int pop() { 
        return q[ql++]; 
    }

    bool isEmpty(){
        return ql == qr;
    }
};

struct Graph {
    Edge edges[MAXM+1];
    int head[MAXN+1];
    int edgeCnt;

    int visited[MAXN+1];
    int compVisited[MAXN+1];
    int parentArr[MAXN+1];
    int childCount[MAXN+1];

    int comp[MAXN];

    Queue q;

    void init(int n) {
        for (int i = 1; i <= n; i++) head[i] = 0;
        edgeCnt = 0;
    }

    void addEdge(int u, int v) {
        edges[++edgeCnt].to = v;
        edges[edgeCnt].next = head[u];
        head[u] = edgeCnt;
    }

    void bfsComponent(int start, int &root, int &compSize) {
        q.init();
        q.push(start);
        visited[start] = 1;

        root = start;
        compSize = 0;
        comp[compSize++] = start;

        while (!q.isEmpty()) {
            int v = q.pop();
            if (v < root) root = v;

            for (int e = head[v]; e; e = edges[e].next) {
                int u = edges[e].to;
                if (!visited[u]) {
                    visited[u] = 1;
                    q.push(u);
                    comp[compSize++] = u;
                    if (u < root) root = u;
                }
            }
        }
    }

    void bfsTree(int root) {
        for (int i = 0; i < MAXN; i++) {
            compVisited[i] = 0;
            childCount[i] = 0;
            parentArr[i] = -1;
        }

        q.init();
        q.push(root);
        compVisited[root] = 1;

        while (!q.isEmpty()) {
            int v = q.pop();
            for (int e = head[v]; e; e = edges[e].next) {
                int u = edges[e].to;
                if (!compVisited[u]) {
                    compVisited[u] = 1;
                    parentArr[u] = v;
                    childCount[v]++;
                    q.push(u);
                }
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g;
    g.init(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
        g.addEdge(y, x);
    }

    int bigFam = 0;

    for (int i = 1; i <= n; i++) g.visited[i] = 0;

    for (int start = 1; start <= n; start++) {
        if (!g.visited[start]) {
            int root, compSize;
            g.bfsComponent(start, root, compSize);
            g.bfsTree(root);

            for (int i = 0; i < compSize; i++) {
                int v = g.comp[i];
                if (v == root) bigFam++;
                else if (g.childCount[v] > g.childCount[g.parentArr[v]]) bigFam++;
            }
        }
    }

    cout << bigFam;
    return 0;
}