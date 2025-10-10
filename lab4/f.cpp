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
    if(root == nullptr){
        return new Node(x);
    }

    if(x < root->value)
        root->left = add_node(root->left, x);
    else
        root->right = add_node(root->right, x);
    return root;
}

void addNode(Node*& root, int x){
    if(root == nullptr){
        root = new Node(x);
        return;
    }
    if(x < root->value)
        addNode(root->left, x);
    else
        addNode(root->right, x);
}
/*int counter = 0;
void amount_of_triangles(Node* root){
    if(root == nullptr) return;
    if(root->left != nullptr && root->right != nullptr)
        counter++;
    
    amount_of_triangles(root->left);
    amount_of_triangles(root->right);
}
*/

int getTriangles(Node* root){
    if(root == nullptr)
        return 0;
    int counter = 0;
    if(root->left != nullptr && root->right != nullptr)
        counter++;
    
    return counter + getTriangles(root->left) + getTriangles(root->right);
}


int main(){
    int n;
    Node* root = nullptr;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        addNode(root, x);
    }
    cout << getTriangles(root);
    return 0;
}