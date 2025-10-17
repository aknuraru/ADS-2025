#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> letters(n);

    for (int i = 0; i < n; i++) {
        cin >> letters[i];
    }

    char target;
    cin >> target;

    
    for (char c : letters) {
        if (c > target) {
            cout << c;
            return 0;
        }
    }

   
    cout << letters[0];
    return 0;
}