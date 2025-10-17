#include <iostream>

using namespace std;

void my_swap(int& a, int& b){
        int t = a;
        a = b;
        b = t;
}

int partition(int arr[], int left, int right){
    int pivot = arr[right];
    int future_pivot_index = left;
    for(int i = left; i < right; i++){
        if(arr[i] < pivot){
            my_swap(arr[i], arr[future_pivot_index]);
            future_pivot_index++;
        }
    }
    my_swap(arr[future_pivot_index], arr[right]);
    return future_pivot_index;
}

void quickSort(int arr[], int left, int right){
    if(left < right){
        int pivot_index = partition(arr, left, right);
        quickSort(arr, left, pivot_index - 1);
        quickSort(arr, pivot_index + 1, right);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    int min_diff = abs(arr[0] - arr[1]);
    for(int i = 1; i < n - 1; i++){
        if(abs(arr[i] - arr[i + 1]) < min_diff){
            min_diff = abs(arr[i] - arr[i + 1]);
        }
    }

    for(int i = 0; i < n - 1; i++){
        if(abs(arr[i] - arr[i + 1]) == min_diff){
            cout << arr[i] << " " << arr[i + 1] << " ";
        }
    }
    return 0;
}