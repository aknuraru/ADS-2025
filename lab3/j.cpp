#include <iostream>

using namespace std;

bool check(int* arr, int n, int mid, int k){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += (arr[i] + mid - 1) / mid;
    }
    return sum <= k;
}

int binarySearch(int* arr, int n, int maxValue, int k){
    int left = 1, right = maxValue;
    int result = 0;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(check(arr, n, mid, k)){
            result = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return result;
}

int main(){
    int n, k, maxValue = 0;
    cin >> n >> k;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > maxValue)
            maxValue = arr[i];
    }
    cout << binarySearch(arr, n, maxValue, k) ;
    

    return 0;
}