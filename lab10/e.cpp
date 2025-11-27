#include <iostream>

using namespace std;

const int MAX = 1005;

int adj[MAX][MAX];


bool isAdditable(int x, int y, int z){
    x--; y--; z--;
    if(adj[x][y] && adj[x][z] && adj[y][z]){
        return true;
    }
    return false;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }

    while(q--){
        int x, y, z;
        cin >> x >> y >> z;
        if(isAdditable(x, y, z)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }


    return 0;
}