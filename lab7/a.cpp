#include <iostream>

using namespace std;

void merge(string arr[], int left, int mid, int right){
    string temp[1000];
    int i = left;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= right){
        if(arr[i].size() <= arr[j].size()){
            temp[k] = arr[i];
            k++;
            i++;
        }else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while(i <= mid){
        temp[k] = arr[i];
        k++;
        i++;
    }

    while(j <= mid){
        temp[k] = arr[j];
        k++;
        j++;
    }

    for(int p = 0; p < k; p++){
        arr[left + p] = temp[p];
    }
}

void mergeSort(string arr[], int left, int right){
    if(left >= right){
        return;
    }

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main(){
    int k;
    cin >> k;
    cin.ignore();
    while (k--){
        string line;
        getline(cin, line);

        string words[1000];
        int index = 0;
        string word = "";
        for(char ch : line){
            if(ch == ' '){
                words[index] = word;
                index++;
                word = "";
            }else{
                word += ch;
            }
        }
        if(word != ""){
            words[index] = word;
            index++;
        }

        mergeSort(words, 0, index - 1);
        for(int i = 0; i < index; i++){
            cout << words[i] << " ";
        }
        cout << endl;
    }
    

    return 0;
}