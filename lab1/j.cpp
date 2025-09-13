#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main(){
    char c;
    int n;
    deque<int>deq;
    vector<int>v;
    while(cin>>c){
        if(c=='!'){
            break;
        }
        else if(c=='+'){
            cin>>n;
            deq.push_front(n);
        }
        else if(c=='-'){
            cin>>n;
            deq.push_back(n);
        }
        else if(c=='*'){
            if(deq.size()>1){
                v.push_back(deq.front()+deq.back());
                deq.pop_front();
                deq.pop_back();
            }
            else if(deq.size()==1){
                v.push_back(deq.front()+deq.front());
                deq.pop_front();
            }
            else if(deq.size()==0){
                v.push_back(12345);
            }
        }
    }
    for(int i=0;i<v.size();i++){
        if (v[i]==12345){
            cout<<"error"<<endl;
        }
        else{
            cout<<v[i]<<endl;
        }
    }
    return 0;
}