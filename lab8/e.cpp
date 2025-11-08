#include <iostream>

using namespace std;

#define ull long long

const ull P = 2;
const int MAX_N = 55;
const ull Q = 1e18;

ull pPowers[MAX_N];

void computePowersP(int n){
    pPowers[0] = 1;
    for(int i = 1; i <= n; i++){
        pPowers[i] = pPowers[i - 1] * P;
    }
}

string restore(ull v[], int n){
    string s = "";
    s += char('a' + v[0]); // first symbol
    for(int i = 1; i < n; i++){
        ull diff = v[i] - v[i - 1];
        ull value = diff / pPowers[i];
        s += char('a' + value);
    }

    return s;
}

int main(){
    int n;
    cin >> n;
    ull v[n];
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    computePowersP(n);
    cout << restore(v, n);

    return 0;
}