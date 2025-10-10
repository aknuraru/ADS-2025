#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node() : value(0), left(nullptr), right(nullptr){};
    Node(int x) : value(x), left(nullptr), right(nullptr){};
};

Node* add_node(Node* root, int x){
    if(root == nullptr)
        return new Node(x);
    if(x < root->value)
        root->left = add_node(root->left, x);
    else if(x > root->value)
        root->right = add_node(root->right, x);
    return root;
}

struct Data{
    int level;
    int depth;

    Data() : level(0), depth(0){};
    Data(int lev, int dep) : level(lev), depth(dep){};
};

int get_max(int n1, int n2){
    if(n1 > n2)
        return n1;
    return n2;
}

int get_max(int n1, int n2, int n3){
    if(n1 > n2 && n1 > n3)
        return n1;
    else if(n3 > n2 && n1 < n3)
        return n3;
    return n2;
}

Data* calculateNode(Node* root){
    if(root == nullptr)
        return new Data();
    Data* left = calculateNode(root->left);
    Data* right = calculateNode(root->right);
    int level = 1 + get_max(left->level, right->level);
    int depth = get_max(left->depth, right->depth, left->level + right->level);
    return new Data(level, depth);
}

int main(){
    int n;
    Node* root = nullptr;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = add_node(root, x);
    }
    cout << calculateNode(root)->depth + 1;
    return 0;
}