#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isbalanced(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(!st.empty() && s[i]==st.top()){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    return st.empty();

}
int main(){
    string s;
    cin>>s;
    if(isbalanced(s)){
        cout<<"YES";

    }
    else{
        cout<<"NO";
    }
    return 0;
}