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
int getmax(int a,int b){
    if(a>b)
        return a;
    return b;
}
int main(){
    int n,k;
    cin>>n>>k;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;//(x1,y1) left bottom;(x2,y2) right top
        arr[i]=getmax(x2,y2);
    }
    quicksort(arr,0,n-1);
    cout<<arr[k-1]<<endl;
    return 0;
}