#include <iostream>
#include <string>
using namespace std;

static int lps[200005];

void build_lps(const string &s) {
    int n = s.size();
    lps[0] = 0;
    for(int i = 1, j = 0; i < n;) {
        if(s[i] == s[j]) {
            lps[i] = j + 1;
            i++; j++;
        } else {
            if(j > 0) 
                j = lps[j - 1];
            else { 
                lps[i] = 0; i++; 
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        long long k;
        cin >> s >> k;

        int n = s.size();
        build_lps(s);
        int overlap = lps[n-1];

        long long min_len = n + (k - 1) * (n - overlap);
        cout << min_len << endl;
    }
    return 0;
}