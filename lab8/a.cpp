#include <iostream>
#include <string>

using namespace std;

const int SIZE = 50021; // size of table prime number
const long long QUOTIENT = 1000000007;
const int PRODUCT = 11;

void copyString(char* a, const char* b){
    int i = 0;
    while (b[i] != '\0')
    {
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';
}

bool isEqualStrings(const char* a, const char* b){
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if(a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

struct Node{
    char key[105];
    Node* next;

    Node(){
        key[0] = '\0'; // end of str
        next = nullptr;
    }

    Node(const char* s){
        copyString(key, s);
        next = nullptr;
    }
};

struct Hashtable{
    Node* table[SIZE];

    Hashtable(){
        for(int i = 0; i < SIZE; i++){
            table[i] = nullptr;
        }
    }

    int getIndex(const char s[]){
        long long h = 0, power_PRODUCT = 1;
        for(int i = 0; s[i]; i++){
            long long current = (s[i] - 47) * power_PRODUCT % QUOTIENT;
            h = (h + current) % QUOTIENT;
            power_PRODUCT = (power_PRODUCT * PRODUCT) % QUOTIENT;
        }
        return (int)(h % SIZE); // to stand in this range
    }
    
    void insert(const char s[]){
        int hash_index = getIndex(s);
        if(!isExist(s)){
            Node* node = new Node(s);
            node->next = table[hash_index];
            table[hash_index] = node;
        }
    }

    bool isExist(const char s[]){
        int hash_index = getIndex(s);
        Node* current = table[hash_index];
        while (current)
        {
            if(isEqualStrings(current->key, s)){
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main(){
    int n;
    cin >> n;
    int total = 2 * n;

    static char strings[20050][105];
    Hashtable ht;
    for(int i = 0; i < total; i++){
        cin >> strings[i];
        ht.insert(strings[i]);
    }

    int counter = 0;
    for(int i = 0; i < total; i++){
        if(counter == n){
            break;
        }

        long long h = 0, power_PRODUCT = 1;
        for(int j = 0; strings[i][j]; j++){
            long long current = (strings[i][j] - 47) * power_PRODUCT % QUOTIENT;
            h = (h + current) % QUOTIENT;
            power_PRODUCT = (power_PRODUCT * PRODUCT) % QUOTIENT;
        }

        // hash to str
        /*
        char hashStr[50];
        int len = 0;
        long long temp = h;
        if(temp == 0) hashStr[len++] = '0';
        while (temp > 0)
        {
            hashStr[len++] = (temp % 10) + '0';
            temp /= 10;
        }
        hashStr[len] = '\0';
        for(int l = 0, r = len - 1; l < r; l++, r--){
            char c = hashStr[l];
            hashStr[l] = hashStr[r];
            hashStr[r] = c;
        }
        */
        string hashStr = to_string(h);
        if(ht.isExist(hashStr.c_str())){
            cout << "Hash of string \"" << strings[i] << "\" is " << hashStr << endl;
            counter++;
        }
    }

    return 0;
}