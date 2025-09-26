#include <iostream>

using namespace std;

bool binarySearch(int* arr, int n, int target){
    int left = 0, right = n - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if(target < arr[mid])
            right = mid - 1;
        else if(target > arr[mid])
            left = mid + 1;
        else{
            return true;
        }
    }
    return false;
}

int main(){
    int n, target;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cin >> target;
    if(binarySearch(arr, n, target))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}