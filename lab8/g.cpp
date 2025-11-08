#include <iostream>

using namespace std;

#define ull unsigned long long

const int P1 = 31;
const int P2 = 37;
const int MAX_N = 1000005;
const ull Q1 = 1e9 + 7;
const ull Q2 = 1000000009;

ull pPowers1[MAX_N];
ull pPowers2[MAX_N];
ull prefix1[MAX_N];
ull prefix2[MAX_N];

void computePowersP(int n){
    pPowers1[0] = 1;
    pPowers2[0] = 1;
    for(int i = 1; i < n; i++){
        pPowers1[i] = (pPowers1[i - 1] * P1) % Q1;
        pPowers2[i] = (pPowers2[i - 1] * P2) % Q2;
    }
}

void computePrefix(string s){
    prefix1[0] = (s[0] - 'a' + 1) % Q1;
    prefix2[0] = (s[0] - 'a' + 1) % Q2;
    for(int i = 1; i < s.size(); i++){
        prefix1[i] = (prefix1[i - 1] +(ull)( (s[i] - 'a' + 1) * pPowers1[i]) % Q1 ) % Q1;
        prefix2[i] = (prefix2[i - 1] +(ull)( (s[i] - 'a' + 1) * pPowers2[i]) % Q2 ) % Q2;
    }
}

ull getHash1(const string& s){
    ull h = 0;
    for(int i = 0; i < s.size(); i++){
        h = ( h + (ull)((s[i] - 'a' + 1) * pPowers1[i]) ) % Q1;
    }
    return h;
}

ull getHash2(const string& s){
    ull h = 0;
    for(int i = 0; i < s.size(); i++){
        h = ( h + (ull)((s[i] - 'a' + 1) * pPowers2[i]) ) % Q2;
    }
    return h;
}

ull getSubstringHash1(int l, int r){
    ull res = prefix1[r];
    if(l > 0){
        res = (res + Q1 - prefix1[l - 1]) % Q1;
    }
    return res;
}

ull getSubstringHash2(int l, int r){
    ull res = prefix2[r];
    if(l > 0){
        res = (res + Q2 - prefix2[l - 1]) % Q2;
    }
    return res;
}

int countOccurences(const string& text, const string& sub){
    int n = text.size();
    int m = sub.size();
    ull sub_hash1 = getHash1(sub);
    ull sub_hash2 = getHash2(sub);
    int counter = 0;

    for(int i = 0; i + m <= n; i++){
        ull current_hash1 = getSubstringHash1(i, i + m - 1);
        ull current_hash2 = getSubstringHash2(i, i + m - 1);

        ull expect1 = (sub_hash1 * pPowers1[i]) % Q1;
        ull expect2 = (sub_hash2 * pPowers2[i]) % Q2;

        if(current_hash1 == expect1 && current_hash2 == expect2){
            counter++;
        }
    }
    return counter;
}

int main(){
    string s;
    cin >> s;
    int q;
    cin >> q;
    int res[q];
    computePowersP(s.length());
    computePrefix(s);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        string sub = s.substr(l, r - l + 1); // akzhol 1 1 = a
        res[i] = countOccurences(s, sub);
    }

    for(int i = 0; i < q; i++){
        cout << res[i] << endl;
    }

    return 0;
}