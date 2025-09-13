#include <iostream>
#include <string>
using namespace std;
int main(){
    string s,t,eq1,eq2;
    cin>>s>>t;
    for (int i=0;i<s.size();i++){
        if(s[i]=='#'){
            eq1.pop_back();
        }
        else{
            eq1+=s[i];
        }
    }
    for (int i=0;i<t.size();i++){
        if(t[i]=='#'){
            eq2.pop_back();
        }
        else{
            eq2+=t[i];
        }
    }
    if(eq1==eq2){
        cout<<"Yes"<<endl;

    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}