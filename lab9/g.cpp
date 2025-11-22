#include <iostream>

using namespace std;

static int lps[200005];

void fill_lps(string &p){
    int n = p.size();
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
}

int main(){
    string s;
    cin >> s;
    fill_lps(s);
    int n = s.length();

    int res = n - lps[n - 1];
    cout << res;

    return 0;
}