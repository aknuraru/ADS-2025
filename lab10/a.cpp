#include <iostream>

using namespace std;

const int MAX = 1005;

int matrix[MAX][MAX];
pair<int, int> marios[MAX * MAX];
int marioCount;

pair<int, int> q[MAX * MAX];
int ql, qr;

int n, m;
int mushrooms;

int direction_x[4] = {-1, 1, 0, 0};
int direction_y[4] = {0, 0, -1, 1};

bool inside(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

void readInput(){
    cin >> n >> m;
    mushrooms = 0;
    marioCount = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 2){
                marios[marioCount++] = make_pair(i, j);
            }
            if(matrix[i][j] == 1){
                mushrooms++;
            }
        }
    }
}

void initQueue(){
    ql = 0;
    qr = 0;
    for(int i = 0; i < marioCount; i++){
        q[qr++] = marios[i];
    }
}

void crushLayer(){
    int layerSize = qr - ql;
    for(int s = 0; s < layerSize; s++){
        pair<int, int> current = q[ql++];
        int x = current.first;
        int y = current.second;

        for(int d = 0; d < 4; d++){
            int new_x = x + direction_x[d];
            int new_y = y + direction_y[d];

            if(!inside(new_x, new_y)){
                continue;
            }

            if(matrix[new_x][new_y] == 1){
                matrix[new_x][new_y] = 2;
                mushrooms--;
                q[qr++] = make_pair(new_x, new_y);
            }
        }
    }
}

int bfs(){
    if(mushrooms == 0){
        return 0;
    }

    int minutes = 0;

    while (ql < qr)
    {
        if(mushrooms == 0){
            break;
        }

        crushLayer();
        minutes++;
    }
    
    if(mushrooms != 0){
        return -1;
    }else{
        return minutes;
    }
}

int main(){
    readInput();
    initQueue();
    cout << bfs();

    return 0;
}