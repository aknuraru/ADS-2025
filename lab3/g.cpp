#include <iostream>

using namespace std;


bool check(int* arr, int n, long k, int capacity_of_bag){
    long count_round = 0;
    for(int i = 0; i < n; i++){
        count_round += (arr[i] + capacity_of_bag - 1) / capacity_of_bag;
    }

    return count_round <= k;
}

int binarySearch(int* arr, int n, int maxValue, int k){
    int left = 1, right = maxValue;
    int result = maxValue;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(check(arr, n, k, mid)){
            result = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return result;
}

int main(){
    int n, maxValue = 0;
    long k;
    cin >> n >> k;
    int* arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }
    
    cout << binarySearch(arr, n, maxValue, k);
    delete[] arr;
    return 0;
}