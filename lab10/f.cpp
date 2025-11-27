#include <iostream>

using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

struct Queue{
    pair<int, int> q[MAXN];
    int ql;
    int qr;

    Queue(){
        ql = 0;
        qr = 0;
    }

    void push(int node, int distance){
        q[qr++] = make_pair(node, distance);
    }

    pair<int, int> front(){
        return q[ql];
    }

    void pop(){
        ql++;
    }

    bool isEmpty(){
        return ql == qr;
    }
};

struct Graph{
    // adj[][]
    int head[MAXN]; // қабырғаны бірінші қыламыз
    int to[MAXM]; // қабырға қай төбеге барады
    int nxt[MAXM]; // алдыңғымен байланыстырамыз
    int edgeCounter;

    bool visited[MAXN];

    Graph(){
        edgeCounter = 0;
        for(int i = 0; i < MAXN; i++){
            visited[i] = false;
            head[i] = 0;
        }
    }

    void addEdge(int u, int v){
        to[++edgeCounter] = v;
        nxt[edgeCounter] = head[u];
        head[u] = edgeCounter;
    }

    bool bfs(int from, int to){
        Queue q;
        q.push(from, 0);
        visited[from] = true;

        while(!q.isEmpty()){
            pair<int, int> current = q.front();
            q.pop();
            int current_node = current.first;
            int current_dist = current.second;

            if(current_node == to){
                return true;
            }

            for(int i = head[current_node]; i != 0; i = nxt[i]){
                int u = this->to[i];
                if(visited[u] == false){
                    q.push(u, current_dist + 1);
                    visited[u] = true;
                }
            }
        }

        return false;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    Graph g;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
        g.addEdge(v, u);
    }

    int from, to;
    cin >> from >> to;

    if(g.bfs(from, to)){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}