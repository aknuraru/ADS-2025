#include <iostream>

using namespace std;

const int MAXN = 200005;
const int MAXM = 400005;

struct Queue{
    pair<int, int> q[MAXN];
    int ql;
    int qr;

    Queue(){
        ql = 0;
        qr = 0;
    }

    void push(int vertex, int distance){
        q[qr++] = make_pair(vertex, distance);
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
    bool color[MAXN];
    // adj[][]
    int head[MAXN]; // қабырғаны бірінші қыламыз
    int to[MAXM]; // қабырға қай төбеге барады
    int nxt[MAXM]; // алдыңғымен байланыстырамыз
    int edgeCounter;
    bool visited[MAXN];

    Graph(){
        for(int i = 0; i < MAXN; i++){
            head[i] = 0;
        }
    }

    void addEdge(int u, int v){
        to[++edgeCounter] = v; // [ 0, 0, 1, 1, 0, 1]
        nxt[edgeCounter] = head[u];
        head[u] = edgeCounter;
    }

    void changeToRed(int vertex){
        color[vertex] = true;
    }

    int bfs(int start){ // nearest Red Vertex
        for(int i = 0; i < MAXN; i++){
            visited[i] = false;
        }

        if(color[start] == true){
            return 0;
        }
        
        Queue q;
        q.push(start, 0);
        visited[start] = true;

        while(!q.isEmpty()){
            pair<int, int> current = q.front();
            q.pop();
            int current_node = current.first;
            int current_dist = current.second;

            for(int i  = head[current_node]; i != 0; i = nxt[i]){
                int u = to[i];
                if(visited[u] == false){
                    visited[u] = true;
                    if(color[u] == true){
                        return current_dist + 1;
                    }
                    q.push(u, current_dist + 1);
                    }
                }
            }

        return -1;
    }
};

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    
    Graph g;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g.addEdge(a, b);
        g.addEdge(b, a);
    }

    while(q--){
        int command, vertex;
        cin >> command >> vertex;
        vertex--;
        if(command == 1){
            g.changeToRed(vertex);
        }else if(command == 2){
            cout << g.bfs(vertex) << endl;
        }
    }
    
    return 0;
}