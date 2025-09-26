#include <iostream>

using namespace std;

int partition(int* arr, int low, int high){ // returns index of pivot
    int pivot = arr[high];
    int orange = low - 1;

    for (int green = low; green < high; green++){
        if(arr[green] <= pivot){
            orange++;
            swap(arr[orange], arr[green]);
        }
    }
    int index_of_pivot = orange + 1;
    swap(arr[index_of_pivot], arr[high]);
    return index_of_pivot;
}

void quickSort(int* arr, int low, int high){ // O(n * log(n))
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1); // left arr 
        quickSort(arr, pivot + 1, high); // right arr 
    }
}

int findElementsInRange(int* arr, int n, int LTarget, int RTarget){
    int left = 0, right = n - 1, LIndex = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] >= LTarget){
            LIndex = mid;
            right = mid - 1;
        }else 
            left = mid + 1;
    }
    left = 0; 
    right = n - 1; 
    int RIndex = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] <= RTarget){
            RIndex = mid;
            left = mid + 1;
        }else 
            right = mid - 1;

            
    }
    return RIndex - LIndex + 1;
}

int main(){

    int n, q;
    cin >> n >> q;
    int* arr = new int[n];
    for(int i = 0; i  < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);
    while(q--){
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int L = min(l1, l2);
        int R = max(r1, r2);

        if(!(r1 < l2 || r2 < l1))
            cout << findElementsInRange(arr, n, L, R) << endl;
        else {
            cout << findElementsInRange(arr, n, L, R) - findElementsInRange(arr, n, min(r1, r2) + 1, max(l1, l2) - 1) << endl;
        }
    }

    return 0;
}