#include <iostream>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int matrix[MAX_N][MAX_M + 1];
int temp[MAX_N][MAX_M + 1];

bool compare_sum_of_rows(int row1[], int row2[], int m){
    if(row1[m] != row2[m]){
        return row1[m] > row2[m]; // desc
    }

    for(int i = 0; i < m; i++){
        if(row1[i] != row2[i]){
            return row1[i] < row2[i];
        }
    }

    return false;
}

void merge(int matrix[][MAX_M + 1], int left, int mid, int right, int n, int m){
    int i = left;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= right){
        if(compare_sum_of_rows(matrix[i], matrix[j], m)){
            for(int col = 0; col <= m; col++){
                temp[k][col] = matrix[i][col];
            }
            i++;
            k++;
        }else{
            for(int col = 0; col <= m; col++){
                temp[k][col] = matrix[j][col];
            }
            j++;
            k++;
        }
    }

    while(i <= mid){
        for(int col = 0; col <= m; col++){
            temp[k][col] = matrix[i][col];
        }
        i++;
        k++;
    }

    while(j <= right){
        for(int col = 0; col <= m; col++){
            temp[k][col] = matrix[j][col];
        }
        j++;
        k++;
    }

    for(int p = 0; p < k; p++){
        for(int col = 0; col <= m; col++){
            matrix[left + p][col] = temp[p][col];
        }
    }
}

void mergeSort(int matrix[][MAX_M + 1], int left, int right, int n, int m){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(matrix, left, mid, n, m);
    mergeSort(matrix, mid + 1, right, n, m);
    merge(matrix, left, mid, right, n, m);
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
            sum += matrix[i][j];
        }
        matrix[i][m] = sum;
    }

    mergeSort(matrix, 0, n - 1, n, m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}