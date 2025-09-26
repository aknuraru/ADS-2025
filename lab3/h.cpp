#include <iostream>

using namespace std;

int binarySearch(int* arr, int n, int target){
    int left = 0, right = n - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left + 1;
}

int main(){

    int n, m;
    cin >> n >> m;

    int* arr = new int[n];
    int* p = new int[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    p[0] = arr[0];
    for(int i = 1; i < n; i++)
        p[i] = p[i - 1] + arr[i];
    
    while(m--){
        int x;
        cin >> x;
        cout << binarySearch(p, n, x) << endl;
    }

    return 0;
}