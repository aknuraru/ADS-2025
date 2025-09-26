#include <iostream>
using namespace std;
int partition(int* arr,int low,int hight){//return index og pivot
    int pivot=arr[hight];
    int orange=low-1;
    for(int green=low;green<hight;green++){
        if(arr[green]<=pivot){
            orange++;
            swap(arr[orange],arr[green]);
        }
    }
    int index_of_pivot=orange+1;
    swap(arr[index_of_pivot],arr[hight]);
    return index_of_pivot;
}
void quicksort(int* arr,int low,int hight){
    if(low<hight){
        int pivot=partition(arr,low,hight);
        quicksort(arr,low,pivot-1);//left arr
        quicksort(arr,pivot+1,hight);//right arr
    }
}
int main(){
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    int rounds;
    cin>>rounds;
    while(rounds--){
        int power;
        cin>>power;
        int left=0,right=n-1,pos=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(arr[mid]<=power){
                pos=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        int canwin=pos+1;
        int sum=0;
        for(int i=0;i<canwin;i++){
            sum+=arr[i];
        }
        cout<<canwin<<" "<<sum<<endl;
    }
    return 0;
}