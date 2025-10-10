#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node() : value(0), left(nullptr), right(nullptr){};
    Node(int x) : value(x), left(nullptr), right(nullptr){};
};

Node* add_new_node(Node* root, int x){
    Node* new_node = new Node(x);
    if(root == nullptr){
        root = new_node;
        return root;
    }
    if(x < root->value)
        root->left = add_new_node(root->left, x);
    else
        root->right = add_new_node(root->right, x);
    return root;
}

int get_max(int n1, int n2){
    if(n1 > n2)
        return n1;
    return n2;
}

int getAmountOfLevels(Node* root){
    if(root == nullptr) return 0;
    return 1 + get_max(getAmountOfLevels(root->left), getAmountOfLevels(root->right));
}

void get_level_sum(Node* root, int level, int arr[]){
    if(root == nullptr) return;
    arr[level] += root->value;
    get_level_sum(root->left, level + 1, arr);
    get_level_sum(root->right, level + 1, arr);
}

int main(){
    int n;
    Node* root = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = add_new_node(root, x);
    }
    int levels = getAmountOfLevels(root);
    cout << levels << endl;
    int* arr = new int[levels](); // sum = 0 [0, 0, 0]
    get_level_sum(root, 0, arr);
    for(int i = 0; i < levels; i++)
        cout << arr[i] << " ";
    return 0;
}