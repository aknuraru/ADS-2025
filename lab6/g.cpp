#include <iostream>

using namespace std;

struct User{
    string original;
    string current;
};

int partition(User arr[], int left, int right){
    string pivot = arr[right].original;
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(arr[j].original <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(User arr[], int left, int right){
    if(left < right){
        int piv_index = partition(arr, left, right);
        quickSort(arr, left, piv_index - 1);
        quickSort(arr, piv_index + 1, right);
    }
}

int main(){
    int n;
    cin >> n;
    User users[1000];
    int count = 0; // қазіргі уникальный адамдар саны

    for(int i = 0; i < n; i++){
        string oldNick, newNick;
        cin >> oldNick >> newNick;

        bool bar_ma_nick = false;
        for(int j = 0; j < count;  j++){
            if(users[j].current == oldNick){
                users[j].current = newNick;
                bar_ma_nick = true;
                break;
            }
        }

        if(!bar_ma_nick){
            users[count].original = oldNick;
            users[count].current = newNick;
            count++;
        }
    }

    quickSort(users, 0, count - 1);
    cout << count << endl;
    for(int i = 0; i < count; i++){
        cout << users[i].original << " " << users[i].current << endl;
    }

    return 0;
}