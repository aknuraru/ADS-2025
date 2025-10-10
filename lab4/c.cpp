#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node() : value(0), left(nullptr), right(nullptr){};
    Node(int x) : value(x), left(nullptr), right(nullptr){};
};

Node* addNewNode(Node* root, int x){
    Node* node = new Node(x);
    if(root == nullptr){
        root = node;
        return root;
    }
    if(x < root->value)
        root->left = addNewNode(root->left, x);
    else
        root->right = addNewNode(root->right, x);
    return root;
}

Node* getNode(Node* root, int x){
    if(root->value == x){
        return root;
    }
    if(x < root->value)
        return getNode(root->left, x);
    else
        return getNode(root->right, x);
}

void getChildren(Node* current){
    if(current == nullptr)
        return;
    cout << current->value << " ";
    getChildren(current->left);
    getChildren(current->right);
}

void solve(Node* root, int x){
    Node* target = getNode(root, x);
    getChildren(target);
}

int main(){
    int n, k;
    Node* root = nullptr;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = addNewNode(root, x);
    }
    cin >> k;
    solve(root, k);
    return 0;
}