#include <iostream>

using namespace std;

const int MAX_N = 1000005;
const int P = 11;
const long long Q = 1000000007;
const int MOD = 50021;
unsigned long long pPower[MAX_N];
unsigned long long prefix[MAX_N];
int covered[MAX_N] = {0};

void computePowersP(int n){
    pPower[0] = 1;
    for(int i = 1; i <= n; i++){
        pPower[i] = (pPower[i - 1] * P) % Q;
    }
}

void computePrefix(const string& s){
    prefix[0] = (s[0] - 'a' + 1);
    for(int i = 1; i < s.size(); i++){
        prefix[i] = (prefix[i - 1] + (s[i] - 'a' + 1) * pPower[i]) % Q;
    }
}

unsigned long long getSubstrringHash(int l, int r){
    unsigned long long res = prefix[r];
    if(l > 0){
        res = (res + Q - prefix[l - 1]) % Q;
    }
    return res;
}

unsigned long long getHash(const string& s){
    unsigned long long h = 0;
    for(int i = 0; i < s.size(); i++){
        h = (h + (s[i] - 'a' + 1) * pPower[i]) % Q;
    }
    return h;
}

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    computePowersP(s.length());
    computePrefix(s);
    while(n--){
        string sub;
        cin >> sub;
        int m = sub.size();

        unsigned long long hash_sub = getHash(sub);
        for(int i = 0; i + m <= s.size(); i++){
            unsigned long long current_hash = getSubstrringHash(i, i + m - 1);
            if(current_hash == (hash_sub * pPower[i]) % Q){
                for(int j = i; j < i + m; j++){
                    covered[j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < s.size(); i++){
        if(covered[i] == 0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}