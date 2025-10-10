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

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int x) : value(x), left(nullptr), right(nullptr){};
};

Node* add(int arr[], int l, int r){
    if(l > r) return nullptr;
    int mid = l + (r - l) / 2;
    Node* root = new Node(arr[mid]);
    root->left = add(arr, l, mid - 1);
    root->right = add(arr, mid + 1, r);
    return root;
}

void print_tree(Node* root){
    if(root == nullptr) return;
    cout << root->value << " ";
    print_tree(root->left);
    print_tree(root->right);
}

int get_power(int a, int b){
    int result = 1;
    for(int i = 0; i < b; i++)
        result *= a;
    return result;
}

int main(){
    int n, k;
    cin >> n;
    k = get_power(2, n) - 1;
    int* arr = new int[k];
    for(int i = 0; i <  k; i++)
        cin >> arr[i];
    quickSort(arr, 0, k - 1);
    Node* root = add(arr, 0, k - 1);
    print_tree(root);
    return 0;
}