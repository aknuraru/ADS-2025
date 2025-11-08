#include <iostream>

using namespace std;

const int MOD = 50021;
const long long Q = 1000000007;
const int P = 11;
unsigned long long pPower[1000005];
unsigned long long prefix1[1000005];
unsigned long long prefix2[1000005];


struct Node{
    string key;
    Node* next;

    Node(){
        key = "";
        next = nullptr;
    }

    Node(string s){
        key = s;
        next = nullptr;
    }
};

struct HashTable{
    Node* table[MOD];

    HashTable(){
        for(int i = 0; i < MOD; i++){
            table[i] = nullptr;
        }
    }

    unsigned long long getHash(const string& s){
        long long hash = 0, P_Power = 1;
        for(char c : s){
            hash = (hash + (unsigned long long)(c) * P_Power) % Q;
            P_Power = (P_Power * P) % Q;
        }
        return hash;
    }

    int getIndex(const string& s){
        return (int)(getHash(s) % MOD);
    }

    void insert(const string& s){
        int hash_index = getIndex(s);
        if(!isExist(s)){
            Node* node = new Node(s);
            node->next = table[hash_index];
            table[hash_index] = node;
        }
    }

    bool isExist(const string& s){
        int hash_index = getIndex(s);
        Node* current = table[hash_index];
        while (current)
        {
            if(current->key == s) return true;
            current = current->next;
        }
        return false;   
    }
};

int main(){
    string s1, s2, target;
    cin >> s1 >> s2 >> target;

    int n1 = s1.size(), n2 = s2.size(), m = target.size(), counter = 0;

    HashTable ht;
    unsigned long long target_hash = ht.getHash(target);

    pPower[0] = 1;
    for(int i = 1; i <= max(n1, n2); i++){
        pPower[i] = (pPower[i - 1] * P) % Q;
    }


    prefix1[0] = (unsigned long long)(s1[0]);
    for(int i = 1; i < n1; i++){
        prefix1[i] = (prefix1[i - 1] + (unsigned long long)(s1[i]) * pPower[i]) % Q;
    }

    for(int i = 0; i + m <= n1; i++){
        unsigned long long h = prefix1[i + m - 1];
        if(i > 0){
            h = (h + Q - prefix1[i - 1]) % Q;
        }
        if(h == (target_hash * pPower[i]) % Q){
            ht.insert(to_string(i));
        }
    }

    prefix2[0] = (unsigned long long)(s2[0]);
    for(int i = 1; i < n2; i++){
        prefix2[i] = (prefix2[i - 1] + (unsigned long long)(s2[i]) * pPower[i]) % Q;
    }

    for(int i = 0; i + m <= n2; i++){
        unsigned long long h = prefix2[i + m - 1];
        if(i > 0){
            h = (h + Q - prefix2[i - 1]) % Q;
        }
        if(h == (target_hash * pPower[i]) % Q && ht.isExist(to_string(i))){
            counter++;
        }   
    }

    cout << counter;

    return 0;
}