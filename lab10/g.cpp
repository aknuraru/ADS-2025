#include <iostream>
using namespace std;

const int MAXN = 501;

struct Graph {
    int to[MAXN * MAXN];    
    int next[MAXN * MAXN];  
    int head[MAXN];         
    int edgeCount;

    Graph() {
        for (int i = 0; i < MAXN; i++) head[i] = -1;
        edgeCount = 0;
    }

    void addEdge(int u, int v) {
        to[edgeCount] = v;
        next[edgeCount] = head[u];
        head[u] = edgeCount;
        edgeCount++;
    }
};

int states[MAXN];
Graph g;

bool detectCycle(int v, int edge_u, int edge_v) {
    states[v] = 1;

    for (int e = g.head[v]; e != -1; e = g.next[e]) {
        int to = g.to[e];

        if (v == edge_u && to == edge_v)
            continue;

        if (states[to] == 0) {
            if (detectCycle(to, edge_u, edge_v))
                return true;
        }
        else if (states[to] == 1) {
            return true;
        }
    }

    states[v] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.addEdge(u, v);
    }


    for (int u = 0; u < n; u++) {
        for (int e = g.head[u]; e != -1; e = g.next[e]) {
            int v = g.to[e];

            for (int i = 0; i < n; i++)
                states[i] = 0;

            bool hasCycle = false;

            for (int k = 0; k < n; k++) {
                if (states[k] == 0) {
                    if (detectCycle(k, u, v)) {
                        hasCycle = true;
                        break;
                    }
                }
            }

            if (!hasCycle) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}