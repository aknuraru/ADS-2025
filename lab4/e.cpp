#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;

    Node() : value(0), left(nullptr), right(nullptr){};
    Node(int x) : value(x), left(nullptr), right(nullptr){};
};

void add_node(Node* root, int x, int y, int z){
    Node* node = new Node(y);
    if(root == nullptr)
        return;
    if(root->value == x){
        if(z == 1)
            root->right = node;
        else if(z == 0)
            root->left = node;
        return;
    }

    add_node(root->left, x, y, z);
    add_node(root->right, x, y, z);
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

void count_vertices_on_one_level(Node* root, int i, int arr[]){
    if(root == nullptr)
        return;
    arr[i]++;
    count_vertices_on_one_level(root->left, i + 1, arr);
    count_vertices_on_one_level(root->right, i + 1, arr);
}

int main(){
    Node* root = new Node(1);
    int n, levels;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        add_node(root, x, y, z);
    }
    levels = getAmountOfLevels(root);
    int* arr = new int[levels](); // [1, 2, 3, 6]
    count_vertices_on_one_level(root, 0, arr);
    int maxLevel = arr[0];
    for(int i = 1; i < levels; i++)
        if(maxLevel < arr[i])
            maxLevel = arr[i];
    
    cout << maxLevel;
    return 0;
}