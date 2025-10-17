#include <iostream>

using namespace std;

void my_swap(int& a, int& b){
        int t = a;
        a = b;
        b = t;
}

int partition(int arr[], int left, int right){
    int pivot = arr[right];
    int orange = left; // orange = pivot_index
    for(int green = left; green < right; green++){
        if(arr[green] < pivot){
            my_swap(arr[green], arr[orange]);
            orange++;
        }
    }
    my_swap(arr[orange], arr[right]);
    return orange;
}

void quickSort(int arr[], int left, int right){
    if(left < right){
        int pivot_index = partition(arr, left, right);
        quickSort(arr, left, pivot_index - 1);
        quickSort(arr, pivot_index + 1, right);
    }
}


int main(){
    int n, m;
    cin >> n >> m;

    int arr[n], barr[m];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++){
        cin >> barr[i];
    }

    quickSort(arr, 0, n - 1);
    quickSort(barr, 0, m - 1);

    int i = 0, j = 0;
    while(i < n && j < m){
        if(arr[i] == barr[j]){
            cout << arr[i] << " ";
            i++;
            j++;
        }else if(arr[i] < barr[j]){
            i++;
        }else{
            j++;
        }
    }

    return 0;
}