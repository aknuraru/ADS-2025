#include <iostream>

using namespace std;

bool compareDates(string date1, string date2){
    int day1 = stoi(date1.substr(0, 2));
    int month1 = stoi(date1.substr(3, 2));
    int year1 = stoi(date1.substr(6, 4));

    int day2 = stoi(date2.substr(0, 2));
    int month2 = stoi(date2.substr(3, 2));
    int year2 = stoi(date2.substr(6, 4));

    if(year1 != year2){
        return year1 < year2;
    }
    if(month1 != month2){
        return month1 < month2;
    }
    if(day1 != day2){
        return day1 < day2;
    }
}

void my_swap(string& a, string& b){
        string t = a;
        a = b;
        b = t;
}

int partition(string arr[], int left, int right){
    string pivot = arr[right];
    int future_pivot_index = left;
    for(int i = left; i < right; i++){
        if(compareDates(arr[i], pivot)){
            my_swap(arr[i], arr[future_pivot_index]);
            future_pivot_index++;
        }
    }
    my_swap(arr[future_pivot_index], arr[right]);
    return future_pivot_index;
}

void quickSort(string arr[], int left, int right){
    if(left < right){
        int pivot_index = partition(arr, left, right);
        quickSort(arr, left, pivot_index - 1);
        quickSort(arr, pivot_index + 1, right);
    }
}

int main(){
    int n;
    cin >> n;
    string arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}