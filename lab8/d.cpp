#include <iostream>

using namespace std;

#define ull unsigned long long

const int MAX_N = 1000005;
const int P = 31;
const long long Q = 1000000007;
unsigned long long pPower[MAX_N];
unsigned long long prefix[MAX_N];

struct Pattern{
    string sub;
    int count;
};

void computePowersP(int n){
    pPower[0] = 1;
    for(int i = 1; i <= n; i++){
        pPower[i] = (pPower[i - 1] * P) % Q;
    }
}

void computePrefix(const string& s){
    prefix[0] = (s[0] - 'a' + 1) % Q;
    for(int i = 1; i < s.size(); i++){
        prefix[i] = (prefix[i - 1] + (s[i] - 'a' + 1) * pPower[i]) % Q;
    }
}


ull getHash(const string& s){
    ull h = 0;
    for(int i = 0; i < s.size(); i++){
        h = (h + (s[i] - 'a' + 1) * pPower[i]) % Q;
    }
    return h;
}

ull getSubstringHash(int l, int r){
    ull res = prefix[r];
    if(l > 0){
        res = (res + Q - prefix[l - 1]) % Q;
    }
    return res;
}

int countOccurences(const string& text, const string& sub){
    int n = text.size();
    int m = sub.size();
    ull sub_hash = getHash(sub);
    int counter = 0;

    for(int i = 0; i + m <= n; i++){
        ull current_hash = getSubstringHash(i, i + m - 1);
        if(current_hash == (sub_hash * pPower[i]) % Q){
            counter++;
        }
    }
    return counter;
}

int main(){
    computePowersP(MAX_N - 1);
    while (true)
    {
        int n;
        cin >> n;
        if(n == 0){
            break;
        }

        Pattern patterns[151];
        for(int i = 0; i < n; i++){
            cin >> patterns[i].sub;
            patterns[i].count = 0;
        }

        string text;
        cin >> text;
        computePrefix(text);
        int maxCount = 0;
        for(int i = 0; i < n; i++){
            patterns[i].count = countOccurences(text, patterns[i].sub);
            if(patterns[i].count > maxCount){
                maxCount = patterns[i].count;
            }
        }

        cout << maxCount << endl;
        for(int i = 0; i < n; i++){
            if(patterns[i].count == maxCount){
                cout << patterns[i].sub << endl;
            }
        }
    }
    return 0;
}