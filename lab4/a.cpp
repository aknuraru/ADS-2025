#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;

    Node() : value(0), left(nullptr), right(nullptr) {};
    Node(int x) : value(x), left(nullptr), right(nullptr) {};
};

Node* addNewNode(Node* root, int x){
    Node* new_node = new Node(x);
    if(root == NULL){
        root = new_node;
        return root;
    }
    if(x < root->value)
        root->left = addNewNode(root->left, x);
    else
        root->right = addNewNode(root->right, x);
    return root;
    /*
    Node* current = root;
    Node* prev = nullptr;
    while(current){
        prev = current;
        if(x < current->value)
            current = current->left;
        else
            current = current->right;
    }
    if(x < prev->value)
        prev->left = new_node;
    else
        prev->right = new_node;
    */
}

void isItExist(Node* root, string str){
    Node* curr = root;
    for(char ch : str){
        if(curr == NULL) break;
        if(ch == 'L')
            curr = curr->left;
        else
            curr = curr->right;
    }
    if(curr != NULL)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(){
    Node* root = NULL;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = addNewNode(root, x);
    }
    for(int i = 0; i < m; i++){
        string str;
        cin >> str; // LLR
        isItExist(root, str);
    }

    return 0;
}