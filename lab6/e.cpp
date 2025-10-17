#include <iostream>

using namespace std;

void my_swap(int** matrix, int& row1, int& row2, int column){
        int temp = matrix[row1][column];
        matrix[row1][column] = matrix[row2][column];
        matrix[row2][column] = temp;
}

int partition(int** matrix, int left, int right, int column){
    int pivot = matrix[right][column];
    int orange = left; // orange = pivot_index
    for(int green = left; green < right; green++){
        if(matrix[green][column] > pivot){ // DECREASING ORDER
            my_swap(matrix, green, orange, column);
            orange++;
        }
    }
    my_swap(matrix, orange, right, column);
    return orange;
}

void quickSort(int** matrix, int left, int right, int column){
    if(left < right){
        int pivot_index = partition(matrix, left, right, column);
        quickSort(matrix, left, pivot_index - 1, column);
        quickSort(matrix, pivot_index + 1, right, column);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int** matrix = new int *[n];

    for(int i = 0; i < n; i++){
        matrix[i] = new int[m];
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    for(int j = 0; j < m; j++){
        quickSort(matrix, 0, n - 1, j);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}