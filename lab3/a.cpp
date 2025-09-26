#include <iostream>
using namespace std;
int binarySearchIncreasing(int arr[], int left, int right, int target){
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            return mid;
        if(arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int binarySearchDecreasing(int arr[], int left, int right, int target){
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            return mid;
        if(arr[mid] < target)
            right = mid - 1; 
        else
            left = mid + 1;
    }
    return -1;
}

int main(){
    int k;
    cin >> k;
    int queries[k];
    for(int i = 0; i < k; i++)
        cin >> queries[i];

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int q = 0; q < k; q++){
        int target = queries[q];
        bool isFound = false;

        for(int i = 0; i < n; i++){
            int index;
            if(i % 2 == 1){
                index = binarySearchIncreasing(a[i], 0, m - 1, target);
            }else {
                index = binarySearchDecreasing(a[i], 0, m - 1, target);
            }
            if(index != -1){
                cout << i << " " << index << endl;
                isFound = true;
                break;
            }
        }

        if(!isFound)
            cout << -1 << endl;
    }

    return 0;
}