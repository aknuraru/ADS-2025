#include <iostream>

using namespace std;

#define ull unsigned long long

const ull Q1 = 1e9 + 7;
const ull Q2 = 1e9 + 9;
const int P1 = 47;
const int P2 = 53;

const long SIZE = 500003;
const int MAX_N = 2005;

ull pPowers1[MAX_N];
ull pPowers2[MAX_N];
ull prefix1[MAX_N];
ull prefix2[MAX_N];

void computePowersP(int n){
    pPowers1[0] = 1;
    pPowers2[0] = 1;
    for(int i = 1; i <= n; i++){
        pPowers1[i] = (pPowers1[i - 1] * P1) % Q1;
        pPowers2[i] = (pPowers2[i - 1] * P2) % Q2;
    }
}

void computePrefix(const string& s){
    prefix1[0] = (s[0] - 'a' + 1);
    prefix2[0] = (s[0] - 'a' + 1);
    for(int i = 1; i < s.size(); i++){
        prefix1[i] = (prefix1[i - 1] + (ull)((s[i] - 'a' + 1) * pPowers1[i]) % Q1) % Q1;
        prefix2[i] = (prefix2[i - 1] + (ull)((s[i] - 'a' + 1) * pPowers2[i]) % Q2) % Q2;
    }
}

unsigned long long getSubstrringHash1(int l, int r, int n){
    unsigned long long res = prefix1[r];
    if(l > 0){
        res = (res + Q1 - prefix1[l - 1]) % Q1;
    }
    res = (res * pPowers1[n - r - 1]) % Q1;
    return res;
}

unsigned long long getSubstrringHash2(int l, int r, int n){
    unsigned long long res = prefix2[r];
    if(l > 0){
        res = (res + Q2 - prefix2[l - 1]) % Q2;
    }
    res = (res * pPowers2[n - r - 1]) % Q2;
    return res;
}

struct DoubleHash{
    ull h1;
    ull h2;

    DoubleHash(){
        h1 = 0;
        h2 = 0;
    }

    DoubleHash(ull a, ull b){
        h1 = a;
        h2 = b;
    }

    bool operator==(const DoubleHash& other) const{
        return h1 == other.h1 && h2 == other.h2;
    }
};

struct Node{
    DoubleHash key;
    Node* next;

    Node(){
        next = nullptr;
    }

    Node(DoubleHash k){
        key = k;
        next = nullptr;
    }
};

struct HashTable{
    Node* table[SIZE];
    int elements;

    HashTable(){
        elements = 0;
        for(int i = 0; i < SIZE; i++){
            table[i] = nullptr;
        }
    }

    ull getIndex(DoubleHash& h){
        return (h.h1 * 31 + h.h2) % SIZE;
    }

    void insert(DoubleHash& h) {
        if(!isExist(h)){
            int hash_index = getIndex(h);
            Node* node = new Node(h);
            node->next = table[hash_index];
            table[hash_index] = node;
            elements++;
        }
    }

    bool isExist(DoubleHash& h){
        int hash_index = getIndex(h);
        Node* current = table[hash_index];
        while (current)
        {
            if(current->key == h){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int getElements(){
        return elements;
    }
};

int main(){
    string s;
    cin >> s;
    int n = s.size();
    computePowersP(n);
    computePrefix(s);

    HashTable ht;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){ // O(n^2)
            ull current_hash1 = getSubstrringHash1(i, j, n);
            ull current_hash2 = getSubstrringHash2(i, j, n);
            DoubleHash dh(current_hash1, current_hash2);
            ht.insert(dh);
        }
    }

    cout << ht.getElements();

    return 0;
}