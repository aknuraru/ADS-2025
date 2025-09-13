#include <iostream>
#include <deque>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        deque<int>deq;
        int n;
        cin>>n;
        for(int i=n;i>0;i--){
            deq.push_front(i);
            int k=i;
            while(k>0){
                deq.push_front(deq.back());
                deq.pop_back();
                k--;

            }
        }
        for(int i=0;i<deq.size();i++){
            cout<<deq[i]<<' ';

        }
        cout<<endl;
    }
    return 0;
}