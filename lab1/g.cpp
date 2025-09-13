#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool ispr(int num){
    if(num<=1) return false;
    for (int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int>priime;
    vector<int>superprime;
    priime.push_back(0);
    for(int i=2;i<100000;i++){
        if (ispr(i)){
            priime.push_back(i);
        }
    }
    for(int i=2;i<priime.size();i++){
        if (ispr(i)){
            superprime.push_back(priime[i]);
        }
    }
    cout<<superprime[n-1]<<endl;
    return 0;
}