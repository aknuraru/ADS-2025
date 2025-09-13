#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int num){
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
    if(n<=0){
        cout<<"Try again"<<endl;
        return 1;
    }
    int counter=0;
    int currentpr=2;
    while(counter<n){
        if(isprime(currentpr)){
            counter++;
            if(counter==n){
                cout<<currentpr<<endl;
                break;
            }
        }
        currentpr++;
    }
    return 0;
}