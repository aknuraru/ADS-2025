#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;

    Node() : value(0), left(nullptr), right(nullptr){};
    Node(int x) : value(x), left(nullptr), right(nullptr){};
};

Node* addNode(Node* root, int x){
    Node* node = new Node(x);
    if(root == nullptr){
        root = node;
        return root;
    }
    /*
    if(x < root->value)
        root->left = addNode(root->left, x);
    else
        root->right = addNode(root->right, x);
    */

    Node* current = root;
    Node* prev = nullptr;
    while (current){
        prev = current;
        if(x < current->value)
            current = current->left;
        else
            current = current->right;
    }
    if(x < prev->value)
        prev->left = node;
    else
        prev->right = node;
    return root;
}

Node* getNode(Node* root, int x){
    Node* current = root;
    while (current){
        if(x < current->value)
            current = current->left;
        else if(x > current->value)
            current = current->right;
        else
            return current;
    }
    return nullptr;
}

int getChildren(Node* node){
    if(node == nullptr)
        return 0;
    return 1 + getChildren(node->left) + getChildren(node->right);
}

void solve(Node* root, int x){
    Node* node = getNode(root, x);
    cout << getChildren(node);
}

int main(){
    int n, target;
    Node* root = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = addNode(root, x);
    }
    cin >> target;
    solve(root, target);
    
    return 0;
}