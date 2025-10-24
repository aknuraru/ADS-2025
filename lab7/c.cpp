#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right){
    int result[1000];
    int i = left;
    int j  = mid + 1;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if(arr[i] <= arr[j]){
            result[k] = arr[i];
            k++;
            i++;
        }else{
            result[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        result[k] = arr[i];
        k++;
        i++;
    }
    
    while (j <= right)
    {
        result[k] = arr[j];
        k++;
        j++;
    }

    for(int p = 0; p < k; p++){
        arr[left + p] = result[p];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left >= right){
        return;
    }

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void getSolution(int arr1[], int n, int arr2[], int m){
    int i = 0, j = 0;
    while(i < n && j < m){
        if(arr1[i] == arr2[j]){
            cout << arr1[i] << " ";
            i++;
            j++;
        }else if(arr1[i] < arr2[j]){
            i++;
        }else{
            j++;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
    
    for(int i = 0; i < m; i++)
        cin >> arr2[i];
    

    mergeSort(arr1, 0, n - 1);
    mergeSort(arr2, 0, m - 1);

    getSolution(arr1, n, arr2, m);

    return 0;
}