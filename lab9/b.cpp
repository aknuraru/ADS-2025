#include <iostream>
#include <vector>
using namespace std;
vector<int> get_pref(string s){
    int n=s.size();
    vector<int>p(n);
    p[0]=0;
    for(int i=1;i<n;i++){
        int j=p[i-1];
        while(j>0 && s[j]!=s[i]){
            j=p[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        p[i]=j;
    }
    return p;
}
int main(){
    string s,t;
    int n;
    cin>>t>>n>>s;
    string s1=t+"#"+s;
    vector<int>p=get_pref(s1);
    int count=0;
    for(int i=0;i<s1.size();i++){
        if(p[i]==t.size()){
            count++;
        }
    }
    if(count>=n){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}