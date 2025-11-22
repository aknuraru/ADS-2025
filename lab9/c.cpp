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

int kmp(string &text, string &sub){
    int n = text.size();
    int m = sub.size();
    int counter = 0;
    fill_lps(sub);

    int i = 0, j = 0;
    while (i < n)
    {
        if(text[i] == sub[j]){
            i++;
            j++;
            if(j == m){
                return i - m;
            }
        }else{
            if(j > 0){
                j = lps[j - 1];
            }else{
                i++;
            }
        }
    }
    return -1;
}

int main(){
    string a, p, text;
    cin >> a >> p;
    text = a + a;
    int position = kmp(text, p);
    if(position == -1){
        cout << -1;
    }else{
        cout << p.length() - position;
    }

    return 0;
}