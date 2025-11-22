#include <iostream>

using namespace std;

static int lps[200005];
static int positions[200005];

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
    string res = "";
    fill_lps(sub);
    int i = 0, j = 0, counter = 0;
    while (i < n)
    {
        if(text[i] == sub[j]){
            i++;
            j++;
            if(j == m){
                positions[counter] = i - m + 1;
                counter++;
            }
        }else{
            if(j > 0){
                j = lps[j - 1];
            }else{
                i++;
            }
        }
    }
    return counter;
}

int main(){
    string text, p;
    cin >> text >> p;
    int counter = kmp(text, p);
    cout << counter << endl;
    for(int i = 0; i < counter; i++){
        cout << positions[i] << " ";
    }

    return 0;
}