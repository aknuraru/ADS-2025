#include <iostream>
using namespace std;

struct DFS {
    static const int N = 101;
    char a[N][N];
    int n, m;

    void run(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (a[i][j] == '0' || a[i][j] == '#') return;

        a[i][j] = '#';
        run(i + 1, j);
        run(i - 1, j);
        run(i, j + 1);
        run(i, j - 1);
    }
};

int main() {
    DFS d;

    cin >> d.n >> d.m;
    for (int i = 0; i < d.n; i++)
        for (int j = 0; j < d.m; j++)
            cin >> d.a[i][j];

    int cnt = 0;
    for (int i = 0; i < d.n; i++) {
        for (int j = 0; j < d.m; j++) {
            if (d.a[i][j] == '1') {
                cnt++;
                d.run(i, j);
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}