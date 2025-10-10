#include <iostream>

using namespace std;

struct Node{
    int key; // int value
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr){};
};

Node* add(Node* root, int x){
    if(root == nullptr) 
        return new Node(x);
    if(x < root->key)
        root->left = add(root->left, x);
    else if(x > root->key)
        root->right = add(root->right, x);
    return root;
}

void getNode(Node* root, int& sum){
    if(root == nullptr) return;
    getNode(root->right, sum);
    sum += root->key;
    root->key = sum;
    getNode(root->left, sum);
}

void print_tree(Node* root){
    if(root == nullptr) return;
    print_tree(root->right);
    cout << root->key << " ";
    print_tree(root->left);
}

int main(){
    int n, sum = 0;
    Node* root = nullptr;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = add(root, x);
    }
    getNode(root, sum);
    print_tree(root);

    return 0;
}