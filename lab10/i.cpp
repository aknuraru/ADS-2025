#include <iostream>
using namespace std;

const int MAXN = 100000; 
const int MAXM = 200000; 

struct Graph {
    int n, m;                
    int head[MAXN];            
    int to[MAXM];              
    int next[MAXM];            
    int edgeCount;            

    void init(int nodes) {
        n = nodes;
        edgeCount = 0;
        for(int i = 0; i < n; i++) head[i] = -1;
    }

    void addEdge(int u, int v) {
        to[edgeCount] = v;
        next[edgeCount] = head[u];
        head[u] = edgeCount++;
    }
};

int states[MAXN];
int topSortV[MAXN];
bool used[MAXN];
int topIndex = 0;

bool detectCycle(Graph &g, int v) {
    states[v] = 1;
    for(int i = g.head[v]; i != -1; i = g.next[i]) {
        int to = g.to[i];
        if(states[to] == 0) {
            if(detectCycle(g, to)) return true;
        } else if(states[to] == 1) {
            return true;
        }
    }
    states[v] = 2;
    return false;
}

void topsort(Graph &g, int v) {
    used[v] = true;
    for(int i = g.head[v]; i != -1; i = g.next[i]) {
        int to = g.to[i];
        if(!used[to]) topsort(g, to);
    }
    topSortV[topIndex++] = v;
}

int main() {
    Graph g;
    int n, m;
    cin >> n >> m;
    g.init(n);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.addEdge(a, b);
    }

    bool hasCycle = false;
    for(int i = 0; i < n; i++) {
        if(states[i] == 0 && detectCycle(g, i)) {
            hasCycle = true;
            break;
        }
    }

    if(!hasCycle) {
        cout << "Possible" << endl;
        for(int i = 0; i < n; i++) {
            if(!used[i]) topsort(g, i);
        }
        for(int i = topIndex - 1; i >= 0; i--) {
            cout << topSortV[i] + 1 << " ";
        }
    } else {
        cout << "Impossible";
    }

    return 0;
}