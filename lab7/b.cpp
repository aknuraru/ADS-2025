#include <iostream>

using namespace std;

int* merge(int arr1[], int n, int arr2[], int m){
    int i = 0, j = 0, temp_size = n + m, k = 0;
    int* temp = new int[temp_size];
    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            temp[k] = arr1[i];
            k++;
            i++;
        }else{
            temp[k] = arr2[j];
            k++;
            j++;
        }
    }

    while(i < n){
        temp[k] = arr1[i];
        k++;
        i++;
    }

    while(j < m){
        temp[k] = arr2[j];
        k++;
        j++;
    }

    return temp;
}

void print(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    int arr1[n];
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    int arr2[m];
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    int* result = merge(arr1, n, arr2, m);

    print(result, n + m);

    delete[] result;
    return 0;
}