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
    if (ispr(n)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;

    }
    return 0;
}