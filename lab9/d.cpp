#include <iostream>
#include <string>
using namespace std;

static int lps[200005];

void build_lps(const string &p, int m) {
    lps[0] = 0;
    for (int i = 1, j = 0; i < m;) {
        if (p[i] == p[j]) {
            lps[i] = j + 1;
            i++; j++;
        } else {
            if (j > 0) j = lps[j - 1];
            else { lps[i] = 0; i++; }
        }
    }
}

int max_overlap(const string &target, const string &city) {
    int n = target.size();
    int m = city.size();
    int j = 0;

    build_lps(city, m);


    int start = n - m > 0 ? n - m : 0;
    for (int i = start; i < n; i++) {
        while (j > 0 && target[i] != city[j]) j = lps[j - 1];
        if (target[i] == city[j]) j++;
    }
    return j;
}

int main() {
    string target;
    cin >> target;

    int n;
    cin >> n;
    string cities[1005];
    int matches[1005];
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        cin >> cities[i];
        matches[i] = max_overlap(target, cities[i]);
        if (matches[i] > max_len) max_len = matches[i];
    }

    int counter = 0;
    for (int i = 0; i < n; i++) if (matches[i] == max_len) counter++;

    cout << counter << "\n";
    for (int i = 0; i < n; i++) if (matches[i] == max_len) cout << cities[i] << "\n";

    return 0;
}