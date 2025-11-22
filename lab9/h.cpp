#include <iostream>

using namespace std;

int main(){
    string p;
    getline(cin, p);

    int n = p.size();
    long long counter = 0;
    int* lps = new int[n];
    lps[0] = 0;

    for(int i = 1, j = 0; i < n;){
        if(p[i] == p[j]){
            lps[i] = j + 1;
            i++;
            j++;
        }else{
            if(j > 0){
                j = lps[j - 1];
            }else{
                i++;
            }
        }
    }

    for(int i = 1; i < n; i++){
        int k = i - lps[i - 1];
        if(k > 0 && (i % 2 == 0) && (i / k) % 2 == 0){
            counter++;
        }
    }
    cout << counter;
    delete[] lps;
    return 0;
}