#include <iostream>
#include <vector>
using namespace std;
vector<int>getpref(string s){
    int n=s.size();
    vector<int>p(n);
    p[0]=0;
    for(int i=1;i<n;i++){
        int j=p[i-1];
        while(j>0 && s[i]!=s[j]){
            j=p[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        p[i]=j;
    }
    return p;
}
bool findin(string a,string b){
    string combined=b+"#"+a;
    vector<int>p=getpref(combined);
    for(int i=0;i<combined.size();i++){
        if(p[i]==b.size()){
            return true;
        }
    }
    return false;
}
int main(){
    string a,b;
    cin>>a>>b;
    string repeated=a;
    int count=1;
    while(repeated.size()<b.size()){
        count++;
        repeated+=a;
    }
    if(findin(repeated,b)){
        cout<<count<<endl;
        return 0;
    }
    count++;
    repeated+=a;
    if(findin(repeated,b)){
        cout<<count<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}