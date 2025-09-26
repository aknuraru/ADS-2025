#include <iostream>
using namespace std;
int main(){
    long n,k;
    cin>>n>>k;
    long *arr=new long[n];
    for(long i=0;i<n;i++){
        cin>>arr[i];
    }
    long l=0;
    long r=1e18; //l is lowest sum
    while(l<=r){
        long mid=l+(r-l)/2; //check in block if max sum is equal to mid;
        long counter_blocks=1;
        long sum=0;
        for(int i=0;i<n;i++){
            if(mid<sum+arr[i]){
                counter_blocks++;
                sum=0;
            }
            if(mid<arr[i]){
                counter_blocks=k+1;//other block
            }
            sum+=arr[i];
        }
        if(k<counter_blocks){
                l=mid+1;
            }
        else{
            r=mid-1;
        }
    }
    cout<<l;
    return 0;

}