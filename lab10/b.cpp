#include <iostream>

using namespace std;

const int MAX = 101;

int adj[MAX][MAX];
bool visited[MAX]; // used

struct Queue{
    pair<int, int> q[MAX * MAX];
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

int minDistance(int from, int to, int n){
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    Queue q;
    q.push(from, 0);
    visited[from] = true;
    while (!q.isEmpty())
    {
        pair<int, int> current = q.front();
        q.pop();
        int node = current.first;
        int total_distance = current.second;

        if(node == to){
            return total_distance;
        }

        for(int i = 0; i < n; i++){
            if(adj[node][i] == 1 && visited[i] == false){
                visited[i] = true;
                q.push(i, total_distance + 1);
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }

    int from, to;
    cin >> from >> to;
    from--;
    to--;
    cout << minDistance(from, to, n);
    return 0;
}