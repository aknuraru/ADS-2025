#include <iostream>

using namespace std;

const int MAX = 100005;

bool visited[MAX];
int prevs[MAX];

struct Queue{
    pair<int, int> q[MAX];
    int ql;
    int qr;

    Queue(){
        ql = 0;
        qr = 0;
    }

    void push(int value, int previous){
        q[qr++] = make_pair(value, previous);
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

void bfs(int a, int b){
    for(int i = 0; i < MAX; i++){
        visited[i] = false;
    }

    Queue q;
    q.push(a, -1);
    visited[a] = true;
    prevs[a] = -1;

    while(!q.isEmpty()){
        pair<int, int> current = q.front();
        q.pop();
        int val = current.first;

        if(val == b){
            break;
        }

        int new_val = val * 2;
        if(new_val < MAX && visited[new_val] == false){
            visited[new_val] = true;
            prevs[new_val] = val;
            q.push(new_val, val);
        }

        new_val = val - 1;
        if(new_val > 0 && visited[new_val] == false){
            visited[new_val] = true;
            prevs[new_val] = val;
            q.push(new_val, val);
        }
    }
}

void printPath(int a, int b){
    int path[MAX];
    int index = 0;
    int x = b;
    while (x != -1)
    {   
        path[index++] = x;
        x = prevs[x];
    }

    cout << index - 1 << endl;
    for(int i = index - 2; i >= 0; i--){
        cout << path[i] << " ";
    }
}

int main(){
    int a, b;
    cin >> a >> b;
    bfs(a, b);
    printPath(a, b);
    return 0;
}